#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void encode(char ch[41] , char str[11]);

int main()
{
	char ch[41];//源码
    char str[11];//解码
    
    gets(ch);
    
    int m;
    scanf("%d", &m);

    if (strlen(ch) % 4 != 0)
    {
        printf("Bad code!");
        return 0;
    }

    encode(ch, str);

    int i = 0;
    int *p;
    p = (int *)malloc(sizeof(int));
    while (m != 0)
    {
        p = (int *)realloc(p, (i+1) * sizeof(int));
        p[i] = m % 10 - 1;
        m /= 10;
        i++;
    }

    while (i>0)
    {
        i--;
        if(p[i] > strlen(str))
        {
        printf("Bad code!");
        return 0;
        }
        if (p[i] != -1)
        {
            printf("%c", str[p[i]]);
        }
    }
}

void encode(char ch[41] , char str[11])
{
    int i = 0;
    int j = 0;
    while (ch[i] != '\0')
    {
        int sum = 0;
        for (int n = 0; n < 4; n++)
        {
            sum = sum*2 + (ch[i] - '0');
            i++;
        }
        str[j] = sum + 'A';
        j++;
    }
}