#define _CRT_SECURE_NO_WARNINGS 1
#define n 10
#include<stdio.h>

int main()
{
	int i=0;
	int j=0;
	int arr[n][n] = { 0 };
	arr[i][j] = 1;
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (j==0||j==i)
			arr[i][j] = 1;
			else
			{
				arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= n-i; j++)
		{
			printf("  ", arr[i][j]);
		}
		for (j = 0; j <= i; j++)
		{
			printf("%3d  ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
	