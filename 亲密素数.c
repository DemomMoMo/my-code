#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	//求100以内的素数
	int num[50] = { 2 }; //定义一个以2开头的素数数组
	int i, j, n = 1; //n为已求素数的个数
	for (i = 3; i <= 100; i += 2)
	{
		for (j = 1; j < n; j++)
		{
			if (i%num[j] == 0) //判断一个数取模小于其的素数是否等于0
				break; //等于0则跳出计算下一个数
		}
		if (j==n)
		{
			num[n] = i; //均不等于0后记录这个数
		n++;
	}
	}
	printf("一共记录了有%d个素数\n",n);
	int num2[50];
	for (i = 1,j=0; i < n; i++)
	{
		if (num[i - 1] + 2 == num[i])
		{
			num2[j] = num[i - 1];
			num2[j + 1] = num[i];
			j += 2;
		}
	}
	printf("其中亲密素数对有%d对,分别为:\n",j/2);
	for (i = 0; i < j; i += 2)
		printf("%d和%d,", num2[i],num2[i+1]);
	return 0;
}
