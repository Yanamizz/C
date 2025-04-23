#include <stdio.h>

int main()
{
    int num , digit = 0 , max = 0 , min = 10;
    scanf ("%d", &num);
    if (num == 0)
    {
        printf("1 0 0");
        return 0;
    }
    while (num != 0)
    {
        int temp = num % 10;
        if (temp > max)
        {
            max = temp;
        }
        if (temp < min)
        {
            min = temp;
        }
        digit++;
        num /= 10;
    }
    
    printf ("%d %d %d", digit, max, min);
    return 0;
}