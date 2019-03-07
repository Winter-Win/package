#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>
using namespace std;

void test_string1()
{
	string s0("hello world!");
	cout << s0 << endl;
	//string();
	string s1;
	cout << s1 << endl;
	//string(const string& str);
	string s2(s0);
	cout << s2 << endl;
	//string(const string& str, size_t pos, size_t len = npos);
	string s3(s0, 6, 1);
	cout << s3 << endl;
	//string(const char* s);
	string s4("hello world!");
	cout << s4 << endl;
	//string(const char* s, size_t n);
	string s5("hello world!", 5);
	cout << s5 << endl;
	//string(size_t n, char c);
	//template <class InputIterator>
	//string(InputIterator first, InputIterator last);
}

void test_string2()
{
	string s0("hello");
	string s1, s2, s3;
	//string& operator= (const string& str);
	s1 = s0;
	cout << s1 << endl;
	//string& operator= (const char* s);
	s2 = "hello world!";
	cout << s2 << endl;
	//string& operator= (char c);
	s3 = 'w';
	cout << s3 << endl;
}

//1.遍历字符串
//  "1234"
int StrToInt1(string str)
{
	//for (size_t i = 0; i < str.size(); ++i)
	//{
	//	cout << str[i] << " ";
	//	//cout << str.operator[](i) << " ";
	//}
	//cout << endl;

	//return 0;

	int val = 0;
	for (size_t i = 0; i < str.size(); ++i)
	{
		val *= 10;
		val += str[i] - '0';
	}

	return val;
}

int StrToInt2(string str)
{
	int val = 0;
	//迭代器 不破坏封装的情况下去访问容器
	//string::iterator it = str.begin();
	//while (it != str.end())
	//{
	//	val *= 10;
	//	val += (*it - '0');
	//	++it;
	//}

	string::reverse_iterator it = str.rbegin();
	while (it != str.rend())
	{
		val *= 10;
		val += (*it - '0');
		++it;
	}
	return val;
}

int StrToInt3(string str)
{
	int val = 0;
	//C++11
	for (auto ch : str)
	{
		val *= 10;
		val += (ch - '0');
	}

	return val;
}

void test_string3()
{
	cout << StrToInt1("1234") << endl;
	cout << StrToInt2("1234") << endl;
	cout << StrToInt3("1234") << endl;

	list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	list<int>::iterator lit = l.begin();
	while (lit != l.end())
	{
		cout << *lit << endl;
		++lit;
	}
}

void test_string4()
{
	string s1("hello");
	s1.push_back(' ');
	s1.push_back('w');
	s1.push_back('o');
	s1.push_back('r');
	s1.push_back('l');
	s1.push_back('d');
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;

	//s1.resize(5);//直接缩小
	//cout << s1 << endl;
	//cout << s1.size() << endl;
	//cout << s1.length() << endl;
	//cout << s1.capacity() << endl;

	//s1.resize(14, 'a');
	//cout << s1 << endl;
	//cout << s1.size() << endl;
	//cout << s1.length() << endl;
	//cout << s1.capacity() << endl;

	s1.resize(20, 'x');
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;
}

void test_string5()
{
	string s1("hello world");
	//s1[5] = '%';
	//cout << s1 << endl;

	for (size_t i = 0; i < s1.size(); ++i)
	{
		if (s1[i] == ' ')
			s1[i] = '%';
	}
	cout << s1 << endl;
}

void test_string6()
{
	string s1("hello");
	s1.push_back(' ');
	s1.append("world");
	cout << s1 << endl;

	s1 += "!!!";
	s1 += 'x';
	cout << s1 << endl;

	string protocol = "https://";
	string domain = "www.baidu.com";
	//不建议用+
	string url1 = protocol + domain;//加出临时对象，拷贝构造给url1
	cout << url1 << endl;

	//建议用+=
	string url2 = protocol;
	url2 += domain;
	cout << url2 << endl;
}

void test_string7()
{
	string s1("ello");
	s1.insert(0, 1, 'h');
	cout << s1 << endl;
	s1.insert(s1.begin(), 'h');
	cout << s1 << endl;
	s1.insert(0, "world");
	cout << s1 << endl;
	s1.erase(5, 1);//从第五个位置开始，删除指定长度字符串
	cout << s1 << endl;
}

void test_string8()
{
	/*
	string s1("hello");
	string s2("world");
	s1.swap(s2);
	cout << s1 << "--" << s2 << endl;

	swap(s1, s2);//不建议，效率低
	cout << s1 << "--" << s2 << endl;
	*/


	//replace  替换
	string url = "http://www.cplusplus.com/reference/string/string/replace/";
	url.replace(0, 4, "https");
	cout << url << endl;
	cout << url.c_str() << endl;
	printf("%s\n", url.c_str());

	url[5] = '\0';
	cout << url << endl;
	cout << url.c_str() << endl;
	printf("%s\n", url.c_str());

}

string getfilesuffix(const string& file)
{
	size_t pos = file.find('.');
	string suffix;
	if (pos != string::npos)
	{
		suffix = file.substr(pos, file.size() - pos);
	}

	return suffix;
}

void test_string9()
{
	//string file = "test.cpp";
	//string suffix(file, 4, 4);
	//cout << suffix << endl;

	//string file = "test.cpp";
	//size_t pos = file.find('.');
	//if (pos != string::npos)
	//{
	//	string suffix(file, pos, file.size() - pos);
	//	cout << suffix << endl;
	//}

	//cout << getfilesuffix("test.cpp") << endl;

	const string file = "test.cpp.tar.zip";
	size_t pos = file.rfind('.');
	string suffix;
	if (pos != string::npos)
	{
		suffix = file.substr(pos, file.size() - pos);
	}
	cout << suffix << endl;

	size_t prevpos = file.rfind('.', pos - 1);
	if (prevpos != string::npos)
	{
		suffix = file.substr(prevpos, pos - prevpos);
	}
	cout << suffix << endl;
}

int main()
{
	//test_string1();
	//test_string2();
	//test_string3();
	//test_string4();
	//test_string5();
	//test_string6();
	//test_string7();
	//test_string8();
	//test_string9();

	system("pause");
	return 0;
}

