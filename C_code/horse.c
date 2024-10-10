#include <stdio.h>

int inspect(int nx , int ny ,int hx , int hy) //:判断卒的下一个位置是否会被马吃掉
{
    int horse[20][2] ; //:马的位置
    horse[0][0] = hx-1; horse[0][1] = hy-2;
    horse[1][0] = hx-2; horse[1][1] = hy-1;
    horse[2][0] = hx-1; horse[2][1] = hy+2;
    horse[3][0] = hx+2; horse[3][1] = hy-1;
    horse[4][0] = hx+1; horse[4][1] = hy+2;
    horse[5][0] = hx+2; horse[5][1] = hy+1;
    horse[6][0] = hx+1; horse[6][1] = hy-2;
    horse[7][0] = hx-2; horse[7][1] = hy+1;
    horse[8][0] = hx+1; horse[8][1] = hy+1; //:马的八个位置
    for (int i = 0 ; i <= 8 ; i++) 
    {
        if (nx == horse[i][0] && ny == horse[i][1]) //:判断下一个位置是否是马的位置
        {
            return 1 ; //:如果是马脚的位置,返回1
        }    
    }
	
	return 0 ;
}




int main() 
{
    int x , y , hx , hy ;
    scanf("%d %d %d %d" , &x , &y , &hx , &hy );
    long long F[x+1][y+1] ;//:建立二维数组模拟棋盘,内容为从{0,0}到{x,y}的步数
    
    for (int i = 0 ; i <= x ; i++) //:棋盘初始化
    {   
        for(int j = 0 ; j <= y ; j++) 
        {
            F[i][j] = 0 ;
        }
    }
 
	for (int nx = 0 ; nx <= x ; nx++) 
    {
        for (int ny = 0 ; ny <= y ; ny++) 
        {
                        
            if (nx==0 && ny==0)
            {
				F[nx][ny] = 1;
			}
			else if (inspect(nx , ny , hx , hy) == 1 )//:当前位置没有被马吃掉
			{ 
			    F[nx][ny] = 0 ;
			}
			else if (nx == 0 )
            {
                F[nx][ny] = F[nx][ny - 1] ;
            }
            else if (ny == 0 )
            {
                F[nx][ny] = F[nx - 1][ny] ;
            }
            else
            {
                F[nx][ny] = F[nx - 1][ny] + F[nx][ny - 1] ;
            }
        }
    }
    
   
    printf("%d\n", F[x][y]); //:输出从{0,0}到{x,y}的步数
    for (int i = 0; i <= x; i++) {
			for (int j = 0; j <= y; j++) 
			{
				printf("% lld", F[i][j]);
			}
			printf("\n");//按数组的行换行
		}
	

    return 0 ;

}
