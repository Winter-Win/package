#define _CRT_SECURE_NO_WARNINGS 1

//#include <iostream>
//using namespace std;

//1. ʵ�ֺ꺯��
//2.���ŵ㣺û��ѹջ�Ŀ���	ȱ�㣺���ӣ����ܵ��ԣ�û�����Ͱ�ȫ�ļ��
//3.��ν����C++��enum��const��inlineȥ�����

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
//	////auto d;//auto�����ʼ��
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
//	//	arr[i] *= 2;//ÿ���ӱ�
//
//	//for (int* p = arr; p <arr + sizeof(arr) / sizeof(arr[0]); p++)//ָ��ķ�������
//	//	cout << *p << endl;
//
//	//cout << "=======================C++11=======================" << endl;
//	////�﷨��
//	//for (auto e : arr)
//	//	cout << e << endl;
//
//	//for (auto& e : arr)//�����ã�ͬһƬ�ռ䣬������õĻ���e�ı��ˣ����ܸı�ԭ�����ֵ
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
////	//���壺�ɳ�Ա�����ͳ�Ա�������
////
////};//һ��ע�����ķֺ�
//
//
////��
//class Person
//{
//public:
//	//��ʾ������Ϣ
//	void ShowInfo()
//	{
//		cout << _name << "-" << _sex << "-" << _age << endl;
//	}
//
//public:
//	char* _name;//����
//	char* _sex; //�Ա�
//	int _age;   //����
//};
//
//
//// ���м��г�Ա���������г�Ա����
////
//#include <iostream>
//using namespace std;
//
////#pragma pack(4)//����Ĭ�϶�����
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
//// ���н��г�Ա����
//class A2
//{
//public:
//	void f2() {}
//};
//
//// ����ʲô��û��---����
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