//#pragma once   //windows vs

#ifndef __SLIST_H__
#define __SLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;

typedef struct SList
{
	SListNode* _head;
	SListNode* _tail;
}SList;

void SListInit(SList* plist);
void SListDestroy(SList* plist);

void SListPushBack(SList* plist, SLTDataType x);
void SListPophBack(SList* plist);
void SListPushFront(SList* plist, SLTDataType x);
void SListPopFront(SList* plist);

SListNode* SListFind(SList* plist, SLTDataType x);
//在pos的后面进行插入
void SListInsertAfter(SList* plist, SListNode* pos, SLTDataType x);
//void SListEraseAfter(SListNode* pos);
void SListEraseAfter(SList* plist, SListNode* pos);

void SListRemove(SList* plist, SLTDataType x);
void SListPrint(SList* plist);
void TestSlist();


#endif   //__SLIST_H__
