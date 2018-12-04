#define _CRT_SECURE_NO_WARNINGS 1

//#include <iostream>
//using namespace std;

//1. 实现宏函数
//2.宏优点：没有压栈的开销	缺点：复杂，不能调试，没有类型安全的检查
//3.如何解决？C++用enum、const、inline去代替宏

//#define ADD(a, b) ((a)+(b))
//
//inline int Add(int left, int right)
//{
//	return left + right;
//}
//
//int main()
//{
//	Add(1, 2);
//
//	int ret = ADD(1, 2);
//
//	cout << ret << endl;
//	system("pause");
//	return 0;
//}




////auto
//
//#include <iostream>
//using namespace std;
//
//int TestAuto()
//{
//	return 10;
//}
//
//int main()
//{
//	//int a = 10;
//	//auto b = a;
//	//auto c = 'a';
//	////auto d;//auto必须初始化
//	//auto d = TestAuto();
//
//	//cout << typeid(a).name() << endl;
//	//cout << typeid(b).name() << endl;
//	//cout << typeid(c).name() << endl;
//	//cout << typeid(d).name() << endl;
//
//
//
//	/*int x = 10;
//	auto a = &x;
//	auto* b = &x;
//	auto& c = x;
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;*/
//
//
//
//	//int arr[] = { 1, 2, 3, 4, 5 };
//
//	//for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	//	arr[i] *= 2;//每个加倍
//
//	//for (int* p = arr; p <arr + sizeof(arr) / sizeof(arr[0]); p++)//指针的方法遍历
//	//	cout << *p << endl;
//
//	//cout << "=======================C++11=======================" << endl;
//	////语法糖
//	//for (auto e : arr)
//	//	cout << e << endl;
//
//	//for (auto& e : arr)//用引用，同一片空间，如果不用的话，e改变了，不能改变原数组的值
//	//	e *= 2;
//
//	//for (auto e : arr)
//	//	cout << e << endl;
//
//
//	system("pause");
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//int main()
//{
//	char str1[] = "\0";
//	cout << sizeof(str1) << endl;//2
//	cout << strlen(str1) << endl;//0
//
//	char str2[] = "\\0";
//	cout << sizeof(str2) << endl;//3
//	cout << strlen(str2) << endl;//2
//
//	char str3[] = "\0 123";
//	cout << sizeof(str3) << endl;//3
//	cout << strlen(str3) << endl;//2
//
//	system("pause");
//	return 0;
//}




//#include <iostream>
//using namespace std;
//
////class className
////{
////	//类体：由成员函数和成员变量组成
////
////};//一定注意后面的分号
//
//
////人
//class Person
//{
//public:
//	//显示基本信息
//	void ShowInfo()
//	{
//		cout << _name << "-" << _sex << "-" << _age << endl;
//	}
//
//public:
//	char* _name;//姓名
//	char* _sex; //性别
//	int _age;   //年龄
//};
//
//
//// 类中既有成员变量，又有成员函数
////
//#include <iostream>
//using namespace std;
//
////#pragma pack(4)//设置默认对齐数
//
//class A1
//{
//public:
//	void f1() {}
//private:
//	int _a;
//	double _b;
//};
//
//// 类中仅有成员函数
//class A2
//{
//public:
//	void f2() {}
//};
//
//// 类中什么都没有---空类
//class A3
//{};
//
//
//int main()
//{
//	cout << sizeof(A1) << endl;//
//	cout << sizeof(A2) << endl;//1
//	cout << sizeof(A3) << endl;//1
//
//	system("pause");
//	return 0;
//}