#include "ThreadCache.h"
#include "CentralCache.h"

void* ThreadCache::FetchFromCentralCache(size_t index, size_t size)
{
	//��׮
	//return malloc(size);

	//��׮
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

//�ͷŶ���ʱ���������ʱ�������ڴ�ص����Ķ�
void* ThreadCache::ListTooLong(Freelist* list, size_t size)
{
	return nullptr;
}

//������ͷ��ڴ����
void* ThreadCache::Allocate(size_t size)
{
	size_t index = 0;//��ȡ�����Ӧ��λ��
	Freelist* freelist = &_freelist[index];
	if (!freelist->Empty())//��ThreadCache����Ϊ�յĻ���ֱ��ȡ
	{
		return freelist->Pop();
	}
	else
	{//����Ļ��������Ļ��洦��ȡ
		return FetchFromCentralCache(index, SizeClass::Roundup(size));
	}
}

void ThreadCache::Deallocate(void* ptr, size_t size)
{
	size_t index = 0;
	Freelist* freelist = &_freelist[index];
	freelist->Push(ptr);

	//����ĳ������ʱ���ͷŻ����Ļ���

}