#include <stdio.h>
#include <math.h>

int main()
{
    int n ;
    scanf("%d", &n);
    int Num[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &Num[i]);
    }
    int min = abs(Num[0] - Num[1]);
    
    for (int i = 0 ; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(Num[i] - Num[j]) < min)
            {
                min = abs(Num[i] - Num[j]);
            }
        }
        if (min == 0)
        {
            break;
        }
    }

    printf("%d", min);
    return 0;
}