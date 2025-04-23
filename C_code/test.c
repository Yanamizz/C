#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// BMP file header structure
#pragma pack(push, 1)
typedef struct {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BITMAPFILEHEADER;

// BMP info header structure
typedef struct {
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

// Function to calculate neighborhood mean
unsigned char calculateNeighborhoodMean(unsigned char *image, int width, int height, int x, int y, int r) {
    int sum = 0;
    int count = 0;
    
    for (int i = x - r; i <= x + r; i++) {
        for (int j = y - r; j <= y + r; j++) {
            // Check if the neighbor is within image boundaries
            if (i >= 0 && i < height && j >= 0 && j < width) {
                sum += image[i * width + j];
                count++;
            }
        }
    }
    
    return (count > 0) ? (sum / count) : 0;
}

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc != 5) {
        printf("Usage: %s <input_bmp> <output_bmp> -r=<radius> -t=<threshold>\n", argv[0]);
        return 1;
    }
    
    char *inputPath = argv[1];
    char *outputPath = argv[2];
    int r = 0, t = 0;
    
    // Parse radius and threshold parameters
    if (sscanf(argv[3], "-r=%d", &r) != 1 || sscanf(argv[4], "-t=%d", &t) != 1) {
        printf("Invalid parameters. Format: -r=<radius> -t=<threshold>\n");
        return 1;
    }
    
    // Open input file
    FILE *inputFile = fopen(inputPath, "rb");
    if (!inputFile) {
        printf("Error: Cannot open input file %s\n", inputPath);
        return 1;
    }
    
    // Read BMP headers
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    
    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, inputFile);
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, inputFile);
    
    // Check if it's a valid BMP file
    if (fileHeader.bfType != 0x4D42) { // "BM" in hex
        printf("Error: Not a valid BMP file\n");
        fclose(inputFile);
        return 1;
    }
    
    // Get image dimensions
    int width = infoHeader.biWidth;
    int height = infoHeader.biHeight;
    
    // Calculate row padding (BMP rows are padded to multiple of 4 bytes)
    int padding = (4 - (width % 4)) % 4;
    
    // Allocate memory for image data
    unsigned char *inputImage = (unsigned char *)malloc(height * width);
    unsigned char *outputImage = (unsigned char *)malloc(height * width);
    
    if (!inputImage || !outputImage) {
        printf("Error: Memory allocation failed\n");
        fclose(inputFile);
        free(inputImage);
        free(outputImage);
        return 1;
    }
    
    // Read image data
    fseek(inputFile, fileHeader.bfOffBits, SEEK_SET);
    
    // Read pixel data row by row (accounting for padding)
    for (int i = 0; i < height; i++) {
        fread(&inputImage[(height - 1 - i) * width], width, 1, inputFile);
        fseek(inputFile, padding, SEEK_CUR); // Skip padding bytes
    }
    
    fclose(inputFile);
    
    // Process the image - apply neighborhood mean binarization
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char mean = calculateNeighborhoodMean(inputImage, width, height, i, j, r);
            outputImage[i * width + j] = (mean <= t) ? 0 : 255; // 0 for black, 255 for white
        }
    }
    
    // Create output file
    FILE *outputFile = fopen(outputPath, "wb");
    if (!outputFile) {
        printf("Error: Cannot create output file %s\n", outputPath);
        free(inputImage);
        free(outputImage);
        return 1;
    }
    
    // Modify the info header for binary image
    infoHeader.biBitCount = 8;  // 8 bits per pixel for grayscale
    
    // Write headers
    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, outputFile);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, outputFile);
    
    // Write color table for 8-bit image (grayscale palette)
    unsigned char colorTable[1024]; // 256 entries * 4 bytes (BGRA)
    for (int i = 0; i < 256; i++) {
        colorTable[i * 4] = i;     // Blue
        colorTable[i * 4 + 1] = i; // Green
        colorTable[i * 4 + 2] = i; // Red
        colorTable[i * 4 + 3] = 0; // Alpha (reserved)
    }
    fwrite(colorTable, 1024, 1, outputFile);
    
    // Write image data with padding
    for (int i = 0; i < height; i++) {
        fwrite(&outputImage[(height - 1 - i) * width], width, 1, outputFile);
        
        // Add padding
        unsigned char padByte = 0;
        for (int p = 0; p < padding; p++) {
            fwrite(&padByte, 1, 1, outputFile);
        }
    }
    
    fclose(outputFile);
    free(inputImage);
    free(outputImage);
    
    printf("Binarization completed successfully.\n");
    return 0;
}
