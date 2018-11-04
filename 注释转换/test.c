#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include "CommentConvert.h"

void test()
{
	FILE* pfRead = NULL;
	FILE* pfWrite = NULL;
	//打开input.c文件
	pfRead = fopen("input.c", "r");
	if (pfRead == NULL)
	{
		perror("open file for read");
		exit(EXIT_FAILURE);
	}
	//写入output.c文件
	pfWrite = fopen("output.c", "w");
	if (pfWrite == NULL)
	{
		perror("open file for write");
		fclose(pfRead);
		pfRead = NULL;
		exit(EXIT_FAILURE);
	}
	//注释转换
	CommentConvert(pfRead, pfWrite);//状态转换机

	printf("转换完成\n");
	fclose(pfRead);
	fclose(pfWrite);
	pfRead = NULL;
	pfWrite = NULL;
}

int main()
{
	test();
	system("pause");
	return 0;
}