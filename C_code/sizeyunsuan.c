#include <stdio.h>

int main()
{
    int a=0 , b=0;
    char c ;

    scanf("%d%c%d", &a, &c, &b);

    switch (c)
    {
    case '+':
        printf("%d+%d=%d", a , b , a+b);
        break;
    case '-':
        printf("%d-%d=%d", a , b , a-b);
        break;
    case '*':
        printf("%d*%d=%d", a , b , a*b);
        break;
    case '/':
        printf("%d/%d=%d", a , b , a/b);
        break;
    default:
        printf("%d%%%d=%d", a , b , a%b);
        break;
    }
    return 0;
}