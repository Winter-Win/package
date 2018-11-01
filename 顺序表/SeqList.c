#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"


void CheckCapacity(SeqList* psl)
{
	SLDataType* tmp;
	if (psl->_size == psl->_capacity)
	{
		if (psl->_capacity == 0)
		{
			psl->_capacity = 2;
		}
		else
		{
			tmp = realloc(psl->_a, psl->_capacity * 2 * sizeof(SLDataType));
			assert(tmp);
			psl->_a = tmp;
			psl->_capacity *= 2;
		}
		
	}
}



void SeqListInit(SeqList* psl, size_t capacity)//����,��ʼ��
{
	assert(psl);
	if (capacity == 0)
	{
		psl->_a = NULL; 
		psl->_capacity = 0;
		psl->_size = 0;
	}
	else
	{
		psl->_capacity = capacity;
		psl->_size = 0;
		psl->_a = (SLDataType*)malloc(sizeof(SLDataType)*capacity);
		assert(psl->_a);
	}
}


void SeqListDestory(SeqList* psl)//����
{
	assert(psl);
	free(psl->_a);
	psl->_a = NULL;
	psl->_size = psl->_capacity = 0;
}


void SeqListPushBack(SeqList* psl, SLDataType x)//β��
{
	//ֱ��ʵ��
	/*assert(psl);
	CheckCapacity(psl);

	psl->_a[psl->_size] = x;
	psl->_size++;*/

	SeqListInsert(psl, psl->_size, x);
}



void SeqListPopBack(SeqList* psl)//βɾ
{
	/*assert(psl);
	if (psl->_size > 0)
	{
		psl->_size--;
	}*/

	SeqListErase(psl, psl->_size - 1);

}


void SeqListPushFront(SeqList* psl, SLDataType x)//ͷ��
{
	int end;
	assert(psl);
	CheckCapacity(psl);

	end = psl->_size;
	while (end >= 1)
	{
		psl->_a[end] = psl->_a[end-1];//ע������������Խ�����
		--end;
	}
	psl->_a[0] = x;
	psl->_size++;

	//SeqListInsert(psl, 0, x);
}



void SeqListPopFront(SeqList* psl)//ͷɾ
{
	//ֱ��ɾ��
	/*assert(psl);
	if (psl->_size > 0)
	{
		rsize_t start = 0;
		while (start < psl->_size-1)
		{
			psl->_a[start] = psl->_a[start + 1];
			start++;
		}
		psl->_size--;
	}*/

	SeqListErase(psl, 0);

}


int SeqListFind(SeqList* psl, SLDataType x) // O(N)  ����x��λ��
{
	size_t i = 0;
	assert(psl);
	for (i = 0; i < psl->_size; i++)
	{
		if (psl->_a[i] == x)
		{
			return i;
		}
	}
	return -1;
}



void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)//����λ�ò���
{
	int end;
	assert(psl&&pos <= psl->_size);
	end = psl->_size - 1;
	CheckCapacity(psl);

	while (end >= (int)pos)
	{
		psl->_a[end + 1] = psl->_a[end];
		end--;
	}
	psl->_a[pos] = x;
	psl->_size++;
}



void SeqListErase(SeqList* psl, size_t pos)//����λ��ɾ��
{
	size_t start;
	assert(psl && pos < psl->_size);

	start = pos;
	while (start<psl->_size-1)
	{
		psl->_a[start] = psl->_a[start + 1];
		start++;
	}
	psl->_size--;
}

//ɾ��ָ����
void SeqListRemove(SeqList* psl, SLDataType x)
{
	int pos;
	assert(psl);
	pos = SeqListFind(psl, x);
	if (pos != -1)
	{
		SeqListErase(psl, pos);
	}
}

void SeqListModify(SeqList* psl, size_t pos, SLDataType x)//�޸�ĳ��λ��(�±�)�ϵ�����
{
	assert(psl&&pos<psl->_size);
	psl->_a[pos] = x;
}


void SeqListPrint(SeqList* psl)
{
	size_t i = 0;
	assert(psl);
	for (i = 0; i < psl->_size; i++)
	{
		printf("%d ", psl->_a[i]);
	}
	printf("\n");
}

void SeqListBubbleSort(SeqList* psl)//ð������
{
	assert(psl);
	size_t i = 0;
	size_t j = 0;
	for (i = 0; i < psl->_size - 1; i++)
	{
		int flag = 0;
		for (j = 0; j < psl->_size - 1 - i; j++)
		{
			if (psl->_a[j]>psl->_a[j + 1])
			{
				SLDataType tmp = psl->_a[j + 1];
				psl->_a[j + 1] = psl->_a[j];
				psl->_a[j] = tmp;
				flag = 1;
			}
		}
		if (0 == flag)
		{
			return;
		}
	}
}

int BinarySearch(SeqList* psl, SLDataType x)//���ֲ���
{
	assert(psl);
	int left = 0;
	int right = psl->_size - 1;
	while (left <= right)
	{
		SLDataType mid = left + (right - left);
		if (psl->_a[mid] < x)
		{
			left = mid + 1;
		}
		else if (psl->_a[mid] > x)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return 0;
}

void SeqListRemoveAll(SeqList* psl, SLDataType x)//Ҫ��ʱ�临�Ӷ���O(N) �ռ临�Ӷ�O(1)
{
	assert(psl);
	SLDataType ret = 0;
	size_t i = 0;
	while (i < psl->_size - 1)
	{
		ret = SeqListFind(psl, x);
		if (ret != -1)
		{
			SeqListRemove(psl, x);
		}
		i++;
	}
}


void TestSeqList()
{
	SeqList sl;
	SeqListInit(&sl, 10);

	SeqListPushBack(&sl, 0);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPrint(&sl);

	SeqListPushFront(&sl, 5);
	SeqListPushFront(&sl, 6);
	SeqListPushFront(&sl, 7);
	SeqListPushFront(&sl, 8);
	SeqListPushFront(&sl, 9);

	SeqListPrint(&sl);

    SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPrint(&sl);
	
	SeqListInsert(&sl, 3, 30);
	SeqListPrint(&sl);
	SeqListInsert(&sl, 3, 300);
	SeqListPrint(&sl);

	SeqListErase(&sl, 0);
	SeqListPrint(&sl);
	SeqListErase(&sl, 1);
	SeqListPrint(&sl);

	SeqListRemove(&sl,300);
	SeqListPrint(&sl);

	SeqListModify(&sl, 2, 100);
	SeqListPrint(&sl);

	SeqListBubbleSort(&sl);
	SeqListPrint(&sl);

	SeqListDestory(&sl);
}