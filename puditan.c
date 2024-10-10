#include <stdio.h>
#define ARR_LEN 10000
#include <stdlib.h>

int main() 
{
    int n , ax , ay ;
    int (*W)[4] = malloc(ARR_LEN * sizeof(*W));
    int (*M)[ARR_LEN] = malloc(ARR_LEN * sizeof(*M));
   
   for (int i = 0; i < ARR_LEN; i++) 
    {
        for (int j = 0; j < ARR_LEN; j++) 
        {
            M[i][j] = -1;
        }
    }
    //:M为地面,W为地毯储存
    
    
    scanf ("%d" , &n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d %d %d %d\n", &W[i][0] , &W[i][1] , &W[i][2] , &W[i][3] );
    }
    
    for (int num = 0; num < n; num++) 
    {
        for (long long i = 0; i < W[num][2]; i++)
        {
            for (long long j = 0; j < W[num][3]; j++)
            {
                M[W[num][0]+i][W[num][1]+j] = num+1;
            }
        }
    }
    scanf("%d %d" , &ax , &ay);
    printf("%d" , M[ax][ay]);
    
    free(W);
    free(M);
    
    return 0;

}               