#include <stdio.h>
void swap(int *a , int *b);
void rank(int m , int SUM[m]);
int main() 
{
    int m;
    scanf("%d", &m);
    int NUM[m][m];
    int SUM[2*m + 2];
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            scanf("%d", &NUM[i][j]);
        }
    }
    for (int i = 0; i < m ; i++) 
    {
        int sum =0;
        for (int j = 0; j < m; j++) 
        {
            sum += NUM[i][j];
        }
        SUM[i] = sum;
    }
    for (int j = 0; j < m ; j++) 
    {
        int sum =0;
        for (int i = 0; i < m; i++) 
        {
            sum += NUM[i][j];
        }
        SUM[m+j] = sum;
    }
    int sum1 = 0 , sum2 = 0;
    for (int i = 0; i < m ; i++) 
    {
        sum1 += NUM[i][i];
        sum2 += NUM[i][m-i-1];
        SUM[2*m] = sum1;
        SUM[2*m + 1] = sum2; 
    }
    rank(m , SUM);
    for (int i=0;i<2*m + 2;i++)
    {
        printf("%d ",SUM[i]);
    }
    return 0;
}

void rank(int m , int SUM[m])
{
    for (int i = 0; i<2*m+2 ;i++)
    {
        
        for (int j = 2*m+1; j>i ;j--)
        {
            if (SUM[j] > SUM[j-1])
            {
                swap(&SUM[j],&SUM[j-1]);
            }
        }
    }
}

void swap(int *a ,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
