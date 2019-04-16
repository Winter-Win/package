#include "Stack.h"

void StackInit(Stack* ps, int n)
{
	assert(ps);
	ps->_data = (STDataType*)malloc(sizeof(STDataType)*n);//开辟空间，初始化。数组实现
	ps->_top = 0;
	ps->_capacity = n;
}

void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_data);
	ps->_data = NULL;
	ps->_top = ps->_capacity = 0;
}

void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		ps->_data = (STDataType*)realloc(ps->_data, ps->_capacity * 2 * sizeof(STDataType));
		ps->_capacity *= 2;
	}
	ps->_data[ps->_top] = x;
	ps->_top++;
}

void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->_top > 0)
	{
		ps->_top--;
	}
}

STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_data[ps->_top - 1];
}

int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

//空0  非空1
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}

void StackTest()
{
	Stack s1;
	StackInit(&s1, 3);
	StackPush(&s1, 1);
	StackPush(&s1, 2);
	StackPush(&s1, 3);
	printf("front:%d\n", StackTop(&s1));
	StackPop(&s1);
	StackPush(&s1, 4);

	while (StackEmpty(&s1))
	{
		printf("front:%d\n", StackTop(&s1));
		StackPop(&s1);
	}

	StackDestroy(&s1);
}