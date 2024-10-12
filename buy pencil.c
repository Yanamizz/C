#include <stdio.h>

int calculate(int n, int j, int k);

int main()
{
    int W[3][3];
    int n , min;

    scanf("%d\n", &n);

    for (int i = 0; i < 3; i++)
    {
        scanf("%d %d" , &W[i][0], &W[i][1]);
    }

    min = calculate(n,W[0][0],W[0][1]);
    
    for (int i = 1; i < 3; i++)
    {
        if (min > calculate(n,W[i][0],W[i][1]))
        {
            min = calculate(n,W[i][0],W[i][1]);
        }
    }

    printf("%d", min);
    return 0;
}

int calculate(int n, int j, int k)
{
    int num;
    if (n % j == 0)
    {
        num = n / j;
    }
    else
    {
        num = n / j + 1;
    }
    
    return num * k;
    
}