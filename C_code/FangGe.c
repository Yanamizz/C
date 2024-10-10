#include <stdio.h>

int max(int a , int b )
{
    if (a > b)
        return a;
    else
        return b;
}

int main() 
{
    int N;
    scanf("%d", &N);
   
    int CUBE[11][11];
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            CUBE[i][j] = 0;
        }
    }


    int x=0 , y=0 , w=0  ;
    int i=0,j=0,k=0,l=0;
    int W[11][11][11][11];

    scanf("%d %d %d", &x , &y , &w);
    while (x!=0 || y!=0 || w!=0)
    {
        CUBE[x][y] = w;
        scanf("%d %d %d", &x , &y , &w);
    }

    W[0][0][0][0] = CUBE[0][0];

    for (int i = 1; i <= N; i++)
        {
            for (int j = 1 ;j <= N; j++)
            {
                for (int k = 1; k <= N; k++)
                {
                    for (int l = 1; l <= N; l++)
                    {
                       
                        if(i!=0 && j!=0 && k!=0 && l!=0)
                        {
                        W[i][j][k][l] = max( max (W[i-1][j][k-1][l], W[i][j-1][k-1][l]) , max( W[i-1][j][k][l-1], W[i][j-1][k][l-1])) + CUBE[i][j] + CUBE[k][l] ;
                    
                        if (i==k && j==l)
                        {
                            W[i][j][k][l] = W[i][j][k][l]-CUBE[i][j];
                        }    
                        }
                    }
                } 
            }
        }
    printf("%d", W[N][N][N][N]);

    return 0;

}