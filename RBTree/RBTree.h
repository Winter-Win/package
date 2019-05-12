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
		cur->_color = RED; //ֻ��ı�һ��·��
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

		// ƽ��
		while (parent && parent->_color == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_color == RED)
				{
					// ��һ����� ��ɫ
					parent->_color = BLACK;
					uncle->_color = BLACK;
					grandfather->_color = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					// �����������˫��->����
					if (cur == parent->_right)
					{
						RotateL(parent);
						std::swap(cur, parent);
					}

					// �ڶ�������� ����+��ɫ
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
					// ��һ����� ��ɫ
					parent->_color = BLACK;
					uncle->_color = BLACK;
					grandfather->_color = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					// �����������˫��->����
					if (cur == parent->_left)
					{
						RotateR(parent);
						std::swap(cur, parent);
					}

					// �ڶ�������� ����+��ɫ
					RotateL(grandfather);
					parent->_color = BLACK;
					grandfather->_color = RED;
				}
			}
		}

		_root->_color = BLACK;

		return true;
	}

	void RotateL(Node* parent)  // ����
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL != nullptr)  //�ж��Ƿ������������Ƿ�Ϊ��
		{
			subRL->_parent = parent;
		}
		subR->_left = parent;
		Node* ppnode = parent->_parent; //����parent�ĸ���
		parent->_parent = subR;

		// ע����ڵ�
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
		subR->_parent = ppnode; // ͳһ����subR�ĸ��׸���

	}

	void RotateR(Node* parent)  // �ҵ���
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR != nullptr) //�ж��Ƿ������������Ƿ�Ϊ��
		{
			subLR->_parent = parent;
		}
		subL->_right = parent;
		Node* ppnode = parent->_parent; //����parent�ĸ���
		parent->_parent = subL;

		// ע����ڵ�
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
		subL->_parent = ppnode; // ͳһ����subL�ĸ��׸���

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