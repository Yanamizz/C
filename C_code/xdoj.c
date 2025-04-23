#include <stdio.h>
#include <string.h>

void swap(char ch[],char a, char b ,int c[] ,int x ,int y);
int main()
{
    //数据输入
    char ch[100] ;
    int c[100] = {0};
    int i , n , m;
    scanf("%d %d",&n,&m);   
    scanf("%s",ch);
   
    //初步设置优先级
    for(i=0;ch[i]!='\0'&&ch[i]!='\n';i++)
    {
        if (ch[i]>='A'&&ch[i]<='Z')
        {
            c[i]=ch[i]-'A';
        }
        else if (ch[i]>='a'&&ch[i]<='z')
        {
            c[i]=ch[i]-'a';
        }
        else
        {
            c[i] = 100;
        }
    }
    
    //排序
    for (int x=0;x<n;x++)
    {
        for (int y=0;y<n-x-1;y++)
        {
            if (c[y]>c[y+1])
            {
                swap(ch,y,y+1 ,c,y,y+1);
            }
        }
    }
    
    //插入数字
    for (int x=n-1;x>m;x--)
    {
        swap(ch,x,x-1 ,c,x,x-1);
    }
    
    for (int x=0;x<n;x++)
    {
        printf("%c",ch[x]);
    }
    return 0;
}
 
void swap(char ch[],char a, char b ,int c[] ,int x ,int y)
{
    char temp;
    temp = ch[x];
    ch[x] = ch[y];
    ch[y] = temp;
    int temp1;
    temp1 = c[x];
    c[x] = c[y];
    c[y] = temp1;
}