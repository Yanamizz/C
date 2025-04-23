#include <stdio.h>
void swap(int *a,int *b);
int main()
{
    int n , x=0 ,y=0;
    scanf("%d" , &n);
    int Num[n] ;
    for (int i =0 ;i<n ;i++)
    {
        int num;
        scanf("%d" , &num);
        if (num%2 == 0)
        {
            Num[x]=num;
            x++;
        }
        else 
        {
            Num[n-1-y]=num;
            y++;
        }
    }
    for (int i = 0; i<x-1 ;i++)
    {     
        for (int j = x-1; j>i ;j--)
        {
            if (Num[j] > Num[j-1])
            {
                swap(&Num[j],&Num[j-1]);
            }
        }
    }
    for (int i = x; i<n-1 ;i++)
    {
        
        for (int j = n-1; j>i ;j--)
        {
            if (Num[j] > Num[j-1])
            {
                swap(&Num[j],&Num[j-1]);
            }
        }
    }
    for (int i=0; i<n; i++)
    {
        printf ("%d ",Num[i]);
    }
    return 0;
}

void swap(int *a,int *b)
{
    int temp=*a;
    *a = *b;
    *b = temp;
}