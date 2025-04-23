#include <stdio.h>

void rerank(int n , int num[n]);
void swap(int *a, int *b);

int main() 
{
    int n;
    scanf("%d", &n);
    int num[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    rerank(n, num);
    int dif = num[1] - num[0];
    for (int i = 1; i < n; i++)
    {
        if (num[i] - num[i - 1] != dif)
        {
            printf("no");
            return 0;
        }
    }
    printf("%d" , dif);
    return 0;
}

void rerank(int n , int num[n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n-1; j > i; j--)
        {
            if (num[j] < num[j - 1])
            {
                swap(&num[j], &num[j - 1]);
            }
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}