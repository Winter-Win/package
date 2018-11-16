#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct Stu
{
	char name[20];
	int age;
};

void print_arr(int *arr, size_t sz)
{
	unsigned int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

int cmp_int(const void *e1, const void *e2)
{
	return *(int *)e1 - *(int *)e2;
}

int cmp_stu_by_age(const void *e1, const void *e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

int cmp_stu_by_name(const void *e1, const void *e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}

int cmp_str(const void* e1, const void* e2)
{
	return strcmp(*(char**)e1, *(char **)e2);
}

void _Swap(char *buf1, char *buf2, size_t width)
{
	unsigned int i = 0;
	assert(buf1&&buf2);
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

void bubble_sort(void *base, int num, int width, int(*cmp)(const void*e1, const void*e2))
{
	int i = 0;
	int j = 0;
	assert(base&&cmp);
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - 1 - i; j++)
		{
			if (cmp((char*)base + j*width, (char*)base + (j + 1)*width)>0)
			{
				//交换
				_Swap((char*)base + j*width, (char*)base + (j + 1)*width, width);
			}
		}
	}
}

int main()
{
	////利用qsort测试整型排序
	//int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//qsort(arr, sz, sizeof(arr[0]), cmp_int);
	//print_arr(arr, sz);
	//
	////利用qsort测试结构体排序
	//struct Stu arr[] = { { "zhangsan", 20 }, { "lisi", 15 }, { "wangwu", 8 } };
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//qsort(arr, sz, sizeof(arr[0]), cmp_stu_by_age);
	//qsort(arr, sz, sizeof(arr[0]), cmp_stu_by_name);

	////利用bubble_qsort测试结构体排序
	//struct Stu arr[] = { { "zhangsan", 20 }, { "lisi", 15 }, { "wangwu", 8 } };
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//bubble_sort(arr, sz, sizeof(arr[0]), cmp_stu_by_name);

	////利用bubble_qsort测试字符串排序
	//char *arr[] = { "abcdef", "qqqqq", "bbbbbb" };
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//bubble_sort(arr, sz, sizeof(arr[0]), cmp_str);

	system("pause");
	return 0;
}