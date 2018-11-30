#pragma once

//传统写法string类
namespace bit
{
	class String
	{
	public:
		//String()
		//	:_str(new char[1])
		//{
		//	_str[0] = '\0';//将第一个位置
		//}

		//String(const char* str)
		//	:_str(new char[strlen(str) + 1])
		//{
		//	strcpy(_str, str);
		//}

		String(const char* str = "")//无参的和带参的可以合成一个全缺省的
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}

		String(const String& s)
		{
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}

		String& operator=(const String& s)
		{
			if (this != &s)
			{
				delete[] _str;
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
			}
			return *this;
		}

		~String()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
		
		char* c_str()
		{
			return _str;
		}

		size_t Size()
		{
			return strlen(_str);
		}

		char& operator[](size_t pos)
		{
			return _str[pos];
		}
	private:
		char* _str;
	};

	void TestString1()
	{
		String s1;
		String s2("hello");
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		for (size_t i = 0; i < s2.Size(); ++i)
		{
			cout << s2[i] << " ";
		}
		cout << endl;

		String s3(s2);
		cout << s3.c_str() << endl;

		String s4 = s3;
		cout << s4.c_str() << endl;
	}
}