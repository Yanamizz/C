#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf ("%d", &n);
    float sqn= sqrt(n); 

    if (sqn == (int)sqn)
    {
        printf ("%d" , (int)sqn);
    }
    else
    {
        printf ("no");
    }
    return 0;
}