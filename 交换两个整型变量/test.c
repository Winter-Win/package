#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = 10;
	int b = 20;
	scanf("%d%d", &a, &b);
	printf("a=%d b=%d\n", a, b);
	a = a^b;//��(������)λ���
	b = a^b;
	a = a^b;
	printf("a=%d b=%d\n", a, b);
	system("pause");
	return 0;
}












//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int tmp = 0;//������ʱ����
//	scanf("%d%d", &a, &b);
//	printf("a=%d b=%d\n", a, b);
//	tmp = a;
//	a = b;
//	b = tmp;
//	printf("a=%d b=%d\n", a, b);
//	system("pause");
//	return 0;
//}
