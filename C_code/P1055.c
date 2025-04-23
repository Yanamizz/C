#include <stdio.h>
#include <math.h>
char N[15];

char judge(int num);
int main()
{
	int num = 0;
	scanf ("%s" , N);
	
	for (int i =0; N[i] != '\0'; i++)
	{
		if (N[i] != '-')
		{
			num = num*10 + (int)N[i];
		}
	}
	
	char m = judge(num);
	if (m == 'y')
	{
		printf("Right");
	}
	else
	{
		N[12] = m;
		printf ("%s", N);
	}
	
	return 0;
}

char judge(int num)
{
	int sum = 0;
	
	for (int i =1; i < 9;i++)
	{
		sum += num / (int)pow(10 , 10-i) * i;
		num %= (int)pow(10 , 9-i);
	}
	
	int n = sum % 11;
	char m;
	if (n == 10)
	{
		m = 'X';
	}
	else 
	{
		m =(char)n;
	}
	
	if (m == N[12])
	{
		return 'y';
	}
	else
	{
		return m;
	}
	
	
}
