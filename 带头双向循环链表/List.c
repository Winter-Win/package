#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	assert(node);
	node->_data = x;
	node->_next = NULL;
	node->_prev = NULL;

	return node;
}

void ListInit(List* plist)
{
	assert(plist);
	plist->_head = BuyListNode(0);
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}

void ListDestroy(List* plist)
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
	while (cur!=plist->_head)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(plist->_head);
	plist->_head = NULL;
}

void ListPushBack(List* plist, LTDataType x)
{
	assert(plist);
	/*ListNode* head = plist->_head;

	ListNode* tail = head->_prev;
	ListNode* newnode = BuyListNode(x);

	tail->_next = newnode;
	newnode->_prev = tail;
	newnode->_next = head;
	head->_prev = newnode;*/

	ListInsert(plist->_head, x);
}

void ListPopback(List* plist)
{
	assert(plist);
	/*ListNode* head = plist->_head;
	ListNode* tail = head->_prev;
	ListNode* prev = tail->_prev;

	prev->_next = head;
	head->_prev = prev;

	free(tail);*/

	ListErase(plist->_head->_prev);
}

void ListPushFront(List* plist, LTDataType x)
{
	assert(plist);
	/*ListNode* head = plist->_head;
	ListNode* next = head->_next;
	ListNode* newnode = BuyListNode(x);

	head->_next = newnode;
	newnode->_prev = head;
	newnode->_next = next;
	next->_prev = newnode;*/

	ListInsert(plist->_head->_next, x);
}

void ListPopFront(List* plist)
{
	assert(plist);
	/*ListNode* head = plist->_head;
	ListNode* next = head->_next;
	ListNode* nextnext = next->_next;

	if (head == next)
	{
		return;
	}

	head->_next = nextnext;
	nextnext->_prev = head;
	free(next);
	next = NULL;*/

	ListErase(plist->_head->_next);
}

void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* newnode = BuyListNode(x);

	prev->_next = newnode;
	newnode->_prev = prev;
	newnode->_next = pos;
	pos->_prev = newnode;
}

void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;

	prev->_next = next;
	next->_prev = prev;
	free(pos);
	pos = NULL;
}

ListNode* ListFind(List* plist, LTDataType x)
{
	assert(plist); 
	ListNode* cur = plist->_head->_next;
	while (cur!=plist->_head)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->_next;
		}
	}
	return NULL;
}

void ListPrint(List* plist)
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
	while (cur!=plist->_head)
	{
		printf("%d<=>", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void ListTest()
{
	List lt;
	ListInit(&lt);
	ListPushBack(&lt, 1);
	ListPushBack(&lt, 2);
	ListPushBack(&lt, 3);
	ListPushBack(&lt, 4);
	ListPrint(&lt);

	ListPopback(&lt);
	ListPopback(&lt);
	ListPrint(&lt);

	ListPushFront(&lt, 1);
	ListPushFront(&lt, 2);
	ListPushFront(&lt, 3);
	ListPushFront(&lt, 4);
	ListPrint(&lt);

	ListPopFront(&lt);
	ListPopFront(&lt);
	ListPrint(&lt);

	ListDestroy(&lt);
}