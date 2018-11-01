#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* _a;	   // 数组
	size_t _size;	   // 有多少个有效数据
	size_t _capacity;  // 容量
}SeqList;



void CheckCapacity(SeqList* psl);
void SeqListInit(SeqList* psl, size_t capacity);
void SeqListDestory(SeqList* psl);

void SeqListPushBack(SeqList* psl, SLDataType x);
void SeqListPopBack(SeqList* psl);
void SeqListPushFront(SeqList* psl, SLDataType x);
void SeqListPopFront(SeqList* psl);

int SeqListFind(SeqList* psl, SLDataType x); // O(N)
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
void SeqListErase(SeqList* psl, size_t pos);
void SeqListRemove(SeqList* psl, SLDataType x);
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);

void SeqListBubbleSort(SeqList* psl);
int BinarySearch(SeqList* psl, SLDataType x);
void SeqListRemoveAll(SeqList* psl, SLDataType x);

void SeqListPrint(SeqList* psl);
void TestSeqList();

#endif   //__SEQLIST_H__