#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct BTNode
{
	struct BTNode* _left;
	struct BTNode* _right;
	char _data;
}BTNode;

BTNode* GreateTree(char* str, int* pi)
{
	if (str[*pi] != '#')
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = str[*pi];
		++(*pi);
		root->_left = GreateTree(str, pi);
		++(*pi);
		root->_right = GreateTree(str, pi);

		return root;
	}
	else
	{
		return NULL;
	}
}


void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		InOrder(root->_left);
		printf("%c ", root->_data);
		InOrder(root->_right);
	}
}

int main()
{
	int i = 0;
	char str[100] = { 0 };
	scanf("%s", str);
	BTNode* tree = GreateTree(str, &i);
	InOrder(tree);
	return 0;
}