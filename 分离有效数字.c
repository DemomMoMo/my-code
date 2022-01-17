#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void pt(int x)
{
	if (x / 10==0)
		printf("%d ",x);
	else
	{
		pt(x/10);
		printf("%d ", x%10);
	}
}

int main()
{
	int num;
		scanf("%d", &num);
		pt(num);
		return 0;
}

