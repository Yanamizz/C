#include <stdio.h>

void judge(int *a , int *b);

int main()
{
    int i=0 , j=0;
    int *a = &i , *b = &j;
    
    scanf("%d", &i);

    judge(a , b);

    printf ("%d/%d",i-j , j );    

    return 0;
}

void judge(int *a , int *b)
{
    int n=0 , m=0;
    
    while ((1+n)*n/2 < *a)
        n++;
        
    if (n%2 == 0)
    {
        *b =n * (n+1) / 2 - *a + 1;
    }
    else
    {
        *b = *a - n * (n- 1) / 2;
    }
    
    *a = n + 1;

}