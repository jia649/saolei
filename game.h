#pragma once
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void InitBoard(char Board[ROWS][COLS],int r,int c,char set);


//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int r, int c);

void Setmine(char board[ROWS][COLS], int r, int c);


void FindMine(char board[ROWS][COLS], char Board[ROWS][COLS], int r, int c);


int GetMineCount(char mine[ROWS][COLS], int r, int c);