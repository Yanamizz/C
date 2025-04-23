#include <stdio.h>

int judge_x(int x , int y , int num[x][y] , int i , int j);
int judge_y(int x , int y , int num[x][y] , int i , int j);
int main() 
{
    int x , y ,sum=0;
    scanf("%d %d" , &x , &y);
    int num[x][y];
    for (int i=0 ; i < x ; i++)
    {
        for (int j=0 ; j < y ; j++)
        {
            scanf("%d" , &num[i][j]);
        }
    }
    for (int i=0 ; i < x ; i++)
    {
        for (int j=0 ; j < y ; j++)
        {
            if(judge_x(x , y , num , i , j) && judge_y(x , y , num , i , j))
            {
                printf("%d %d %d\n" , i , j , num[i][j]);
                sum++;
            }
        }
    }
    if (sum == 0)
    {
        printf("no\n");
    }
    return 0;
}

int judge_x(int x , int y , int num[x][y] , int i , int j)
{
    int a = 0;
    while (a<y)
    {
        if (a != j)
        {
            if (num[i][j] > num[i][a])
            {
                return 0;
            }
        }
        a++;
    }
    return 1;
}

int judge_y(int x , int y , int num[x][y] ,int i ,int j)
{
    int a = 0;
    while (a<x)
    {
        if (a != i)
        {
            if (num[i][j] < num[a][j])
            {
                return 0;
            }
        }
        a++;
    }
    return 1;
}