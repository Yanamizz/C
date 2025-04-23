#include <stdio.h>

int main()
{
    int n=0 , sum=0;
    scanf ("%d", &n);
    
    int N[n] , M[7];
    
    for (int i = 0 ; i<7 ; i++)
    {
        M[i] = 0;
    }
    
    for (int i = 0 ; i<n ; i++)
    {
        scanf ("%d", &N[i]);
        sum += N[i];
        if (N[i] > 300)
        {
            M[5]++;
        }
        else if (N[i] > 200)
        {
            M[4]++;
        }
        else if (N[i] > 150)
        {
            M[3]++;
        }
        else if (N[i] > 100)
        {
            M[2]++;
        }
        else if (N[i] > 50)
        {
            M[1]++;
        }
        else
        {
            M[0]++;
        }
    }
    printf ("%.2f\n", (float)sum/n);
    for (int i = 0 ; i<6 ; i++)
    {
        printf ("%d ", M[i]);
    }
}