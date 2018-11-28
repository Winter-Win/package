//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//找出这两个数字，编程实现。
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

void Find_num(int *arr, int sz, int *px, int *py)
{
	//1.先将全部异或
	int num = 0;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		num ^= arr[i];
	}
	//2.找出异或为1的位置
	int pos = 0;
	for (i = 0; i < 32; i++)
	{
		if (((num >> i) & 1) == 1);
		{
			pos = i;
			break;
		}
	}
	//3.按照分组将数字找出
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