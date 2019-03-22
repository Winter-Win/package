#pragma once

#include "Common.h"
#include "ThreadCache.h"

//被动调用，哪个线程来了之后，需要内存就调用这个接口
void* ConcurrentAlloc(size_t size)
{
	if (size > MAX_BYTES)//超过一个最大值，就自己从系统中获取，否则使用内存池
	{
		return malloc(size);
	}
	else
	{
		if (tlslist == nullptr)//第一次来，自己创建，后面来的，就可以直接使用当前创建好的内存池
		{
			tlslist = new ThreadCache;
		}

		return tlslist->Allocate(size);
	}
}

void ConcurrentFree(void* ptr, size_t size)//最后释放
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