#include <stdio.h>

int main()
{
    int n , max=0;
    scanf ("%d", &n);
    int N[n];

    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &N[i]);
    }
    for (int i = 0; i < n-1; i++)
    {
        int temp = 0;
        if (N[i] > N[i+1])
        {
            temp = N[i] - N[i+1];
        }
        else
        {
            temp = N[i+1] - N[i];
        }
        if (temp > max)
        {
            max = temp;
        }
    }
    printf ("%d", max);
    return 0;


}