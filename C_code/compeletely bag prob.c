#include <stdio.h>
  
int max(int a, int b) 
{
    if (a > b) 
    {
        return a;
    }
    else 
    {
        return b;
    }
}//:定义函数max,返回a和b中的最大值

int main() 
{
    int N ,V , i , j;
    scanf("%d %d",&N,&V );//:输入个数和总体积

    int weight[N+1], value[N+1];//:定义数组,weight[i]表示第i个物品的重量,value[i]表示第i个物品的价值
    
    int bag[N+1][V+1];//:定义二维数组,bag[i][j]表示前i个物品恰好装入一个容积为j的背包可以获得的最大价值
    for (i=0;i<=N;i++)
    {
        for (j=0;j<=V;j++)
        {
            bag[i][j]=0;
        }
    }
    
    for (i = 1; i <= N; i++) 
    {
        scanf("%d %d", &weight[i] , &value[i]);//:输入第i个物品的重量和价值
    }
    
    for (i = 1; i <= N; i++) 
    {
        for (j = 1; j <= V; j++) 
        {
            if (weight[i] > j)
            {
                bag[i][j] = bag[i -1 ][j];    
            }
            else
            {
                bag[i][j] = max(bag[i-1][j] , bag[i][j-weight[i]] + value[i]);
            }
        }

    }
    printf("%d", bag[N][V]);//:输出最大价值
    return 0;
}   

