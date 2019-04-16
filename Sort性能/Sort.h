#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "Stack.h"


void PrintArray(int *a, int n)
{
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//直接插入排序
void InsertSort(int *a, int n)
{
	assert(a);
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0 && a[end] > tmp)
		{
			a[end + 1] = a[end];
			--end;
		}
		a[end + 1] = tmp;
	}
}

void TestInsertSort()
{
	int a[] = { 4, 2, 1, 6, 7, 3, 4, 9, 8, 0 };
	InsertSort(a, sizeof(a) / sizeof(a[0]));
	printf("插入=>");
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

//希尔排序
void ShellSort(int *a, int n)
{
	assert(a);
	int gap = n;
	while (gap > 1)
	{
		//预排序
		gap = gap / 3 +1;
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0 && a[end] > tmp)
			{
				a[end + gap] = a[end];
				end -= gap;
			}
			a[end + gap] = tmp;
		}
	}
}

void TestShellSort()
{
	int a[] = { 4, 2, 1, 6, 7, 3, 4, 9, 8, 0 };
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	printf("希尔=>");
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}


void Swap(int *p1, int *p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//选择排序
void SelectSort(int *a, int n)
{
	assert(a);
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int min = begin, max = end;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] > a[max])
				max = i;

			if (a[i] < a[min])
				min = i;
		}
		Swap(&a[begin], &a[min]);

		if (begin == max)//注意上面交换的时候，在两个相同的基础上，会把max交换到其他位置，但是我们可能还会以为它在begin的位置
			max = min;

		Swap(&a[end], &a[max]);
		++begin;
		--end;
	}
}

void TestSelectSort()
{
	int a[] = { 4, 2, 1, 6, 7, 3, 4, 9, 8, 0 };
	SelectSort(a, sizeof(a) / sizeof(a[0]));
	printf("选择=>");
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}


//堆排序
void AdjustDown(int *a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n
			&& a[child + 1] > a[child])
		{
			++child;
		}

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int *a, int n)
{
	assert(a);
	//建堆,向下调整建堆
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

void TestHeapSort()
{
	int a[] = { 4, 2, 1, 6, 7, 3, 4, 9, 8, 0 };
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	printf("堆排=>");
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}


//冒泡
void BubbleSort(int *a, int n)
{
	assert(a);
	int end = n;
	while (end > 0)
	{
		int flag = 0;
		for (int i = 1; i < n; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
		--end;
	}
}

void TestBubbleSort()
{
	int a[] = { 4, 2, 1, 6, 7, 3, 4, 9, 8, 0 };
	BubbleSort(a, sizeof(a) / sizeof(a[0]));
	printf("冒泡=>");
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

//快速排序
//三数取中
int GetMidIndex(int* a, int begin, int end)
{
	int mid = begin - ((end - begin) >> 1);
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
	else
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return begin;
		}

		else
		{
			return end;
		}
	}
}

//单趟排序
//hoare版本
int PartSort1(int *a, int begin, int end)
{
	assert(a);

	int mindindex = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[mindindex]);

	int key = a[begin];
	int start = begin;
	while (begin < end)
	{
		//end 找小
		while (begin < end && a[end] >= key)
			--end;

		//begin 找大
		while (begin < end && a[begin] <= key)
			++begin;

		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[start]);

	return begin;
}

//挖坑法
int PartSort2(int *a, int begin, int end)
{
	assert(a);
	int key = a[begin];
	int start = begin;
	while (begin < end)
	{
		while (begin < end && a[end] >= key)
		{
			--end;
		}

		a[begin] = a[end];

		while (begin < end && a[begin] <= key)
		{
			++begin;
		}

		a[end] = a[begin];
	}
	a[begin] = key;

	return begin;
}

//前后指针版本
int PartSort3(int *a, int begin, int end)
{
	assert(a);
	int key = a[begin];
	int prev = begin;
	int cur = begin + 1;
	while (cur <= end)
	{
		if (a[cur] < key && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	Swap(&a[begin], &a[prev]);

	return begin;
}

//递归算法
void  QuickSort(int *a, int left, int right)
{
	assert(a);
	if (left >= right)
		return;

	//小区间优化
	if (right - left + 1 < 10)
	{
		InsertSort(a + left, right - left + 1);
	}
	else
	{
		//int div = PartSort1(a, left, right);
		//int div = PartSort2(a, left, right);
		int div = PartSort3(a, left, right);

		//[left, div - 1]
		//[div + 1, right]
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
}

//非递归
void QuickSortR(int *a, int left, int right)
{
	assert(a);
	Stack st;
	StackInit(&st, 10);
	if (left < right)
	{
		StackPush(&st, right);
		StackPush(&st, left);
	}

	while (StackEmpty(&st) != 0)
	{
		left = StackTop(&st);
		StackPop(&st);
		right = StackTop(&st);
		StackPop(&st);

		int div = PartSort1(a, left, right);
		//[left, div-1]
		if (left < div - 1)
		{
			StackPush(&st, div - 1);
			StackPush(&st, left);
		}
		//[div+1, right]
		if (div + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, div + 1);
		}
	}
}

void TestQuickSort()
{
	int a[] = { 4, 2, 1, 6, 7, 3, 4, 9, 8, 0 };
	QuickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	printf("快速=>");
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestQuickSortR()
{
	int a[] = { 4, 2, 1, 6, 7, 3, 4, 9, 8, 0 };
	QuickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	printf("快速=>");
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}



//归并
void _MergeSort(int* a, int* tmp, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	
	int mid = left + ((right - left) >> 1);
	//[left, mid]
	//[mid+1, right]
	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid + 1, right);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}

	while (begin1 <= end1)
		tmp[index++] = a[begin1++];

	while (begin2 <= end2)
		tmp[index++] = a[begin2++];

	memcpy(a + left, tmp + left, sizeof(int)*(right - left + 1));
}

void MergeSort(int* a, int n)
{
	assert(a);
	int *tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, tmp, 0, n - 1);
	free(tmp);
}

void TestMergeSort()
{
	int a[] = { 4, 2, 1, 6, 7, 3, 4, 9, 8, 0 };
	MergeSort(a, sizeof(a) / sizeof(a[0]));
	printf("归并=>");
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}


//计数
void CountSort(int* a, int n)
{
	//统计个数，范围大小，最大的减最小的
	int max = a[0], min = a[0];
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > max)
			max = a[i];

		if (a[i] < min)
			min = a[i];
	}

	int range = max - min + 1;
	int *count = (int*)malloc(range*sizeof(int));
	memset(count, 0, sizeof(int)*range);

	//统计个数
	for (int i = 0; i < n; ++i)
		count[a[i] - min]++;

	int index = 0;
	for (int i = 0; i < range; ++i)
	{
		while (count[i]--)
		{
			a[index++] = i + min;//相对位置,不然如果第一个不是0的话，就会错位
		}
	}
}

void TestCountSort()
{
	int a[] = { 4, 2, 1, 6, 7, 3, 4, 9, 8, 0};
	CountSort(a, sizeof(a) / sizeof(a[0]));
	printf("计数=>");
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}


void TestSortOP()
{
	const int n = 10000000;
	int *a1 = (int*)malloc(sizeof(int)*n);
	int *a2 = (int*)malloc(sizeof(int)*n);
	int *a3 = (int*)malloc(sizeof(int)*n);
	int *a4 = (int*)malloc(sizeof(int)*n);
	int *a5 = (int*)malloc(sizeof(int)*n);
	int *a6 = (int*)malloc(sizeof(int)*n);
	int *a7 = (int*)malloc(sizeof(int)*n);
	int *a8 = (int*)malloc(sizeof(int)*n);

	srand((int)time(0));
	for ( int i = 0; i < n; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
	}

	size_t begin1 = clock();
	//InsertSort(a1, n);
	size_t end1 = clock();
	printf("插入-> %u\n", end1 - begin1);

	size_t begin2 = clock();
	ShellSort(a2, n);
	size_t end2 = clock();
	printf("希尔-> %u\n", end2 - begin2);

	size_t begin3 = clock();
	//SelectSort(a3, n);
	size_t end3 = clock();
	printf("选择-> %u\n", end3 - begin3);

	size_t begin4 = clock();
	HeapSort(a4, n);
	size_t end4 = clock();
	printf("堆排-> %u\n", end4 - begin4);

	size_t begin5 = clock();
	//BubbleSort(a5, n);
	size_t end5 = clock();
	printf("冒泡-> %u\n", end5 - begin5);

	size_t begin6 = clock();
	//QuickSort(a6, 0, n);
	size_t end6 = clock();
	printf("快速-> %u\n", end6 - begin6);

	size_t begin7 = clock();
	MergeSort(a7, n);
	size_t end7 = clock();
	printf("归并-> %u\n", end7 - begin7);

	size_t begin8 = clock();
	CountSort(a8, n);
	size_t end8 = clock();
	printf("计数-> %u\n", end8 - begin8);
}