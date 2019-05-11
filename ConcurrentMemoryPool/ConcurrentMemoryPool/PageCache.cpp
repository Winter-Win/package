#include "PageCache.h"

PageCache PageCache::_inst;

Span* PageCache::NewSpan(size_t n)
{
	assert(n < NPAGES);
	if (!_spanlist[n].Empty())
	{
		return _spanlist[n].PopFront();
	}

	for (size_t i = n+1; i < NPAGES; ++i)
	{
		if (!_spanlist[i].Empty())
		{
			Span* span = _spanlist[i].PopFront();
			Span* split = new Span;

			split->_pageid = span->_pageid;
			split->_npage = n;
			span->_pageid = span->_pageid + n;
			span->_npage = span->_npage - n;

			for (size_t i = 0; i < n; ++i)
			{
				_idspanmap[split->_pageid + i] = split;
			}

			_spanlist[span->_npage].PushFront(span);
			return split;
		}
	}

	Span* span = new Span;
	void* ptr = VirtualAlloc(0, (NPAGES - 1)*(1 << PAGE_SHIFT),
		MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	span->_pageid = (PageID)ptr >> PAGE_SHIFT;
	span->_npage = NPAGES - 1;

	for (size_t i = 0; i < span->_npage; ++i)
	{
		_idspanmap[span->_pageid+i] = span;
	}

	_spanlist[span->_npage].PushFront(span);
	return NewSpan(n);
}

// ��ȡ�Ӷ���span��ӳ��
Span* PageCache::MapObjectToSpan(void* obj)
{
	PageID id = (PageID)obj >> PAGE_SHIFT;
	auto it = _idspanmap.find(id);
	if (it != _idspanmap.end())
	{
		return it->second;
	}
	else
	{
		assert(false);
		return nullptr;
	}
}

void PageCache::ReleaseSpanToPageCahce(Span* cur)
{
	// ��ǰ�ϲ�
	while (1)
	{
		PageID curid = cur->_pageid;
		PageID previd = curid - 1;
		auto it = _idspanmap.find(previd);

		// û���ҵ�
		if (it == _idspanmap.end())
			break;

		// ǰһ��span������
		if (it->second->_usecount != 0)
			break;

		Span* prev = it->second;
		// �Ȱ�prev���������Ƴ�
		_spanlist[prev->_npage].Erase(prev);

		// �ϲ�
		prev->_npage += cur->_npage;
		delete cur;

		// ������ǰ�ϲ�
		cur = prev;
	}

	//while (1)
	//{
	//	PageID curid = cur->_pageid;
	//	PageID nextid = curid + 1;
	//	auto it = _idspanmap.find(nextid);
	//}

	_spanlist[cur->_npage].PushFront(cur);

	// 
}