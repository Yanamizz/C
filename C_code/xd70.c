#include <stdio.h>
void zigzag(int n, int arr[n][n]);
int main() 
{
    int n;
    scanf("%d", &n);
    int arr[n][n];
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int x=0 , y=0;
    zigzag(n, arr);
    return 0;
}

void zigzag(int n, int arr[n][n]) 
{
    int a = 0 , b = 0;
    printf ("%d ", arr[a][b]);
    while(a < n-1 || b < n-1)
    {
        if (a == 0  && b < n-1)
        {
            b++;
            printf ("%d ", arr[a][b]);
            while (b > 0 && a < n-1) 
            {
                a++;
                b--;
                printf ("%d ", arr[a][b]);
            }
        }
        else if (b == 0 && a < n-1)
        {
            a++;
            printf ("%d ", arr[a][b]);
            while (a > 0 && b < n-1) 
            {
                a--;
                b++;
                printf ("%d ", arr[a][b]);
            }
        }
        else if (b == n-1)
        {
            a++;
            printf ("%d ", arr[a][b]);
            while (a < n-1 && b > 0) 
            {
                a++;
                b--;
                printf ("%d ", arr[a][b]);
            }
        }
        else if (a == n-1)
        {
            b++;
            printf ("%d ", arr[a][b]);
            while (b < n-1 && a > 0) 
            {
                a--;
                b++;
                printf ("%d ", arr[a][b]);
            }
        }
    }
    
}