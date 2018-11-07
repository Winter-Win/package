#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void test()
{
	//测试游戏
	char mine[ROWS][COLS];//存放雷
	char show[ROWS][COLS];//存放排查到的雷
	InitBoard(mine, ROWS, COLS, '0');//'0'
	InitBoard(show, ROWS, COLS, '*');//'*'
	//布置雷
	SetMine(mine, ROW, COL);
	PrintBoard(show, ROW, COL);
	//排雷
	FindMine(mine, show, ROW, COL);
}


int main()
{
	srand((unsigned int)time(NULL));
	test();
	system("pause");  //此环境下程序停留
	return 0;
}