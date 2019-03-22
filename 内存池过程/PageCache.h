#include "Common.h"

//单例模式
class PageCache
{
public:
	static PageCache* GetInstence()
	{
		return &_inst;
	}

	Span* NewSpan(size_t n);//获取的是以页为单位

	//获取从对象到span的映射
	Span* MapObjectToSpan(void* obj);

	//释放空间span回到PageCache，并合并相邻的span
	void ReleaseSpanToPageCache(Span* span);

private:
	SpanList _spanlist[NPAGES];
	std::map<PageID, Span*> _idspanmap;
private:
	PageCache(){}

	PageCache(const PageCache&) = delete;
	static PageCache _inst;
};