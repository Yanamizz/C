#include <stdio.h>

int main() 
{
    int a;
    scanf("%d", &a);

    int foot = a/0.3048/100;
    int inch = (a/0.3048/100-foot)*12;

    printf("%d %d" , foot , inch);

    return 0;
}