#include <stdio.h>

int main()
{
    int now;
    int time;
    scanf("%d %d" , &now, &time);

    int after;
    int a = ((now/100*60 + now%100) + time);
    after = a/60*100 + a%60;

    printf("%d", after);

    return 0;
}
