#pragma once

enum Color
{
	RED,
	BLACK,
};

template<class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	std::pair<K, V> _kv;
	Color _color;

	RBTreeNode(const std::pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _color(BLACK)
	{}
};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;

private:
	Node* _root = nullptr;

public:
	bool Insert(const std::pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_color = BLACK;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		cur->_color = RED; //只会改变一条路径
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		// 平衡
		while (parent && parent->_color == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_color == RED)
				{
					// 第一种情况 变色
					parent->_color = BLACK;
					uncle->_color = BLACK;
					grandfather->_color = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					// 第三种情况：双旋->单旋
					if (cur == parent->_right)
					{
						RotateL(parent);
						std::swap(cur, parent);
					}

					// 第二种情况： 单旋+变色
					RotateR(grandfather);
					parent->_color = BLACK;
					grandfather->_color = RED;
				}
			}
			else  //  parent == grandfather->_right
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_color == RED)
				{
					// 第一种情况 变色
					parent->_color = BLACK;
					uncle->_color = BLACK;
					grandfather->_color = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					// 第三种情况：双旋->单旋
					if (cur == parent->_left)
					{
						RotateR(parent);
						std::swap(cur, parent);
					}

					// 第二种情况： 单旋+变色
					RotateL(grandfather);
					parent->_color = BLACK;
					grandfather->_color = RED;
				}
			}
		}

		_root->_color = BLACK;

		return true;
	}

	void RotateL(Node* parent)  // 左单旋
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL != nullptr)  //判断是否右树的左树是否为空
		{
			subRL->_parent = parent;
		}
		subR->_left = parent;
		Node* ppnode = parent->_parent; //保存parent的父亲
		parent->_parent = subR;

		// 注意根节点
		if (parent == _root)
		{
			_root = subR;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subR;
			}
			else
			{
				ppnode->_right = subR;
			}
		}
		subR->_parent = ppnode; // 统一处理subR的父亲更新

	}

	void RotateR(Node* parent)  // 右单旋
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR != nullptr) //判断是否左树的右树是否为空
		{
			subLR->_parent = parent;
		}
		subL->_right = parent;
		Node* ppnode = parent->_parent; //保存parent的父亲
		parent->_parent = subL;

		// 注意根节点
		if (parent == _root)
		{
			_root = subL;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subL;
			}
			else
			{
				ppnode->_right = subL;
			}
		}
		subL->_parent = ppnode; // 统一处理subL的父亲更新

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
};

void TestRBTree()
{
	RBTree<int, int> at;
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (auto e : a)
	{
		at.Insert(std::make_pair(e, e));
	}
	at.Inorder();
}