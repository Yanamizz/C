#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define  int long long

char* itoa1(int a);
void swap(char** a, char** b);

int main()
{
	int n;
	scanf("%d", &n);
	
	int num[21];
	char* numc[21];

	for (int i=0 ; i<n ; i++)
	{
		scanf ("%d" , &num[i]);
		numc[i] = itoa1(num[i]);
	}
	 
	
	for (int i =0 ; i < n ; i++)//冒泡
	{
		int k = 0;
		for (int j = 0 ; j< n-i-1; j++)
		{
			if (strcmp(numc[j] , numc[j+1]) < 0)
			{
				swap (&numc[j] ,&numc[j+1]);
				k++;
			}
		}
		if (k == 0)
		{
			break;
		}//优化
	}
	
	char* result;
	result = (char*) malloc (200 * sizeof(char));
	result[0] = '\0';
	for (int i =0; i<n ; i++)
	{			
		strcat (result , numc[i]);	
	}
	
	int W = atoi(result);
	free(result);
	for (int i = 0 ; i<n ; i++)
	{
		free(numc[i]);
	}
	
	printf("%d", W);
	return 0;
}

char* itoa1(int a)
{
	char *c;
	c = (char*) malloc (10 * sizeof(char));
	sprintf(c, "%d", a);
	return c;
}

void swap(char**a , char**b)
{
	char* temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
