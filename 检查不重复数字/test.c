//һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
//�ҳ����������֣����ʵ�֡�
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

void Find_num(int *arr, int sz, int *px, int *py)
{
	//1.�Ƚ�ȫ�����
	int num = 0;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		num ^= arr[i];
	}
	//2.�ҳ����Ϊ1��λ��
	int pos = 0;
	for (i = 0; i < 32; i++)
	{
		if (((num >> i) & 1) == 1);
		{
			pos = i;
			break;
		}
	}
	//3.���շ��齫�����ҳ�
	for (i = 0; i < sz; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			*px ^= arr[i];
		}
		else
			*py ^= arr[i];
	}
}



int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int n1 = 0;
	int n2 = 0;
	Find_num(arr, sz, &n1, &n2);
	printf("%d %d\n", n1, n2);
	system("pause");
	return 0;
}