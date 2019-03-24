#include "ThreadCache.h"
#include "CentralCache.h"


//�����Ļ����ȡ����
void* ThreadCache::FetchFromCentralCache(size_t index, size_t size)
{
	//��׮
	//return malloc(size);

	//��׮
	//size_t numtomove = 5;
	//void* start = nullptr, *end = nullptr;
	//size_t batchsize = CentralCache::Getinstance()->FetchRangeObj(start, end, numtomove, size);

	//if (batchsize > 1)
	//{
	//	Freelist* freelist = &_freelist[index];
	//	freelist->PushRange(NEXT_OBJ(start), end, batchsize - 1);
	//}
	//return start;

	Freelist* freelist = &_freelist[index];
	size_t maxsize = freelist->MaxSize();
	size_t numtomove = min(SizeClass::NumMoveSize(size), maxsize);

	void* start = nullptr, *end = nullptr;
	size_t batchsize = CentralCache::Getinstance()->FetchRangeObj(start, end, numtomove, size);

	if (batchsize > 1)
	{
		freelist->PushRange(NEXT_OBJ(start), end, batchsize - 1);
	}

	if (batchsize >= freelist->MaxSize())
	{
		freelist->SetMaxSize(maxsize + 1);
	}

	return start;
}

//�ͷŶ���ʱ���������ʱ�������ڴ�ص����Ļ���
void ThreadCache::ListTooLong(Freelist* freelist, size_t size)
{
	//��׮
	//return nullptr;
	void* start = freelist->PopRange();
	CentralCache::Getinstance()->ReleaseListToSpans(start, size);
}

//������ͷ��ڴ����
void* ThreadCache::Allocate(size_t size)
{
	size_t index = SizeClass::Index(size);//��ȡ�����Ӧ��λ��
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
	size_t index = SizeClass::Index(size);
	Freelist* freelist = &_freelist[index];
	freelist->Push(ptr);

	//����ĳ������ʱ(�ͷŻ�һ�������Ķ���)���ͷŻ����Ļ���
	if (freelist->Size() >= freelist->MaxSize())
	{
		ListTooLong(freelist, size);
	}
}