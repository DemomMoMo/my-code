#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>;
int AC(int a)
{
	int b;
	int i;
		b = 1;
		i = 0;
		while (i < a)
		{
			i++;
			b = b*i;
		}
		
	return b;
}
int main()
{
	int i;
	int X;
	int f;
	int c;
	X = 0;
	scanf("%d", &f);
		f = f + 1;
	for (i = 1; i <f; i++)
	{
		c = AC(i);
		X = X + c;
	}
	printf("%d\n", X);
	return 0;
}
