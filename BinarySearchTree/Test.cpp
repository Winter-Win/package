#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using std::cout;
using std::endl;

#include <string>
#include <map>
#include <set>

//template<class K, class V>
//struct pair
//{
//	K fisrt;
//	V second;
//
//	//����
//};

template<class K, class V>
inline std::pair<K, V> make_pair(const K& k, const V& v)
{
	return std::pair<K, V>(k, v);
}

void test_map()
{
	// 1. key/value. ͨ���ؼ��ֲ���ӳ�������Ϣvalue

	//����ֻ��key
	std::map<std::string, std::string> dict;
	dict.insert(std::pair<std::string, std::string>("sort", "����"));
	dict.insert(std::make_pair("string", "�ַ���"));
	dict["pair"];
	dict["key"] = "�ؼ���";
	dict["sort"] = "paixu";

	std::map<std::string, std::string>::iterator dit = dict.begin();
	while (dit != dict.end())
	{
		cout << (*dit).first << " : " << (*dit).second << endl;
		cout << dit->first << " : " << dit->second << endl;
		++dit;
	}

	std::string strs[] = { "ƻ��", "�㽶", "����", "����", "ƻ��", "ƻ��" };
	//ͳ��ˮ�����ֵĴ���
	//std::map<std::string, int> countmap;
	//for (const auto& str : strs)
	//{
	//	auto it = countmap.find(str);
	//	if (it != countmap.end())
	//	{
	//		it->second++;
	//	}
	//	else
	//	{
	//		countmap.insert(make_pair(str, 1));
	//	}
	//}

	typedef std::map<std::string, int> CountMap;
	typedef std::map<std::string, int>::iterator CountMapIter;

	//std::map<std::string, int> countmap;
	CountMap countmap;
	for (const auto& str : strs)
	{
		//std::pair<std::map<std::string, int>::iterator, bool> ret = countmap.insert(std::make_pair(str, 1));
		//std::pair<CountMapIter, bool> ret = countmap.insert(std::make_pair(str, 1));
		auto ret = countmap.insert(std::make_pair(str, 1));
		if (ret.second == false)
		{
			ret.first->second++;
		}
	}

/******************************************************************************

	// operator[]
	mapped_type& operator[] (const key_type& k)
	{
		return (*((this->insert(make_pair(k, mapped_type()))).first)).second;
	}
	���ص���value���͵�����
******************************************************************************/

	//std::map<std::string, int> countmap;
	////for (const std::string& str : strs)
	//for (const auto& str : strs)
	//{
	//	countmap[str]++;
	//}




	//std::map<std::string, int>::iterator cit = countmap.begin();
	auto cit = countmap.begin();
	while (cit != countmap.end())
	{
		cout << cit->first << " : " << cit->second << endl;
		++cit;
	}
	cout << endl;

	for (const auto& cm : countmap)
	{
		cout << cm.first << " : " << cm.second << endl;
	}
}


void test_set()
{
	//1. key. ���ҹؼ����ڲ���
	//2. ���� + ȥ��
	std::set<int> st;
	st.insert(3);
	st.insert(2);
	st.insert(1);
	st.insert(5);
	st.insert(5);
	st.insert(5);
	st.insert(2);
	st.insert(4);
	st.insert(4);

	std::set<int>::iterator stit = st.begin();
	while (stit != st.end())
	{
		cout << *stit << " ";
		stit++;
	}
	cout << endl;

	stit = st.find(3); //O(logN)
	//stit = find(st.begin(), st.end(), 3); //O(N)
	if (stit != st.end())
	{
		cout << "�ҵ���" << endl;
		st.erase(stit);
	}

	st.erase(4);

	for (auto e : st)
	{
		cout << e << " ";
	}
	cout << endl;

	//1. key. ���ҹؼ����ڲ���
	//2. ����
	std::multiset<int> ms;
	ms.insert(2);
	ms.insert(4);
	ms.insert(1);
	ms.insert(2);
	ms.insert(5);
	ms.insert(2);
	ms.insert(6);

	for (auto e : ms)
	{
		cout << e << " ";
	}
	cout << endl;

	auto msit = ms.find(2); //�ҵ���������ĵ�һ��2
	if (msit != ms.end())
	{
		cout << "�ҵ���" << endl;
		while (*msit == 2)
		{
			cout << *msit << endl; 
			++msit; //find()���ƣ�++����������ҡ�������
		}
	}
}


#include "BinarySearchTree.h"
#include "AVLTree.h"

int main()
{
	//test_map();
	//test_set();

	//TestBSTree1();
	//TestBSTree2();
	TestAVLTree();

	system("pause");
	return 0;
}