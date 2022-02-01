#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}

int div(int a, int b)
{
	return a / b;
}

void test(int (*pl)(int a, int b))
{
	int x = 0;
	int y = 0;
	printf("请输入2个操作数\n");
	scanf("%d%d",&x,&y);
	printf("结果=%d\n", (*pl)(x, y));
}


main()
{
	int cos = 0;
	int i = 1;
	while (i)
	{
		printf("####################################################\n");
		printf("###########    1、add     2、sub    ################\n");
		printf("###########    3、mul     4、div    ################\n");
		printf("###########         0、exit         ################\n");
		printf("####################################################\n");
		scanf("%d",&cos);
		switch (cos)
		{
		case 1:
			test(add);
			break;
		case 2:
			test(sub);
			break;
		case 3:
			test(mul);
			break;
		case 4:
			test(div);
			break;
		case 0:
			printf("已成功退出\n");
			i = 0;
			break;
		default:
			printf("输入错误请重新输入\n");

		
		}
		

	}

	
	return 0;
}
