#define _CRT_SECURE_NO_WARNINGS 1

#include "BinaryTree.h"
#include "Queue.h"
#include "Stack.h"

BTNode* BuyBTNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->_data = x;
	node->_left = NULL;
	node->_right = NULL;

	return node;
}

BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] != '#')
	{
		BTNode* root = BuyBTNode(a[*pi]);
		++(*pi);
		root->_left = BinaryTreeCreate(a, pi);
		++(*pi);
		root->_right = BinaryTreeCreate(a, pi);

		return root;
	}
	else
	{
		return NULL;
	}
}

void BinaryTreeDestory(BTNode* root)//销毁
{
	free(root);
	root->_left = NULL;
	root->_right = NULL;
}

int BinaryTreeSize(BTNode* root)//节点数
{
	if (root == NULL)
		return 0;
	else
		return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)//叶子节点数
{
	if (root == NULL)
		return 0;

	if (root->_left == NULL && root->_right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)//第K层节点数
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BinaryTreeLevelKSize(root->_left, k - 1) 
		+ BinaryTreeLevelKSize(root->_right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode* ret;
	if (root == NULL)
		return NULL;

	if (root->_data == x)
		return root;

	ret = BinaryTreeFind(root->_left, x);
	if (ret)
		return ret;
	
	ret = BinaryTreeFind(root->_right, x);
	if (ret)
		return ret;
	else
		return NULL;
}

void _BinaryTreePrevOrder(BTNode* root, int* array, int* pi)
{
	if (root == NULL)
		return;

	printf("%c ", root->_data);
	(*pi)++;
	_BinaryTreePrevOrder(root->_left, array, pi);
	_BinaryTreePrevOrder(root->_right, array, pi);
}

void BinaryTreePrevOrder(BTNode* root)//前序遍历
{
	if (root == NULL)
		return;

	int* array = (int*)malloc(BinaryTreeSize(root)*sizeof(int));
	
	int i = 0;
	_BinaryTreePrevOrder(root, array, &i);
}


void _BinaryTreeInOrder(BTNode* root, int* array, int* pi)
{
	if (root == NULL)
		return;

	_BinaryTreeInOrder(root->_left, array, pi);

	printf("%c ", root->_data);
	(*pi)++;

	_BinaryTreeInOrder(root->_right, array, pi);
}

void BinaryTreeInOrder(BTNode* root)//中序遍历
{
	if (root == NULL)
		return;

	int *array = (int*)malloc(BinaryTreeSize(root)*sizeof(int));

	int i = 0;
	_BinaryTreeInOrder(root, array, &i);
}

void _BinaryTreePostOrder(BTNode* root, int* array, int* pi)
{
	if (root == NULL)
		return;

	_BinaryTreePostOrder(root->_left, array, pi);

	_BinaryTreePostOrder(root->_right, array, pi);

	printf("%c ", root->_data);
	(*pi)++;
}

void BinaryTreePostOrder(BTNode* root)//后序遍历
{
	if (root == NULL)
		return;

	int *array = (int*)malloc(BinaryTreeSize(root)*sizeof(int));

	int i = 0;
	_BinaryTreePostOrder(root, array, &i);
}

void BinaryTreeLevelOrder(BTNode* root)//层序遍历
{
	Queue q;
	QueueInit(&q);

	if (root != NULL)
	{
		QueuePush(&q, root);//先把跟放进去
		while (QueueEmpty(&q))//当队列里面为空的时候就结束
		{
			BTNode* tree = QueueFront(&q);
			QueuePop(&q);
			printf("%c ", tree->_data);

			if (tree->_left)
				QueuePush(&q, tree->_left);

			if (tree->_right)
				QueuePush(&q, tree->_right);
		}
	}
}

void BinaryTreePrevOrderNonR(BTNode* root)
{
	BTNode* cur = root;
	Stack st;
	StackInit(&st, 2);
	while (cur || StackEmpty(&st) != 0)
	{
		while (cur)
		{
			StackPush(&st, cur);
			printf("%c ", cur->_data);
			cur = cur->_left;
		}
		BTNode* node = StackTop(&st);
		StackPop(&st);
		cur = node->_right;
	}
}

void BinaryTreeInOrderNonR(BTNode* root)
{
	BTNode* cur = root;
	Stack st;
	StackInit(&st, 2);
	while (cur || StackEmpty(&st) != 0)
	{
		while (cur)
		{
			StackPush(&st, cur);
			cur = cur->_left;
		}
		BTNode* node = StackTop(&st);
		StackPop(&st);
		printf("%c ", node->_data);
		cur = node->_right;
	}
}

void BinaryTreePostOrderNonR(BTNode* root)
{
	BTNode* prev = NULL;
	BTNode* cur = root;
	Stack st;
	StackInit(&st, 2);
	while (cur || StackEmpty(&st) != 0)
	{
		while (cur)
		{
			StackPush(&st, cur);
			cur = cur->_left;
		}
		BTNode* node = StackTop(&st);
		if (node->_right == NULL || node->_right == prev)
		{
			printf("%c ", node->_data);
			StackPop(&st);
			prev = node;
		}
		else
		{
			cur = node->_right;
		}
	}
}

void BinaryTreeTest()
{
	char* array = "ABD##E#H##CF##G##";
	int i = 0;
	BTNode* tree = BinaryTreeCreate(array, &i);
	printf("%d\n", BinaryTreeSize(tree));
	printf("%d\n", BinaryTreeLeafSize(tree));
	printf("%d\n", BinaryTreeLevelKSize(tree, 3));

	printf("%c\n", *(BinaryTreeFind(tree, 'A')));

	BinaryTreePrevOrder(tree);
	printf("\n");

	BinaryTreeInOrder(tree);
	printf("\n");

	BinaryTreePostOrder(tree);
	printf("\n");

	BinaryTreeLevelOrder(tree);
	printf("\n");

	BinaryTreePrevOrderNonR(tree);
	printf("\n");

	BinaryTreeInOrderNonR(tree);
	printf("\n");

	BinaryTreePostOrderNonR(tree);
	printf("\n");

}