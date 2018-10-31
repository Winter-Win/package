#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void SListInit(SList* plist)//初始化
{
	assert(plist);
	plist->_head = plist->_tail = NULL;

}

void SListDestroy(SList* plist)//开辟空间
{
	SListNode* cur;
	assert(plist);

	cur = plist->_head;
	while (cur != NULL)
	{
		SListNode* next = cur->_next;
		free(cur);

		cur = next;
	}
	plist->_head = plist->_tail = NULL;
}

SListNode* BuySListNode(SLTDataType x)//创建一个节点
{
	SListNode* node = malloc(sizeof(SListNode));
	assert(node);
	node->_data = x;
	node->_next = NULL;

	return node;
}

void SListPushBack(SList* plist, SLTDataType x)//尾插
{
	SListNode* tail;
	assert(plist);
	//1.一个节点都没有
	//2.一个以上节点
	if (plist->_head == NULL)
	{
		plist->_head = BuySListNode(x);
	}
	else
	{
		tail = plist->_head;
		while (tail->_next)
		{
			tail = tail->_next;
		}
		tail->_next = BuySListNode(x);
	}
}

void SListPophBack(SList* plist)//尾删
{
	SListNode* prev, *tail;
	assert(plist);

	prev = NULL;
	tail = plist->_head;

	if (tail->_next == NULL)
	{
		free(tail);
		plist->_head = NULL;
	}
	else
	{
		while (tail->_next)
		{
			prev = tail;
			tail = tail->_next;
		}
		free(tail);
		prev->_next = NULL;
	}
}

void SListPushFront(SList* plist, SLTDataType x)//头插
{
	SListNode* newnode;
	assert(plist);

	newnode = BuySListNode(x);
	newnode->_next = plist->_head;
	plist->_head = newnode;
}

void SListPopFront(SList* plist)//头删
{
	SListNode* next;
	assert(plist);

	next = plist->_head->_next;
	free(plist->_head);
	plist->_head = next;
}

SListNode* SListFind(SList* plist, SLTDataType x)//查找
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return cur;
}

//在pos的后面进行插入
void SListInsertAfter(SList* plist, SListNode* pos, SLTDataType x)
{
	SListNode* next, *newnode;
	assert(pos);

	next = pos->_next;
	newnode = BuySListNode(x);
	pos->_next = newnode;
	newnode->_next = next;
}

//删除pos后面的节点
void SListEraseAfter(SList* plist,SListNode* pos)
{
	SListNode* next;
	assert(pos);
	if (pos->_next == NULL)
	{
		return;
	}
	next = pos->_next;
	pos->_next = next->_next;
	free(next);
	next = NULL;
}

//删除指定数值
void SListRemove(SList* plist, SLTDataType x)
{
	assert(plist);
	if (plist->_head->_data == x)
	{
		SListPopFront(plist);
			return;
	}
	SListNode* prev =NULL ;
	SListNode*cur = plist->_head;
	while (cur)
	{
		if (cur->_data == x)
		{
			prev->_next = cur->_next;
			free(cur);
			cur = NULL;
			break;
		}
		else
		{
			prev = cur;
			cur = cur->_next;
		}
	}
}

void SListPrint(SList* plist)
{
	SListNode* cur = plist->_head;
	while (cur != plist->_tail)
	{
		printf("%d -> ", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}

void TestSlist()
{
	SList sl;
	SListInit(&sl);

	SListPushBack(&sl, 1);
	SListPushBack(&sl, 2);
	SListPushBack(&sl, 3);
	SListPushBack(&sl, 4);
	SListPrint(&sl);

	SListPophBack(&sl);
	SListPophBack(&sl);
	SListPrint(&sl);

	SListPushFront(&sl, 5);
	SListPushFront(&sl, 6);
	SListPushFront(&sl, 7);
	SListPushFront(&sl, 8);
	SListPrint(&sl);

	SListPopFront(&sl);
	SListPopFront(&sl);
	SListPrint(&sl);

	SListNode* pos = SListFind(&sl, 1);
	SListInsertAfter(&sl, pos, 20);
	SListPrint(&sl);

	SListEraseAfter(&sl,pos);
	SListPrint(&sl);

	SListRemove(&sl, 5);
	SListRemove(&sl, 20);
	SListRemove(&sl, 30);
	SListPrint(&sl);

	SListDestroy(&sl);
}