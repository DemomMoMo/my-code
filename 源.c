#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int Count(int a)
{
	int i;
	int c = 0;
	for (i = 0; i < 32; i++)
	{
		if (a &1 == 1)
			c++;
		a = a >> 1;
	}
	return c ;
}

int main()
{
	int count;
	int a;
	scanf("%d", &a);
	count = Count(a);
	printf("%d",count);
	return 0;
}

