#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void Dis(char board[hens][kuns])
{
	int i;
	int j;
	for (j = 0; j < kun; j++)
	{
		printf("---");
		if (j < hen)
			printf("|");
	}
	printf("\n");
	for (i = 0; i <= kun-1; i++)
	{
		for (j = 0; j <= hen-1; j++)
		{
			printf(" %c ", board[dif+i][dif+j]);
			if (j < hen+1 )
				printf("|");
		}
		printf("\n");
		if (i < kun )
		{
			for (j = 0; j < kun; j++)
			{
				printf("---");
				if (j < hen )
					printf("|");
			}
			printf("\n");
		}
	}
}

char P(char board[hens][kuns],char c)
{
	char f;
	int X;
	int Y;
	if (c == 'O')
		printf("玩家1请输入你下一步棋‘O’的坐标\n");
	else{
		printf("玩家2请输入你下一步棋‘X’的坐标\n");
	}
	while (1)
	{
		printf("X坐标为");
		scanf("%d", &Y);
		printf("Y坐标为");
		scanf("%d", &X);
		if ((X > 0 && Y > 0) && (X <= hen  && Y <=kun))
		{
			X += dif-1;
			Y += dif-1;
			if (board[X ][Y ] == 0)
			{
				board[X ][Y ] = c;
				Dis(board);
				f=Inspect(board, X,Y);
				return f;
			}
			else
			{
				printf("该位置已被占用\n");
			}
		}
		else
		{
			printf("该位置不合法\n");
		}
	}
}

char Inspect(char board[hens][kuns],  int X, int Y)
{
	int j;
	
    //竖行检测
	int cot = 0;
		for (j = 1; j <= dif; j++)
		{
			if (board[X][Y] == board[X + j][Y])
				cot++;
			else
			{
				break;
			}
		}
		for (j = 1; j <= dif; j++)
		{
			if (board[X][Y] == board[X - j][Y])
				cot++;
			else
			{
				break;
			}
		}
		if (cot >= dif)
			return board[X][Y];
	
		//横行检测
		 cot = 0;
		for (j = 1; j <= dif; j++)
		{
			if (board[X][Y] == board[X ][Y+j])
				cot++;
			else
			{
				break;
			}
		}
		for (j = 1; j <= dif; j++)
		{
			if (board[X][Y] == board[X ][Y-j])
				cot++;
			else
			{
				break;
			}
		}
		if (cot >= dif)
			return board[X][Y];

		//一三检测
		cot = 0;
		for (j = 1; j <= dif; j++)
		{
			if (board[X][Y] == board[X+j][Y + j])
				cot++;
			else
			{
				break;
			}
		}
		for (j = 1; j <= dif; j++)
		{
			if (board[X][Y] == board[X-j][Y - j])
				cot++;
			else
			{
				break;
			}
		}
		if (cot >= dif)
			return board[X][Y];

		//二四检测
		 cot = 0;
		for (j = 1; j <= dif; j++)
		{
			if (board[X][Y] == board[X - j][Y + j])
				cot++;
			else
			{
				break;
			}
		}
		for (j = 1; j <= dif; j++)
		{
			if (board[X][Y] == board[X + j][Y - j])
				cot++;
			else
			{
				break;
			}
		}
		if (cot >= dif)
			return board[X][Y];

		return '0';
	}



void Game()
{
	int test = 1;
	char c;
	char ret = '0';
	char board[hens][kuns] = { 0 };
	Dis(board);
	while (ret=='0')
	{
		if (test % 2)
			c = 'O';
		else{ c = 'X'; }
		ret = P(board,c);	
		test++;
		if (test >= hen*kun)
			ret = 'F';
	}
	if (ret == 'F')
		printf("平局\n");
	if (ret == 'O')
		printf("玩家1('O')胜利\n");
	if (ret == 'X')
		printf("玩家2('X')胜利\n");
}