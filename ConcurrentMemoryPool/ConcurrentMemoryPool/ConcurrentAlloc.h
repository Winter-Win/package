#pragma once

#include "Common.h"
#include "ThreadCache.h"

//�������ã��ĸ��߳�����֮����Ҫ�ڴ�͵�������ӿ�
void* ConcurrentAlloc(size_t size)
{
	if (size > MAX_BYTES)//����һ�����ֵ�����Լ���ϵͳ�л�ȡ������ʹ���ڴ��
	{
		return malloc(size);
	}
	else
	{
		if (tlslist == nullptr)//��һ�������Լ��������������ģ��Ϳ���ֱ��ʹ�õ�ǰ�����õ��ڴ��
		{
			tlslist = new ThreadCache;
		}

		return tlslist->Allocate(size);
	}
}

void ConcurrentFree(void* ptr, size_t size)//����ͷ�
{
	if (size > MAX_BYTES)
	{
		free(ptr);
	}
	else
	{
		tlslist->Deallocate(ptr, size);
	}
}