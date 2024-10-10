#include <stdio.h>

int main() 
{
    printf("请输入身高的英尺和英寸:");

    double foot;
    double inch;

    scanf("%lf",&foot);
    scanf("%lf",&inch);
    
    printf("身高是%f米:",((foot + inch/12.0)* 0.3048));
    return 0;
}
