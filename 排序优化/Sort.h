#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Stack.h"

void PrintArr(int* a,int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}


void Swap(int* a, int* b)
{
	assert(a && b);
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void InsertSort(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0 && a[end] > tmp)
		{
			a[end + 1] = a[end];
			end--;
		}
		a[end + 1] = tmp;
	}
}

void InsertSortTest()
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37, 28 };
	int sz = sizeof(a) / sizeof(a[0]);
	InsertSort(a, sz);
	PrintArr(a, sz);
}

void ShellSort(int* a, int n)//希尔排序
{
	assert(a);
	int gap = n;//创建一个分组区间大小
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
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

void ShellSortTest()
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37, 28 };
	int sz = sizeof(a) / sizeof(a[0]);
	ShellSort(a, sz);
	PrintArr(a, sz);
}


void SelectSort(int* a, int n)
{
	assert(a);
	int begin = 0;
	int end = n - 1;
	int i = 0;
	while (begin < end)
	{
		int max = begin, min = begin;
		for (i = begin; i <= end; i++)
		{
			if (a[i] >= a[max])
				max = i;

			if (a[i] <= a[min])
				min = i;
		}
		if (begin != min)
			Swap(&a[begin], &a[min]);

		if (begin == max)
			max = min;

		Swap(&a[end], &a[max]);
		begin++;
		end--;
	}
}

void SelectSortTest()
{
	int a1[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37, 28 };
	//int a2[] = { 5, 2, 4, 6, 1, 3, 8, 7, 9, 0};
	int sz1 = sizeof(a1) / sizeof(a1[0]);
	//int sz2 = sizeof(a2) / sizeof(a2[0]);
	SelectSort(a1, sz1);
	PrintArr(a1, sz1);
	//SelectSort(a2, sz2);
	//PrintArr(a2, sz2);
}

void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//选择左右孩子中较大的
		if (child + 1 < n && a[child + 1] > a[child])//默认child最大
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	assert(a);
	//建堆
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}


void HeapSortTest()
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37, 28 };
	int sz = sizeof(a) / sizeof(a[0]);
	HeapSort(a, sz);
	PrintArr(a, sz);
}


void BubbleSort(int* a, int n)
{
	assert(a);
	int begin = 0;
	int end = n - 1;
	while (end--)
	{
		for (begin = 0; begin <= end; begin++)
		{
			if (a[begin] > a[begin + 1])
				Swap(&a[begin], &a[begin + 1]);
		}
	}
}

void BubbleSortTest()
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37, 28 };
	int sz = sizeof(a) / sizeof(a[0]);
	BubbleSort(a, sz);
	PrintArr(a, sz);
}


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


int PartSort(int* a, int begin, int end)
{
	int midindex = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[midindex]);

	assert(a);
	int key = a[begin];
	int start = begin;
	while (begin < end)
	{
		while(begin < end && key <= a[end])
			end--;
		
		while(begin < end && key >= a[begin])
			begin++;

		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[start]);

	return begin;
}



//快速排序递归；
void QuickSort(int *a, int left, int right)
{
	if (left >= right)
		return;
	if (right - left + 1 < 10)//小区间优化
	{
		InsertSort(a + left, right - left + 1);
	}
	else
	{
		int div = PartSort(a, left, right);

		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
}


//快速排序非递归：
void QuickSortR(int* a, int left, int right)
{
	assert(a);
	Stack st;
	StackInit(&st, 10);
	StackPush(&st, right);
	StackPush(&st, left);
	while (StackEmpty(&st) != 0)
	{
		int left = StackTop(&st);
		StackPop(&st);
		int right = StackTop(&st);
		StackPop(&st);

		int div = PartSort(a, left, right);
		if (left < div - 1)
		{
			StackPush(&st, div - 1);
			StackPush(&st, left);
		}
		if (div + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, div + 1);
		}
	}
}


void QuickSortTest()
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37, 28 };
	int sz = sizeof(a) / sizeof(a[0]);
	QuickSort(a, 0, sz - 1);
	PrintArr(a, sz);
}


void QuickSortRTest()
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37, 28 };
	int sz = sizeof(a) / sizeof(a[0]);
	QuickSortR(a, 0, sz - 1);
	PrintArr(a, sz);
}

void _MergeSort(int* a, int* tmp, int left, int right)
{
	if (left >= right)
		return;

	int mid = left + ((right - left) >> 1);
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
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	memcpy(a + left, tmp + left, sizeof(int)*(right - left + 1));
}

void MergeSort(int* a, int n)
{
	assert(a);
	int *tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, tmp, 0, n - 1);
	free(tmp);
}

void MergrSortTest()
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37, 28 };
	int sz = sizeof(a) / sizeof(a[0]);
	MergeSort(a, sz);
	PrintArr(a, sz);
}





void SortTest()
{
	printf("插入排序-> ");
	InsertSortTest();

	printf("希尔排序-> ");
	ShellSortTest();

	printf("选择排序-> ");
	SelectSortTest();

	printf("大堆排序-> ");
	HeapSortTest();

	printf("冒泡排序-> ");
	BubbleSortTest();

	printf("快速排序-> ");
	QuickSortTest();

	printf("快速排序-> ");
	QuickSortRTest();

	printf("归并排序-> ");
	MergrSortTest();
}