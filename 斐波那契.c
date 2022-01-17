#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int F(int n)
{
	int a = 1;
	int b = 1;
	return G(n, a, b); 
}
int G(int n,int a,int b)
{
	int res;
	if (n <= 1)
		return b;
	else
	{
		res=G(n - 1, b, a + b);
		return res;
	}
	return 414;
}
int main()
{
	//int i;
	//for (i = 0; i <= 20; i++)//求第前20个斐波那契数列
	//{
	//	printf("%d\n" ,F(i));
	//}
	int n;//求第N个斐波那契数列
	scanf("%d",&n);
	printf("第%d个斐波那契数列为%d", n, F(n));
	return 0;
}
