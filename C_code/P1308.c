#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count(char *article, char *word);
void lower(char *a);

int main()
{
	char *article = NULL ,  *word = NULL ;
	size_t len = 100;
	word = (char*) malloc( len * sizeof(char) );
	fgets(word, len, stdin);
	
	char ch; int size = 0;
	while ((ch = getchar()) != '\n')
	{
		article = (char*) realloc(article, size + 1);
		article[size] = ch;
		size++;
	}
	article = (char*) realloc(article, size + 1);
	article[size] = '\0';
	//利用内存分配realloc扩容,最大化利用内存空间;
	lower(article);
	lower(word);
	word[strlen(word) - 1] = '\0';//由于输入时word 和 article 分行输出,所以word末尾存在换行符'\n';
	
	if (strstr(article, word) == NULL)
	{
		printf ("-1");
		free(article);
		free(word);
		return 0;
	}
	
	int place = strstr(article, word) - article;
	int c = count(article, word);
	
	free(article);
	free(word);
	
	printf ("%d %d", c, place);
	return 0;
}

int count(char *article, char *word)
{
	int count = 0;
	char *p = article;
	while ((p = strstr(p, word)) != NULL)
	{
		count++;
		p += strlen(word);
	}
	return count;
}

void lower(char *a)
{
	int i = 0;
	while (a[i] != '\0')
	{
		if (a[i] >= 'A' && a[i] <= 'Z')
		{
			a[i] += 32;
		}
		a++;
	}
}

