#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


int main()
{
	int A = 100, B = 0, C = 0;//A小马.B中马.C大马
	for (C = 0; C <= 34; C++)
	{
		for (A = 100 - C, B = 0; (A + 4 * B + 6 * C) < 200; A--, B++)
		{
			;
		}
		if ((A  + 4 * B + 6 * C) == 200)
			printf("小马=%d,中马=%d,大马=%d\n",A,B,C);
	}
	return 0;
}
