#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int X(int a)
{
	int i;
	int b = 1;
	for (i = 1; i < a; i++)
	{
		b = b*i;
	}
	return b;
}
int CC(int i,int j)
{
	int z;
	z = X(i) / (X(j)*X(i-j));
		return z;
}
int main()
{
	int i=1;
	int j=1;
	for (i =0; i <= 10; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d  ", CC(i, j));
		}
		printf("\n");
	}
	return 0;
}
