#include "ThreadCache.h"
#include "CentralCache.h"

void* ThreadCache::FetchFromCentralCache(size_t index, size_t size)
{
	//打桩
	//return malloc(size);

	//打桩
	size_t numtomove = 5;
	void* start = nullptr, *end = nullptr;
	size_t batchsize = CentralCache::Getinstance()->FetchRangeObj(start, end, numtomove, size);

	if (batchsize > 1)
	{
		Freelist* freelist = &_freelist[index];
		freelist->PushRange(NEXT_OBJ(start), end, batchsize - 1);
	}
	return start;
}

//释放对象时，链表过长时，回收内存回到中心堆
void* ThreadCache::ListTooLong(Freelist* list, size_t size)
{
	return nullptr;
}

//申请和释放内存对象
void* ThreadCache::Allocate(size_t size)
{
	size_t index = 0;//获取到相对应的位置
	Freelist* freelist = &_freelist[index];
	if (!freelist->Empty())//在ThreadCache处不为空的话，直接取
	{
		return freelist->Pop();
	}
	else
	{//否则的话，从中心缓存处获取
		return FetchFromCentralCache(index, SizeClass::Roundup(size));
	}
}

void ThreadCache::Deallocate(void* ptr, size_t size)
{
	size_t index = 0;
	Freelist* freelist = &_freelist[index];
	freelist->Push(ptr);

	//满足某个条件时，释放回中心缓存

}