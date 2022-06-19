#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define num rand()%13+1 


int Gause(int a)
{
	int b = num,c;
	switch (a){
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
				c = b - a;
				break;
			default:
				c = a - b;
				break;		
}
	if (c > 0)
		return Gause(b) + 1;
	else
		return 1;
}

int main()
{
	srand((unsigned int)time(NULL));
	int j;
	for (j = 0; j < 10; j++)
	{
		int  i, t;
		double x = 0.0, xa;
		t = 100000;
		for (i = 0; i < t; i++)
		{
			x += Gause(num) + 1;
		}
		xa = x / t;
		printf("王荣吉占期望为%2f\n", xa);
	}
}
