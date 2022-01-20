#include<stdio.h>

#define hens 11
#define kuns 11
#define hen 9
#define kun 9
#define dif 10

#include<time.h>

void exchange(char board[kuns][hens], int i, int j,char c)
{
	for (i = 0; i < kuns; i++)
	{
		for (j = 0; j < hens; j++)
		{
			board[i][j] = c;
		}
	}
}

void display(char board[kuns][hens], int i, int j)
{
	for (j = 0; j < hen+1; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 0; i < kuns-2; i++)
	{
		printf("%d ", i+1);
		for (j = 0; j < hens-2; j++)
		{
			printf("%c ",board[i+1][j+1]);
		}
		printf("\n");
	}
}

void Boom(char lei[kuns][hens])
{
	int x;
	int y;
	int i;
	for (i = 0; i < dif; i++)
	{
		x = rand() % kun + 1;
		y = rand() % hen + 1;
		if (lei[x][y] == '0')
			lei[x][y] = '1';
		else
		{
			i--;
		}
	}
}

char count(char lei[kuns][hens],int x, int y)
{
	int i;
	int j;
	int Count=0;
	char c;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			Count += lei[x + i][y + j] - '0';
		}
	}
	c = Count + '0';
	return c ;
}

void Game()
{
	char board[kuns][hens] = { 0 };
	exchange(board, kuns, hens,'*');//重置棋盘

	char lei[kuns][hens] = { 0 };
	exchange(lei, kuns, hens, '0');
	srand((unsigned int)time(NULL));
	Boom(lei);//生成雷区

	display(board, kuns, hens);
	int test = 0;
	int x;
	int y;
	while (1)
	{
		while (1)
		{
			printf("请输入你下一步的坐标yx\n");
			scanf("%d%d", &x, &y);
			if (board[x][y] == '*' && (x > 0 && x<10) && (y>0 && y < 10))
				break;
			printf("坐标不合法请重新输入\n");
		}
		if (lei[x ][y ] == '1')
			{
				printf("你输了\n");
				display(lei, kuns, hens);
				break;
			}
		if (lei[x ][y ] == '0')
			{
				printf(" 成功排除1格 \n");
				test++;
				board[x ][y ] =  count(lei, x , y );
				display(board, kuns, hens);
			}
		
			if (test >= kun*hen-dif)
			{
				printf("你赢了\n");
				display(lei, kuns, hens);
				break;
			}
	}

	}
