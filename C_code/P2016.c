#include <stdio.h>

void fz(int *year);
int judge(int a);

int main() 
{
	int date1 = 0, date2 = 0;
	scanf ("%d\n%d", &date1, &date2);
	
	int year1=date1 / 10000 , year2=date2 / 10000;
	
	int a , num = 0;

	for (int i = year1 ; i <= year2 ; i++)
	{
		a = i;
		int *p = &a;
		fz (p);
		if (a <= date2 && a >= date1)
		{
			if (judge(a))
			{
				num++;
			}
		}
	}
	
	printf ("%d", num);
	return 0;
}

void fz(int *year)
{
	int x = *year;
	for (int i = 0; i < 4; i++)
	{
		*year = *year*10 + x%10;
		x /= 10;
	}
}

int judge(int a)
{
	int md[13]={31,28,31,30,31,30,31,31,30,31,30,31};
	int year = a/10000 , month = a/100%100 , day = a%100;
	
	if (year%400 == 0 || (year%4 == 0 && year%100 != 0))
	{
		md[1] = 29;
	}
		
	if (month == 0 || month > 12)
	{
		return 0;
	}
	
	int day1 = md[month - 1];
	if (day>day1)
	{
		return 0;
	}
	return 1;
}
