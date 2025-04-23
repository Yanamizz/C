#include <stdio.h>
#include <stdlib.h>
int* num;
int n;

int judge(int a);
int main()
{
	int sum = 0;
	
	scanf ("%d" , &n);
	num = (int*) malloc (n * sizeof(int));
	for (int i = 0; i < n ; i++)
	{
		scanf ("%d" , &num[i]);
	}
	
	for (int i = 0; i < n ; i++)
	{
		sum += judge(num[i]);
	}
	
	printf ("%d" , sum);
	return 0;
}

int judge (int a )
{
	for (int i = 0; i < n ; i++)
	{
		if (num[i] < a )
		{
			for (int j = i+1; j < n; j++)
			{
				if (num[i] + num[j] == a)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}
