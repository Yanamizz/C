#include<stdio.h>

int save_money(int m , int n);

int main()
{
    int COST[12] , W=0 , num=0 , save=0; 
    for (int i=0;i<12;i++)
    {
        scanf("%d",&COST[i]);
    }          

    for (int i=0;i<12;i++)
    {
        W += 300;
        if (W < COST[i])
        {
            printf("-%d" , i+1);
            return 0;
        }
        
        else
        {
            num = save_money(W , COST[i]);
            W = W - num * 100 -COST[i];
            save += num * 100;
        }
    }

    W =(int) W + save*1.2;
    printf("%d",W);

    return 0;
}

int save_money(int m, int n)
{
    return (m - n) / 100;
}