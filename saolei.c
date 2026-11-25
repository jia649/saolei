
#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
#include<stdio.h>


void InitBoard(char Board[ROWS][COLS], int r, int c,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < r;i++)
	{
		for (j = 0;j < c;j++)
		{
			Board[i][j] = set;
		}

	}
}


int GetMineCount(char mine[ROWS][COLS], int a, int b)
{
return	mine[a - 1][b] + mine[a - 1][b - 1] + mine[a][b - 1] + mine[a + 1][b - 1] + mine[a + 1][b] + mine[a + 1][b + 1] + mine[a][b + 1] + mine[a - 1][b + 1] - 8 * '0';

}





void DisplayBoard(char Board[ROWS][COLS], int r, int c)
{
	int i;
	int j;
	for (j = 0;j <= c; j++)
	{
		printf("%d ",j);
	}
	printf("\n");
	for (i = 1; i <= r; i++)
	{
		printf("%d ",i);
		for (j = 1;j <= c; j++)
		{
			printf("%c ", Board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void Setmine(char board[ROWS][COLS], int r, int c)
{

	int count = 10;
	while (count)
	{
		int x = rand()%r+1;
		int y = rand() % c + 1;
		if (board[x][y] =='0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}


void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int r, int c)
{
	printf("请输入一个坐标，行和列中间用空格隔开");
	int a=0;
	int b = 0;
	int win = 0;
	while (win<r*c-10)
	{
		scanf("%d%d", &a, &b);
		if (a >= 1 && a <= r && b >= 1 && b <= c)
		{
			if (show[a][b] != '*')
			{
				printf("这个位置已经排查过了\n");
			}
			else
			{
				if (mine[a][b] == '1')
				{
					printf("你踩到雷了，游戏结束。\n");
					DisplayBoard(mine, ROW, COL);
					break;
				}
				else
				{
					int count = GetMineCount(mine, a, b);
					show[a][b] = (char)count + '0';
					DisplayBoard(show, ROW, COL);
					win++;

				}
			}

		}
		else
		{
			printf("输入的坐标违法，请重新输入\n");


		}
	}
	if (win == r * c - 10)
	{
		printf("牛逼，你赢了。可以给蒋睿发个红包支持一下。");
		DisplayBoard(mine, ROW, COL);
	}
}





