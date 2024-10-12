#include <stdio.h>
#include <string.h>

void judge(int date ,int num , int n);
char j[4];

int main() 
{
    int a=0 , b=0 , c=0;
    
    scanf("%d %d %d",&a,&b,&c);
    c %= 10;

    if (a >= 6 || b < 200)
    {
        strcpy(j,"no");
        printf("%d %s", c , j);
        return 0;
    }
    else 
    {
        judge(a,b,c);
        printf("%d %s", c , j);
    }

    return 0;

}

void judge(int date ,int num , int n)
{
    if (num >= 200 && num < 400)
    {
        if (n == (date+5)%10 || n == date)
        {
            strcpy(j,"yes");
            return;
        }
        else 
        {
            strcpy(j,"no");
            return;
        }
    }
    else 
    {
        if ( (n%2) == (date%2) )
        {
            strcpy(j,"yes");
            return;
        }
        else 
        {
            strcpy(j,"no");
            return;
        }
    }    
}