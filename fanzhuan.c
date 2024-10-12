#include <stdio.h>
#include <stdlib.h>
#define ll long long

int main()
{
    ll i=0 , j=0 , k=0;
    char a;
    
    scanf("%lld" , i);

    if (i == 0)
    {
        printf("0");
        return 0;
    }
    else if (i < 0) 
    {
        a = '-' ; 
    }
    i = abs(i);
     
    while (i % 10 == 0)
    {
        i /= 10;
    }

    while (i > 0)
    {
        j*=10;
        k = i % 10;
        j += k;
        i /= 10;
    }
    
    if (a == '-')
    {
        printf("%lld", -j);
    }
    else
    {
        printf("%lld", j);
    }
    
    return 0;
}