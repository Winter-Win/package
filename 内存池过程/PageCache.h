#include "Common.h"

//����ģʽ
class PageCache
{
public:
	static PageCache* GetInstence()
	{
		return &_inst;
	}

	Span* NewSpan(size_t n);//��ȡ������ҳΪ��λ

	//��ȡ�Ӷ���span��ӳ��
	Span* MapObjectToSpan(void* obj);

	//�ͷſռ�span�ص�PageCache�����ϲ����ڵ�span
	void ReleaseSpanToPageCache(Span* span);

private:
	SpanList _spanlist[NPAGES];
	std::map<PageID, Span*> _idspanmap;
private:
	PageCache(){}

	PageCache(const PageCache&) = delete;
	static PageCache _inst;
};