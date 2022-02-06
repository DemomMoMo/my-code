#include<stdio.h>

#define hen 12
#define kun 12
#define dif 4
#define hens hen+2*dif
#define kuns kun+2*dif


#include<stdlib.h>

void Game();
void begin();
char P(char board[hens][kuns], char c);
void Dis(char board[hens][kuns]);
char Inspect(char board[hens][kuns], int X,int Y);