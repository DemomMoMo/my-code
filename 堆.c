#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void insert(int arr[20], int i)
{
	int num;
	scanf("%d", &num);
	for (; arr[i / 2] < num&&i!=0; i /= 2)
		arr[i] = arr[i/2];
	arr[i] = num;
}

int main()
{
	int C[20] = {0};
	int it,i;
	scanf("%d",&it);
	insert(C, 0);
	for (i = 1; i < it; i++)
	{
		insert(C,i);
	}
	int j,t;
	for (i = 0, j = 1; i < it; j*=2)
	{
		for (t = 0; t < j; t++,i++)
			printf("%-2d ",C[i]);
		printf("\n");
	}

}
