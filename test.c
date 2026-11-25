#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

#include<stdio.h>


void menu()
{
	printf("--------------------------\n");
	printf("-------1.play-------------\n");
	printf("-------0.exit-------------\n");
	printf("--------------------------\n");
	printf("--------------------------\n");
}

void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	DisplayBoard(show, ROW, COL);
	//DisplayBoard(mine, ROW, COL);

	//布置雷
	Setmine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);

	//排查雷
	FindMine(mine, show, ROW, COL);


}





int main()
{
	int a;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("睿哥让你选择0或者1。敢乱选就关机。");
		printf("就是在键盘上按数字0或者1，再按回车");
		scanf("%d", &a);

		switch (a)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("傻逼让你别乱选\n");
			break;
		}
	} while (a);
	return 0;
}
