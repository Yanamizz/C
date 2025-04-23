#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#pragma pack(1)

typedef struct{
	unsigned short type;//位图文件的类型，必须为 BM
	unsigned long size;//位图文件的大小，以字节为单位（低位在前）
	unsigned short reserved1;//位图文件保留字，必须为 0
	unsigned short reserved2;//位图文件保留字，必须为 0
	unsigned long off_bits;//位图文件的地址偏移，即起始位置，以相对于位图（低位在前）
} bmpfileheader;

typedef struct{
	unsigned long size; //定义该结构体的大小，即为 40
	long width; //位图宽度，以像素为单位
	long height; //位图高度，以像素为单位
	unsigned short planes; //保存所用彩色位面的个数，不常使用
	unsigned short bit_count; //保存每个像素的位数，它是图像的颜色深度
	unsigned long compression; //定义所用的压缩算法
	unsigned long size_image; //位图的大小，以字节为单位。不同于文件大小，这是原始位图数据的大小
	long x_pels_permeter;  //位图水平分辨率，每米像素数
	long y_pels_permeter; //位图垂直分辨率，每米像素数
	unsigned long clr_used; //位图实际使用的颜色表中的颜色数
	unsigned long clr_improtant; //位图显示过程中重要的颜色数
} bmpinfoheader;

typedef struct {
    unsigned char rgbBlue;
    unsigned char rgbGreen;
    unsigned char rgbRed;
    unsigned char rgbReserved;
} RGBQUAD;

void save_binary_to_bmp(const char* filename, unsigned char* binary_data, int width, int height);
int main(int argc, char *argv[])
{
// 命令行参数
    char *gray_path = argv[1];
    char *mono_path = argv[2];
    int r=0,t=0;
    int opt;
    for (int i = 3; i < argc; i++) 
    {
        if (strncmp(argv[i], "-r=", 3) == 0) 
        {
            r = atoi(argv[i] + 3);
        }  
        else if (strncmp(argv[i], "-t=", 3) == 0) 
        {
            t = atoi(argv[i] + 3);  
        }   
    }
//文件读取
    FILE *gfp = NULL;
    FILE *mfp = NULL;
    gfp = fopen(gray_path,"rb");
    bmpfileheader bf;
    bmpinfoheader bi;
    fread(&bf, sizeof(bmpfileheader), 1, gfp);
    fread(&bi, sizeof(bmpinfoheader), 1, gfp);
    
//读取原图gray   
    long width = bi.width,height = bi.height;
    unsigned char* gray = (unsigned char*)malloc(width * height);
    fseek(gfp, bf.off_bits, SEEK_SET);
    int padding = (4 - (width % 4)) % 4;
    for (int y = height - 1; y >= 0; y--) {
        fread(&gray[y * width], 1, width, gfp);
        fseek(gfp, padding, SEEK_CUR); 
    }// 读取像素数据（BMP是倒序存储的）
//avegray
    unsigned char* avegray = (unsigned char*)malloc(width * height);
    for (int y = 0; y < height; y++) 
    {
        for (int x = 0; x < width; x++) 
        {
            long long sum = 0;
            int count = 0;
            for (int ny = (y-r>0)?y-r:0; ny <= ((y+r<height)?y+r:height-1); ny++) 
            {
                for (int nx = (x-r>0)?x-r:0; nx <= ((x+r<width)?x+r:width-1); nx++) 
                {
                    sum += gray[ny * width + nx];
                    count++;                 
                }
            }
            
            // 计算平均值并存储
            avegray[y * width + x] =sum / count;
        }
    }


//gray2mono
    unsigned char* mono = (unsigned char*)malloc(width * height);
    int black=0,white=0;
    for (int i = 0;i<width*height;i++)
    {
        printf("%d ",avegray[i]);
        if (avegray[i] > t)
        {
            mono[i] = 1;
            white++;
        }
        else
        {
            mono[i] = 0;
            black++;
        }
        
    }
    printf("\n%d %d %d %d",white , black , t , r);
//mono2bmp
    save_binary_to_bmp(mono_path, mono, width, height);
    
    
    free(mono);
    free(avegray);
    free(gray);
    fclose(gfp);
    fclose(mfp);
    return 0;
}

void save_binary_to_bmp(const char* filename, unsigned char* binary_data, int width, int height) 
{
    FILE* fp = fopen(filename, "wb");
    if (!fp) 
    {
    printf("无法创建文件\n");
    return;
    }

// 计算每行字节数(必须是4的倍数)
    int line_bytes = (width + 31) / 32 * 4;
    int image_size = line_bytes * height;
    int file_size = 54 + 8 + image_size; // 文件头+信息头+调色板+像素数据

// 1. 创建文件头
    bmpfileheader file_header;
    file_header.type = 0x4D42; // "BM"
    file_header.size = file_size;
    file_header.reserved1 = 0;
    file_header.reserved2 = 0;
    file_header.off_bits = 62; // 14+40+8

// 2. 创建信息头
    bmpinfoheader info_header;
    info_header.size = 40;
    info_header.width = width;
    info_header.height = height;
    info_header.planes = 1;
    info_header.bit_count = 1; // 1位二值图像
    info_header.compression = 0;
    info_header.size_image = image_size;
    info_header.x_pels_permeter = 0;
    info_header.y_pels_permeter = 0;
    info_header.clr_used = 0;
    info_header.clr_improtant = 0;

// 3. 创建调色板(2种颜色)
    RGBQUAD palette[2];
    palette[0].rgbBlue = palette[0].rgbGreen = palette[0].rgbRed = 0;    // 黑色
    palette[1].rgbBlue = palette[1].rgbGreen = palette[1].rgbRed = 255;  // 白色
    palette[0].rgbReserved = palette[1].rgbReserved = 0;

// 写入文件头和信息头
    fwrite(&file_header, sizeof(bmpfileheader), 1, fp);
    fwrite(&info_header, sizeof(bmpinfoheader), 1, fp);
    fwrite(palette, sizeof(RGBQUAD), 2, fp);

// 4. 写入像素数据
    unsigned char* line_buffer = (unsigned char*)calloc(line_bytes, 1);

// BMP是从下往上存储的
    for (int y = height - 1; y >= 0; y--) 
    {
        memset(line_buffer, 0, line_bytes);

    // 将每行8个像素打包成1个字节
        for (int x = 0; x < width; x++) 
        {
            int byte_pos = x / 8;
            int bit_pos = 7 - (x % 8);

            if (binary_data[y * width + x]) 
            {
                line_buffer[byte_pos] |= (1 << bit_pos);
            }
        }

        fwrite(line_buffer, 1, line_bytes, fp);
    }

    free(line_buffer);
    fclose(fp);
}
