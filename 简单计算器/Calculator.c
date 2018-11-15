////ԭʼ������
//
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <stdlib.h>
//
//
//int Add(int a, int b)
//{
//	return a + b;
//}
//
//int Sub(int a, int b)
//{
//	return a - b;
//}
//
//int Mul(int a, int b)
//{
//	return a*b;
//}
//
//int Div(int a, int b)
//{
//	return a / b;
//}
//
//int main()
//{
//	int x, y;
//	int input = 1;
//	int ret = 0;
//	while (input)
//	{
//		printf("*************************\n");
//		printf(" *****1:Add   2:Sub *****\n");
//		printf(" *****3:Mul   4:Div *****\n");
//		printf("*************************\n");
//		printf("��ѡ��:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("�����������:>");
//			scanf("%d %d", &x, &y);
//			ret = Add(x, y);
//			break;
//		case 2:
//			printf("�����������:>");
//			scanf("%d %d", &x, &y);
//			ret = Sub(x, y);
//			break;
//		case 3:
//			printf("�����������:>");
//			scanf("%d %d", &x, &y);
//			ret = Mul(x, y);
//			break;
//		case 4:
//			printf("�����������:>");
//			scanf("%d %d", &x, &y);
//			ret = Div(x, y);
//			break;
//		default:
//			printf("ѡ�����\n");
//			break;
//		}
//		printf("ret = %d\n", ret);
//	}
//	system("pause");
//	return 0;
//}


//ת�Ʊ�ʵ�ּ�����

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

int Mul(int a, int b)
{
	return a*b;
}

int Div(int a, int b)
{
	return a / b;
}

int main()
{
	int x, y;
	int input = 1;
	int ret = 0;
	int(*p[5])(int x, int y) = { 0, Add, Sub, Mul, Div }; //ת�Ʊ�,����ָ���ʹ��
	while (input)
	{

		printf("*************************\n");
		printf("**** 1:Add     2:Sub ****\n");
		printf("**** 3:Mul     4:Div ****\n");
		printf("*************************\n");
		printf("��ѡ��:>");
		scanf("%d", &input);
		if ((input < 5 && input > 0))
		{
			printf("�����������:>");
			scanf("%d %d", &x, &y);
			ret = (*p[input])(x, y);
		}
		else
			printf("��������!\n");
		printf("ret = %d\n", ret);
	}
	return 0;
}