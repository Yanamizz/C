#include <stdio.h>

int main() 
{
    int n , a , b , x , y , ax , ay , num= -1 ;
    scanf("%d" , &n);
    int area[n][4] ;
     
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d %d %d %d \n" , &a , &b , &x , &y);
        area[i][0] = a ;
        area[i][1] = b ;
        area[i][2] = a + x ;
        area[i][3] = b + y ;
    }
    
    scanf("%d %d" , &ax , &ay);

    for (int i = 0 ; i < n ; i++)
    {
        if ((ax >= area[i][0] && ax <= area[i][2]) && (ay >= area[i][1] && ay <= area[i][3]))
        {
            num = i + 1 ;
        }
    }

    printf("%d" , num);

    return 0;
}
