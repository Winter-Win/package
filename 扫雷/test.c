#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void test()
{
	//������Ϸ
	char mine[ROWS][COLS];//�����
	char show[ROWS][COLS];//����Ų鵽����
	InitBoard(mine, ROWS, COLS, '0');//'0'
	InitBoard(show, ROWS, COLS, '*');//'*'
	//������
	SetMine(mine, ROW, COL);
	PrintBoard(show, ROW, COL);
	//����
	FindMine(mine, show, ROW, COL);
}


int main()
{
	srand((unsigned int)time(NULL));
	test();
	system("pause");  //�˻����³���ͣ��
	return 0;
}