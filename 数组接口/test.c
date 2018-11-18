#define _CRT_SECURE_NO_WARNINGS 1

//����һ�����飬 
//ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��

#include <stdio.h>
#include <stdlib.h>

void Init(int array[], int sz)
{
	int i = 0;
	for (i = 0; i<sz; i++)
	{
		array[i] = i + 1;
	}
}

void Print(int array[], int sz)
{
	int i = 0;
	for (i = 0; i<sz; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void Reverse(int array[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left<right)
	{
		int tmp = array[left];
		array[left] = array[right];
		array[right] = tmp;
		left++;
		right--;
	}
}

void Empty(int array[], int sz)
{
	int i = 0;
	for (i = 0; i<sz; i++)
	{
		array[i] = 0;
	}
}
int main()
{
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Print(arr, sz);
	Init(arr, sz);
	Print(arr, sz);
	Reverse(arr, sz);
	Print(arr, sz);
	Empty(arr, sz);
	Print(arr, sz);
	system("pause");
	return 0;
}