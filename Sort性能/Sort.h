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

//ֱ�Ӳ�������
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
	printf("����=>");
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

//ϣ������
void ShellSort(int *a, int n)
{
	assert(a);
	int gap = n;
	while (gap > 1)
	{
		//Ԥ����
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
	printf("ϣ��=>");
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}


void Swap(int *p1, int *p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//ѡ������
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

		if (begin == max)//ע�����潻����ʱ����������ͬ�Ļ����ϣ����max����������λ�ã��������ǿ��ܻ�����Ϊ����begin��λ��
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
	printf("ѡ��=>");
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}


//������
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
	//����,���µ�������
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
	printf("����=>");
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}


//ð��
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
	printf("ð��=>");
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

//��������
//����ȡ��
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

//��������
//hoare�汾
int PartSort1(int *a, int begin, int end)
{
	assert(a);

	int mindindex = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[mindindex]);

	int key = a[begin];
	int start = begin;
	while (begin < end)
	{
		//end ��С
		while (begin < end && a[end] >= key)
			--end;

		//begin �Ҵ�
		while (begin < end && a[begin] <= key)
			++begin;

		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[start]);

	return begin;
}

//�ڿӷ�
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

//ǰ��ָ��汾
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

//�ݹ��㷨
void  QuickSort(int *a, int left, int right)
{
	assert(a);
	if (left >= right)
		return;

	//С�����Ż�
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

//�ǵݹ�
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
	printf("����=>");
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestQuickSortR()
{
	int a[] = { 4, 2, 1, 6, 7, 3, 4, 9, 8, 0 };
	QuickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	printf("����=>");
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}



//�鲢
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
	printf("�鲢=>");
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}


//����
void CountSort(int* a, int n)
{
	//ͳ�Ƹ�������Χ��С�����ļ���С��
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

	//ͳ�Ƹ���
	for (int i = 0; i < n; ++i)
		count[a[i] - min]++;

	int index = 0;
	for (int i = 0; i < range; ++i)
	{
		while (count[i]--)
		{
			a[index++] = i + min;//���λ��,��Ȼ�����һ������0�Ļ����ͻ��λ
		}
	}
}

void TestCountSort()
{
	int a[] = { 4, 2, 1, 6, 7, 3, 4, 9, 8, 0};
	CountSort(a, sizeof(a) / sizeof(a[0]));
	printf("����=>");
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
	printf("����-> %u\n", end1 - begin1);

	size_t begin2 = clock();
	ShellSort(a2, n);
	size_t end2 = clock();
	printf("ϣ��-> %u\n", end2 - begin2);

	size_t begin3 = clock();
	//SelectSort(a3, n);
	size_t end3 = clock();
	printf("ѡ��-> %u\n", end3 - begin3);

	size_t begin4 = clock();
	HeapSort(a4, n);
	size_t end4 = clock();
	printf("����-> %u\n", end4 - begin4);

	size_t begin5 = clock();
	//BubbleSort(a5, n);
	size_t end5 = clock();
	printf("ð��-> %u\n", end5 - begin5);

	size_t begin6 = clock();
	//QuickSort(a6, 0, n);
	size_t end6 = clock();
	printf("����-> %u\n", end6 - begin6);

	size_t begin7 = clock();
	MergeSort(a7, n);
	size_t end7 = clock();
	printf("�鲢-> %u\n", end7 - begin7);

	size_t begin8 = clock();
	CountSort(a8, n);
	size_t end8 = clock();
	printf("����-> %u\n", end8 - begin8);
}