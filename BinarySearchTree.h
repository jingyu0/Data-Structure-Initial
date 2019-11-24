//template<class K>
//struct BSTreeNode
//{
//	BSTreeNode<K>* _left;
//	BSTreeNode<K>* _right;
//	K _key;
//
//	BSTreeNode(const K& key)
//		:_key(key)
//		, _left(nullptr)
//		, _right(nullptr)
//	{}
//};
//
//template<class K>
//class BSTree
//{
//	typedef BSTreeNode<K> Node;
//public:
//	BSTree()
//		:_root(nullptr)
//	{}
//
//	~BSTree()
//	{
//		//...
//	}
//
//	bool Insert(const K& key)
//	{
//		if (_root == nullptr)
//		{
//			_root = new Node(key);
//			return true;
//		}
//
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (cur->_key > key)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else
//			{
//				return false;
//			}
//		}
//
//		cur = new Node(key);
//		if (parent->_key < key)
//		{
//			parent->_right = cur;
//		}
//		else
//		{
//			parent->_left = cur;
//		}
//		return true;
//	}
//
//	Node* Find(const K& key)
//	{
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < keys)
//			{
//				cur = cur->_right;
//			}
//			else if (cur->_key > key)
//			{
//				cur = cur->_left;
//			}
//			else
//			{
//				return cur;
//			}
//		}
//
//		return nullptr;
//	}
//
//	bool Erase(const K& key)
//	{
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (cur->_key > key)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else
//			{
//				// É¾³ý
//				// 1.×óÎª¿Õ
//				// 2.ÓÒÎª¿Õ
//				// 3.×óÓÒ¶¼²»Îª¿Õ
//				Node* del = cur;
//				if (cur->_left == nullptr)
//				{
//					if (parent == nullptr)
//					{
//						_root = cur->_right;
//					}
//					else
//					{
//						if (parent->_left == cur)
//						{
//							parent->_left = cur->_right;
//						}
//						else
//						{
//							parent->_right = cur->_right;
//						}
//					}
//				}
//				else if (cur->_right == nullptr)
//				{
//					if (parent == nullptr)
//					{
//						_root = cur->_left;
//					}
//					else
//					{
//						if (parent->_left == cur)
//						{
//							parent->_left = cur->_left;
//						}
//						else
//						{
//							parent->_right = cur->_left;
//						}
//					}
//				}
//				else
//				{
//					Node* lessParent = cur;
//					Node* lessRight = cur->_right;
//					while (lessRight->_left)
//					{
//						lessParent = lessRight;
//						lessRight = lessRight->_left;
//					}
//
//					cur->_key = lessRight->_key;
//					del = lessRight;
//					if (lessParent->_left == lessRight)
//					{
//						lessParent->_left = lessRight->_right;
//					}
//					else
//					{
//						lessParent->_right = lessRight->_right;
//					}
//				}
//
//				delete del;
//				return true;
//			}
//		}
//
//		return false;
//	}
//
//	bool _InsertR(Node*& root, const K& key)
//	{
//		if (root == nullptr)
//			root = new Node(key);
//
//		if (root->_key < key)
//			return _InsertR(root->_right, key);
//		else if (root->_key > key)
//			return _InsertR(root->_left, key);
//		else
//			return false;
//	}
//
//	// µÝ¹é°æ±¾ÊµÏÖ
//	bool InsertR(const K& key)
//	{
//		return _InsertR(_root, key);
//	}
//
//	Node* _FindR(Node* root, const K& key)
//	{
//		if (root == nullptr)
//			return nullptr;
//
//		if (root->_key == key)
//			return root;
//		else if (root->_key < key)
//			return _FindR(root->_right, key);
//		else if (root->_key > key)
//			return _FindR(root->_left, key);
//	}
//
//	Node* FindR(const K& key)
//	{
//		return _FindR(_root, key);
//	}
//
//	bool EraseR(const K& key)
//	{
//		// ...
//		return false;
//	}
//
//	void InOrder()
//	{
//		_InOrder(_root);
//		cout << endl;
//	}
//
//	void _InOrder(Node* root)
//	{
//		if (root == nullptr)
//		{
//			return;
//		}
//
//		_InOrder(root->_left);
//		cout << root->_key << " ";
//		_InOrder(root->_right);
//	}
//
//private:
//	Node* _root;
//};
//
//void TestBSTree()
//{
//	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
//	BSTree<int> t;
//	for (auto e : a)
//	{
//		t.InsertR(e);
//	}
//
//	t.InOrder();
//
//	// ²âÊÔË³Ðò¸ù¾Ý´úÂëÂß¼­ÉèÖÃ->°×ºÐ²âÊÔ
//	/*t.Erase(2);
//	t.Erase(8);
//	t.Erase(1);
//	t.Erase(7);
//	t.Erase(5);
//
//	t.InOrder();
//
//	for (auto e : a)
//	{
//		t.Erase(e);
//	}
//	t.InOrder();*/
//}

template<class K, class V>
struct BSTreeNode
{
	BSTreeNode<K, V>* _left;
	BSTreeNode<K, V>* _right;
	K _key;
	V _value;

	BSTreeNode(const K& key, const V& value)
		:_key(key)
		, _value(value)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template<class K, class V>
class BSTree
{
	typedef BSTreeNode<K, V> Node;
public:
	BSTree()
		:_root(nullptr)
	{}

	~BSTree()
	{
		//...
	}

	bool _InsertR(Node*& root, const K& key, const V& value)
	{
		if (root == nullptr)
			root = new Node(key, value);

		if (root->_key < key)
			return _InsertR(root->_right, key, value);
		else if (root->_key > key)
			return _InsertR(root->_left, key, value);
		else
			return false;
	}

	// µÝ¹é°æ±¾ÊµÏÖ
	bool InsertR(const K& key, const V& value)
	{
		return _InsertR(_root, key, value);
	}

	Node* _FindR(Node* root, const K& key)
	{
		if (root == nullptr)
			return nullptr;

		if (root->_key == key)
			return root;
		else if (root->_key < key)
			return _FindR(root->_right, key);
		else
			return _FindR(root->_left, key);
	}

	Node* FindR(const K& key)
	{
		return _FindR(_root, key);
	}

	bool EraseR(const K& key)
	{
		// ...
		return false;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_key << ":" << root->_value << endl;
		_InOrder(root->_right);
	}

private:
	Node* _root;
};

#include <string>

void TestBSTreeKV1()
{
	BSTree<string, string> dict;
	dict.InsertR("insert", "²åÈë");
	dict.InsertR("left", "×ó±ß");
	dict.InsertR("right", "ÓÒ±ß");
	dict.InsertR("node", "½Úµã");
	dict.InsertR("tree", "Ê÷");

	string str;
	while (cin>>str)
	{
		BSTreeNode<string, string>* ret = dict.FindR(str);
		if (ret)
		{
			cout << str << ":" << ret->_value << endl;
		}
		else
		{
			cout << str << ":" << "·Ç·¨´Ê»ã" << endl;
		}
	}
}

void TestBSTreeKV2()
{
	string strs[] = { "Æ»¹û", "Î÷¹Ï", "²ÝÝ®", "²ÝÝ®", "Î÷¹Ï", "²ÝÝ®" };
	BSTree<string, int> countTree;
	for (auto& e: strs)
	{
		auto ret = countTree.FindR(e);
		if (ret)
		{
			ret->_value++;
		}
		else
		{
			countTree.InsertR(e, 1);
		}
	}

	countTree.InOrder();
}