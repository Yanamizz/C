#include <stdio.h>

int main()
{
    int num;
    int rev;
    
    scanf("%d", &num);
    rev = num/100 + num/10%10*10 + num%10*100;

    printf("%d", rev);

    return 0;
}