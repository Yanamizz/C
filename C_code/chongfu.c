#include <stdio.h>

int repeat(long long n, long long x);

int main()
{
    long long n=0 , x=0 , sum=0 , i=0;
    scanf("%lld %lld", &n, &x);

    for (i = 1; i <= n; i++)
    {
        sum += repeat(i, x);
    }

    printf("%lld", sum);

    return 0;
}

int repeat(long long n, long long x)
{
    long long sum = 0;
    while (n != 0)
    {
        if (n % 10 == x)
        {
            sum += 1;
        }
        n /= 10;
    }   

    return sum;
}