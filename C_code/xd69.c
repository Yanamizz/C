#include <stdio.h>

void count (int x, int y,int i, int num[x][y] ,int *a ,int *b );
int main()
{
    int x ,y;
    scanf("%d %d", &x, &y);
    int arr1[x][y];
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }

    int start , end , num;
    int arr2[x][2] ;
    for (int i = 0; i < x; i++)
    {
        count (x ,y , i , arr1, &start, &end );
        arr2[i][0] = start;
        arr2[i][1] = end;
    }
    
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void count (int x, int y, int i, int num[x][y] ,int *a ,int *b )
{
    int start = 0;
    int start0 = 0;
    int end = 0;
    int num0 = 0;
    int maxnum = 0;
    for (int j = 0; j < y; j++)
    {
        if (num[i][j] == 1)
        {
            if (maxnum == 0)
            {
                start0 = j;
            }
            maxnum++;
        }
        else
        {
            if (maxnum > num0)
            {
                num0 = maxnum;
                end = j - 1;
                start = start0;
            }
            maxnum = 0;
        }
    }
    if (maxnum > num0)
    {
        num0 = maxnum;
        end = y - 1;
        start = start0;
    }
    if (num0 == 0)
    {
        start = -1;
        end = -1;
    }
    *a = start;
    *b = end;
    
}