#pragma once

#include "common.h"


typedef struct BTNode* STDataType;

typedef struct Stack
{
	STDataType* _a;
	int _top; // Õ»¶¥
	int _capacity; // ÈÝÁ¿
}Stack;

void StackInit(Stack* ps, int n);
void StackDestory(Stack* ps);

void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);

STDataType StackTop(Stack* ps);

int StackSize(Stack* ps);
//¿Õ0  ·Ç¿Õ1
int StackEmpty(Stack* ps);

void TestStack();



