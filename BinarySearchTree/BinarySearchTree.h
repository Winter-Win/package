#pragma once

#include <iostream>

template<class K, class V>
struct BSTreeNode
{
	BSTreeNode<K, V>* _left;
	BSTreeNode<K, V>* _right;

	std::pair<K, V> _kv;

	BSTreeNode(const std::pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _kv(kv)
	{}
};

template<class K, class V>
class BSTree
{
	typedef BSTreeNode<K, V> Node;
private:
	Node* _root;

public:
	BSTree()
		:_root(nullptr)
	{}

	bool Insert(const std::pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		Node* parent = nullptr;  //保证链起来
		Node* cur = _root;
		while (cur != nullptr)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}

	Node* Find(const K& k)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < k)
				cur = cur->_right;
			else if (cur->_kv.first > k)
				cur = cur->_left;
			else
				return cur;
		}

		return nullptr;
	}

	bool Erase(const K& k)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < k)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > k)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				//找到开始删除
				//1. 左为空，父亲指向右
				//2. 右为空，父亲指向左
				//3. 左右都不为空，找替代节点，删除替代节点
				Node* del = cur;
				if (cur->_left == nullptr)
				{
					if (parent == nullptr)
					{
						_root = cur->_right;
					}
					else
					{

						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}
				}
				else if (cur->_right == nullptr)
				{
					if (parent == nullptr)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}
				}
				else
				{
					Node* preplace = cur; //特殊情况关键点
					Node* replace = cur->_right;
					while (replace->_left)
					{
						preplace = replace;
						replace = replace->_left;
					}

					cur->_kv = replace->_kv;
					del = replace;

					//删除替代的最左节点
					if (preplace->_left == replace)
					{
						preplace->_left = replace->_right;
					}
					else
					{
						preplace->_right = replace->_right;
					}	
				}

				delete del;
				return true;
			}
		}
		return false;
	}

	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}

	void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;
		_Inorder(root->_left);
		cout << root->_kv.first << " ";
		_Inorder(root->_right);
	}

	~BSTree()
	{}
};

void TestBSTree1()
{
	BSTree<int, int> bt;
	bt.Insert(std::make_pair(1, 1));
	bt.Insert(std::make_pair(4, 1));
	bt.Insert(std::make_pair(3, 1));
	bt.Insert(std::make_pair(5, 1));
	bt.Insert(std::make_pair(2, 1));
	bt.Insert(std::make_pair(6, 1));
	bt.Inorder();
}

void TestBSTree2()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9, 9 };
	BSTree<int, int> bt;
	for (auto e : a)
	{
		bt.Insert(make_pair(e, e));
	}
	bt.Inorder();

	bt.Erase(2);
	bt.Erase(8);
	bt.Erase(2);
	bt.Erase(1);
	bt.Erase(5);
	bt.Erase(7);
	bt.Inorder();

	for (auto e : a)
	{
		bt.Erase(e);
	}
	bt.Inorder();
}