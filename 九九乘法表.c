#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i = 1;
	int j = 1;
	for (i = 1; i < 10; i++)
	{
		
		for (j = 1; j < i; j++)
		{
			
			printf("%dx%d=%2d  ",i,j, i*j);
			/*if ((i == 3 && i*j == 6) || (i == 4 && i*j == 8))
				printf(" ");*/
			}
		printf("%dx%d=%2d\n", i, j, i*j);
	}
}
