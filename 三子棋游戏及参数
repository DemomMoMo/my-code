#include<stdio.h>
#define Xc 3
#define Yc 3
#include<windows.h>

void Start(char board[Xc][Yc], int x, int y)
{
	int i;
	int j;
	for (i = 0; i < y; i++)
	{
		for (j = 0; j < x; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < x - 1)
				printf("|");
		}
		printf("\n");
		if (i < y - 1)
		{
			for (j = 0; j < y; j++)
			{
				printf("---");
				if (j < x - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void P1(char board[Xc][Yc], int x, int y)
{
	int X;
	int Y;
	printf("玩家1请输入你下一步棋的坐标\n");
	while (1)
	{
		printf("X坐标为");
		scanf("%d", &X);
		printf("Y坐标为");
		scanf("%d", &Y);
		if ((X > 0 && Y > 0) && (X < x + 1 && Y < y + 1))
		{
			if (board[X - 1][Y - 1] == 0) 
			{
				board[X - 1][Y - 1] = 'O';
				break;
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

void P2(char board[Xc][Yc], int x, int y)
{
	int X;
	int Y;
	printf("玩家2请输入你下一步棋的坐标\n");
	while (1)
	{
		printf("X坐标为");
		scanf("%d", &X);
		printf("Y坐标为");
		scanf("%d", &Y);
		printf("\n");
		if ((X > 0 && Y > 0) && (X < x + 1 && Y < y + 1))
		{
		 	if (board[X - 1][Y - 1] == 0)
			{
				board[X - 1][Y - 1] = 'X';
				break;
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

char win(char board[Xc][Yc], int x, int y)
{
	static int num;
	num++;
	int i;
	for (i = 0; i < x; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && (board[i][0] != 0) )
			return board[i][1];
	}
	for (i = 0; i < x; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && (board[0][i] != 0))
			return board[1][i];
	}
	if (num >= x*y)
		return 'F';
	if ((board[0][0] == board[2][2]) && (board[1][1] == board[2][2]) && (board[2][2] != 0))
		return board[1][1];
	if ((board[0][2] == board[2][2]) && (board[1][1] == board[2][0]) && (board[2][2] !=0))
		return board[1][1];
	return 'T';
}
void play()
{
	char board[Xc][Yc] = { 0 };
	char ret = "T";
	Start(board, Xc, Yc);
	while (1){
		P1(board, Xc, Yc);
		Start(board, Xc, Yc);
		ret = win(board, Xc, Yc);
		if  (ret != 'T')
			break;
		P2(board, Xc, Yc);
		Start(board, Xc, Yc);
			ret = win(board, Xc, Yc);
			if (ret != 'T')
			break;
	}
	if (ret == 'F')
		printf("平局\n");
	if (ret == 'O')
		printf("玩家1胜利\n");
	if (ret == 'X')
		printf("玩家2胜利\n");
		
}
