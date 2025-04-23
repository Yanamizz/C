#include <stdio.h>
#include <string.h>

int main()
{
    int n ,sum=0;
    scanf ("%d",&n);
    char m[11] ;
    sprintf(m , "%d" , n);
    for (int i = 0 ; i < strlen(m) ; i++)
    {
        if (m[i] != m[strlen(m)-1-i])
        {
            printf("no");
            return 0;
        }
    }
    while(n!=0)
    {
        sum+=n%10;
        n/=10;
    }
    printf("%d",sum);
    return 0;
}