#include <stdio.h>

void judge(int n , int m ,int N[n][m] , int J[n][m]);

int main()
{
    int n , m;
    scanf("%d %d" , &n , &m);
    int Num[n][m];
    int Judge[n][m];
    for (int i =0 ; i < n ; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf ("%d" , &Num[i][j]);
        }
    }
    judge(n , m , Num , Judge);
    for (int i =0 ; i < n ; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (Judge[i][j] == 1)
            {
                Num[i][j] = 0;
            }
            printf ("%d " , Num[i][j]);          
        }
        printf ("\n");
    }
    return 0;
}

void judge(int n , int m ,int N[n][m] , int J[n][m])
{
    for (int i =0 ; i<n ; i++)
    {
        for (int j = 0; j < m; j++)
        {
            J[i][j] = 0;
        }
    }
    for (int i =0 ; i<n ; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i > 0 && i < n-1)
            {    
                if (N[i][j]==N[i-1][j] && N[i][j]==N[i+1][j])
                {
                    J[i][j] = J[i-1][j] = J[i+1][j] = 1;
                }
            }
            if (j > 0 && j < m-1)
            {
                if (N[i][j]==N[i][j-1] && N[i][j]==N[i][j+1])
                {
                    J[i][j] = J[i][j-1] = J[i][j+1] = 1;
                }
            }
        }          
    }

}