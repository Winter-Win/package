#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

void test_string1()
{
	char str1[] = "string";
	char str2[] = "财大";
	char str3[5];
	str3[0] = -78;
	str3[1] = -58;
	str3[2] = -76;
	str3[3] = -13;
	str3[4] = '\0';

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
}


void test_string2()
{
	string s1("hello");//直接传参构造
	string s2(s1);//拷贝构造
	string s3("world");
	s1 = s3;//赋值运算符重载
	
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;

	string file("file.cpp");
	string suffix(file, 4, 4);
	string s4(s3, 1, 3);

	cout << s4 << endl;
	cout << suffix << endl;

	string path("c:\\test.c");//注意转义字符'\'
	cout << path << endl;


	string s5(file.begin(), file.end());
	cout << s5 << endl;

}
//1.遍历字符串
//"1234"   数组一般用[],可以重载运算符
int StrToInt1(string str)
{
	/*for (size_t i = 0; i < str.size(); ++i)
	{
		cout << str[i] << " ";
		cout << str.operator[](i) << " ";
	}
	cout << endl;

	return 0;*/


	int value = 0;
	for (size_t i = 0; i < str.size(); ++i)
	{
		value *= 10;
		value += str[i] - '0';//注意ASCII的值
	}

	return value;
}


int StrToInt2(string str)
{
	int value = 0;
	//在stl中的迭代器  --  不破坏封装的情况下去访问容器
	string::iterator it = str.begin();
	while (it != str.end())
	{
		value *= 10;
		value += (*it - '0');
		++it;
	}

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	vector<int>::iterator vit = v.begin();
	while (vit != v.end())
	{
		cout << *vit << " ";
		++vit;
	}
	cout << endl;

	list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	list<int>::iterator lit = l.begin();
	while (lit != l.end())
	{
		cout << *lit << " ";
		++lit;
	}
	cout << endl;

	return value;
}

int StrToInt3(string str)
{
	int value = 0;
	//C++11
	for (auto ch : str)
	{
		value *= 10;
		value += (ch - '0');
	}

	return value;
}


//防止改变
int StrToInt4(const string& str)
{
	//在stl中的迭代器  --  不破坏封装的情况下去访问容器
	int value = 0;
	string::const_iterator it = str.begin();
	while (it != str.end())
	{
		value *= 10;
		value += (*it - '0');
		++it;
	}

	/*string::const_reverse_iterator it = str.rbegin();
	while (it != str.rend())
	{
		value *= 10;
		value += (*it - '0');
		++it;
	}*/

	return value;
}



void test_string3()
{
	//1.正向  可读可写
	//2.反向  可读可写
	//3.const 只读
	//StrToInt1("1234");
	//cout << StrToInt1("1234") << endl;

	//cout << StrToInt2("1234") << endl;
	//StrToInt2("1234");

	//cout << StrToInt3("1234") << endl;

	//倒序访问  反向迭代器
	/*string s1("hello");
	string::reverse_iterator rit = s1.rbegin();
	while (rit != s1.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;*/

	cout << StrToInt4("1234") << endl;

}


void test_string4()
{
	/*
	string s1("hello");
	s1.push_back(' ');
	s1.push_back('w');
	s1.push_back('o');
	s1.push_back('r');
	s1.push_back('l');
	s1.push_back('d');
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;
	cout << s1.max_size() << endl;
	cout << s1 << endl;
	*/

	/*
	string s;
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	s.reserve(100);//控制，多次增容会消耗   后面会打印一次是100和capacity不一样   请求容量
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
	*/


	string s("hello world");
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	//s.resize(5);
	cout << s << endl;
	s.resize(20, 'a');
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
}

void test_string5()
{
	string s1("hello,world");//把逗号改成%
	/*s1[5] = '%';
	cout << s1 << endl;*/
	for (size_t i = 0; i < s1.size(); ++i)
	{
		if (s1[i] == ',')
		{
			s1[i] = '%';
		}
	}
	cout << s1 << endl;

	for (auto& ch : s1)
	{
		if (ch == '%')
		{
			ch = ',';
		}
	}
	cout << s1 << endl;

	size_t pos = s1.find(',');
	s1[pos] = '%';
	cout << s1 << endl;
	s1.at(pos) = ',';//早期的接口
	cout << s1 << endl;

	//const string s2("hello");
}

void test_string6()
{
	/*
	string s1("hello");
	s1.push_back(' ');
	s1.append("world");
	cout << s1 << endl;

	s1 += "!!!";//建议使用这个
	s1 += 'x';
	cout << s1 << endl;

	string protocol = "https://";
	string domain = "www.baidu.com";
	string url = protocol + domain;//会产生临时变量
	cout << url << endl;
	*/

	string s1("ello");
	s1.insert(0, 1, 'h');
	s1.insert(s1.begin(), 'h');
	s1.insert(0, "world");
	s1.erase(5, 1);
	cout << s1 << endl;
	s1.erase(5);
	cout << s1 << endl;
}

int main()
{
	test_string6();

	system("pause");
	return 0;
}