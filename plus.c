#include <stdio.h>
int main() 
{
    int n , w ;
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) 
    {
        w += i;
    }

    printf("%d", w);
    
    return 0;
}