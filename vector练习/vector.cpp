#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print_vector(const vector<int>& v)
{
	vector<int>::const_iterator it = v.cbegin();
	while (it != v.cend())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_vector1()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//vector<int>::reverse_iterator rit = v.rbegin();
	auto rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	print_vector(v);
}

void test_vector2()
{
	size_t sz;
	std::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i) {
		foo.push_back(i);
		if (sz != foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
}

void test_vector3()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	v.insert(v.begin(), 0);
	v.insert(v.end(), 5);

	//auto it = v.begin();
	//while (it != v.end())
	//{
	//	if (*it == 3)
	//	{
	//		v.insert(it, 30);
	//		break;
	//	}
	//	else
	//	{
	//		++it;
	//	}
	//}

	// [)
	v.reserve(10);
	auto it = find(v.begin(), v.end(), 3);
	if (it != v.end())
		v.insert(it, 30); // it是失效的迭代器
	else
		cout << "没有找到" << endl;
	// 迭代器失效问题
	// 迭代器：insert(可能会增容) 失效
	// 迭代器：erase(vs会报错) 失效
	// 不能去访问这个位置，否则可能会出问题
	//		   
	//*it = 10;
	//it = find(v.begin(), v.end(), 3);
	//v.erase(it); 

	it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			it = v.erase(it);
		else
			++it;
	}

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector4()
{
	vector<int> v1(10, 5);
	vector<int> v2(5, 10);

	swap(v1, v2);
	v1.swap(v2);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> v(100, 1);
	cout << v.capacity() << endl;
	v.clear();
	// 手动释放vector空间
	v.resize(0);
	v.reserve(0);
	//{
	//	vector<int> tmp;
	//	tmp.swap(v);
	//}
	v.shrink_to_fit();
	cout << v.capacity() << endl;
}

int main()
{
	test_vector4();

	return 0;
}
