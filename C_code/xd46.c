#include <stdio.h>

int main()
{
    int n , sum = 0;
    scanf ("%d", &n);
    int N[n];
    for (int i = 0; i < n; i++) 
    {
        scanf ("%d", &N[i]);
    }

    for (int i = 1; i < n-1; i++)
    {
        if (N[i] > N[i-1] && N[i] > N[i+1] || N[i] < N[i-1] && N[i] < N[i+1])
        {
            sum++;
        }
    }
    printf ("%d", sum);
    return 0;
}