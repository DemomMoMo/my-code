#include<stdio.h>

int main()
{
	//求10000以内的素数
	int num[2000] = { 2 }; //定义一个以2开头的素数数组
	int i, j, n = 1; //n为已求素数的个数
	for (i = 3; i < 10000; i += 2)
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
	printf("一共记录了有%d素数\n",n);
	return 0;
