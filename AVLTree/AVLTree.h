#pragma once

template <class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	std::pair<K, V> _kv;
	int _bf; //平衡因子

	AVLTreeNode(const std::pair<int, int>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{}
};

template <class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
private:
	Node* _root;

public:
	AVLTree()
		:_root(nullptr)
	{}

	bool Insert(const std::pair<K, V>& kv)
	{
		if (_root = nullptr)
		{
			_root = new Node(kv);
			_root->_bf = 0;
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
		if (parent->_kv.first > kv.first)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}

		// 更新平衡因子
		while (parent)
		{
			if (cur = parent->_left)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}

			// 1. 高度不变，更新结束
			if (parent->_bf == 0)
			{
				break;
			}
			// 2. 高度变了，继续更新
			else if (abs(parent->_bf) == 1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)
			{
				// 不平衡旋转：子树变平衡 + 降高度
				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)
					{
						RotateL(parent);
					}
					else if (cur->_bf == -1)
					{
						RotateRL(parent);
					}
				}
				else if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						RotateR(parent);
					}
					else if (cur->_bf == 1)
					{
						RotateLR(parent);
					}
				}

				break;
			}
		}
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

		subR->_bf = parent->_bf = 0;
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
		
		subL->_bf = parent->_bf = 0;
	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(parent->_left);
		RotateR(parent);

		subLR->_bf = 0;
		if (bf == 1)
		{
			parent->_bf = 0;
			subL->_bf = -1;
		}
		else if (bf == -1)
		{
			parent->_bf = 1;
			subL->_bf = 0;
		}
		else if (bf == 0)
		{
			subL->_bf = parent->_bf = 0;
		}
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		subRL->_bf = 0;
		if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
		}
		else if (bf == 1)
		{
			parent->_bf = -1;
			subR->_bf = 0;
		}
		else if (bf == 0)
		{
			subR->_bf = parent->_bf = 0;
		}
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

void TestAVLTree()
{
	AVLTree<int, int> at;
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (auto e : a)
	{
		at.Insert(std::make_pair(e, e));
	}
	at.Inorder();
}



