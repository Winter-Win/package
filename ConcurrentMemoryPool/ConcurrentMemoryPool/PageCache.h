#include "Common.h"

class PageCache
{
public:
	static PageCache* GetInstance()
	{
		return &_inst;
	}

	Span* NewSpan(size_t n);

	// ��ȡ�Ӷ���span��ӳ��
	Span* MapObjectToSpan(void* obj);

	// �ͷſ���span�ص�Pagecache�����ϲ����ڵ�span
	void ReleaseSpanToPageCahce(Span* span);
private:
	SpanList _spanlist[NPAGES];
	std::map<PageID, Span*> _idspanmap;
private:
	PageCache()
	{}

	PageCache(const PageCache&) = delete;

	static PageCache _inst;
};