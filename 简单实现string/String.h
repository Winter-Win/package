//#pragma once
//
////��ͳд��string��
//namespace bit
//{
//	class String
//	{
//	public:
//		//String()
//		//	:_str(new char[1])
//		//{
//		//	_str[0] = '\0';//����һ��λ��
//		//}
//
//		//String(const char* str)
//		//	:_str(new char[strlen(str) + 1])
//		//{
//		//	strcpy(_str, str);
//		//}
//
//		String(const char* str = "")//�޲εĺʹ��εĿ��Ժϳ�һ��ȫȱʡ��
//			:_str(new char[strlen(str) + 1])
//		{
//			strcpy(_str, str);
//		}
//
//		String(const String& s)
//		{
//			_str = new char[strlen(s._str) + 1];
//			strcpy(_str, s._str);
//		}
//
//		String& operator=(const String& s)
//		{
//			if (this != &s)
//			{
//				delete[] _str;
//				_str = new char[strlen(s._str) + 1];
//				strcpy(_str, s._str);
//			}
//			return *this;
//		}
//
//		~String()
//		{
//			if (_str)
//			{
//				delete[] _str;
//				_str = nullptr;
//			}
//		}
//		
//		char* c_str()
//		{
//			return _str;
//		}
//
//		size_t Size()
//		{
//			return strlen(_str);
//		}
//
//		char& operator[](size_t pos)
//		{
//			return _str[pos];
//		}
//	private:
//		char* _str;
//	};
//
//	void TestString1()
//	{
//		String s1;
//		String s2("hello");
//		cout << s1.c_str() << endl;
//		cout << s2.c_str() << endl;
//
//		for (size_t i = 0; i < s2.Size(); ++i)
//		{
//			cout << s2[i] << " ";
//		}
//		cout << endl;
//
//		String s3(s2);
//		cout << s3.c_str() << endl;
//
//		String s4 = s3;
//		cout << s4.c_str() << endl;
//	}
//}



//#pragma once
//
////�ִ�д��string��
////���+����
//namespace bit
//{
//	class String
//	{
//	public:
//		String(const char* str = "")//�޲εĺʹ��εĿ��Ժϳ�һ��ȫȱʡ��
//			:_str(new char[strlen(str) + 1])
//		{
//			strcpy(_str, str);
//		}
//
//		String(const String& s)
//			:_str(nullptr)
//		{
//			/*_str = new char[strlen(s._str) + 1];
//			strcpy(_str, s._str);*/
//
//			String tmp(s._str);
//			swap(_str, tmp._str);
//		}
//
//		//String& operator=(const String& s)
//		//{
//		//	/*if (this != &s)
//		//	{
//		//		delete[] _str;
//		//		_str = new char[strlen(s._str) + 1];
//		//		strcpy(_str, s._str);
//		//	}
//		//	return *this;*/
//
//		//	if (this != &s)
//		//	{
//		//		String tmp(s._str);
//		//		swap(_str, tmp._str);
//		//	}
//		//	return *this;
//		//}
//
//		String& operator=(String s)
//		{
//			swap(_str, s._str);
//			return *this;
//		}
//
//		~String()
//		{
//			if (_str)
//			{
//				delete[] _str;
//				_str = nullptr;
//			}
//		}
//
//		char* c_str()
//		{
//			return _str;
//		}
//
//		size_t Size()
//		{
//			return strlen(_str);
//		}
//
//		char& operator[](size_t pos)
//		{
//			return _str[pos];
//		}
//
//	private:
//		char* _str;
//	};
//
//	void TestString1()
//	{
//		String s1;
//		String s2("hello");
//		cout << s1.c_str() << endl;
//		cout << s2.c_str() << endl;
//
//		for (size_t i = 0; i < s2.Size(); ++i)
//		{
//			cout << s2[i] << " ";
//		}
//		cout << endl;
//
//		String s3(s2);
//		cout << s3.c_str() << endl;
//
//		String s4 = s3;
//		cout << s4.c_str() << endl;
//	}
//}


#pragma once

namespace bit
{
	class String
	{
	public:
		//friend ostream& operator<<(ostream& out, const String& s);

		typedef char* iterator;
		typedef const char* const_iterator;


		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		String(const char* str = "")//�޲εĺʹ��εĿ��Ժϳ�һ��ȫȱʡ��
		{
			_size = strlen(str);
			_capacity = _size;

			_str = (new char[_capacity + 1]);
			strcpy(_str, str);
		}

		//s1.Swap(s2);
		void Swap(String& s)
		{
			swap(this->_str, s._str);
			swap(this->_size, s._size);
			swap(this->_capacity, s._capacity);
		}

		//s2(s1)
		String(const String& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			String tmp(s._str);
			this->Swap(tmp);
		}

		//s1 = s3
		String& operator=(String s)
		{
			this->Swap(s);

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
			
		size_t Size()
		{
			return _size;
		}

		size_t Capacity()
		{
			return _capacity;
		}

		void Reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		void Resize(size_t n, char ch = '\0');

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void PushBack(char ch)
		{
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 15 : _capacity * 2;

				Reserve(newcapacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		void PopBack()
		{
			assert(_size > 0);
			--_size;
			_str[_size] = '\0';
		}

		void Append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				Reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}

		// s1 + 'a'
		String& operator+=(char ch)
		{
			PushBack(ch);
			return *this;
		}

		String& operator+=(const char* str)
		{
			Append(str);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}

		String Substr(size_t pos, size_t len = npos)
		{
			String s;
			while (pos < _size && len--)
			{
				s += _str[pos++];
			}

			return s;
		}


		size_t Find(char ch, size_t pos = 0)
		{
			for (size_t i = pos; i < _size; ++i)
			{
				if (ch == _str[i])
				{
					return i;
				}
			}

			return npos;
		}

		size_t RFind(char ch, size_t pos = npos)
		{
			size_t i = (pos == npos ? _size : pos + 1);
			for (size_t i = _size; i > 0; --i)
			{
				if (ch == _str[i-1])
				{
					return i -1;
				}
			}

			return npos;
		}

		const char* my_strstr(const char* dest, const char* str)
		{
			const char* pdest = dest, *pstr = str;
			while (*pdest)//while (*pdest != '\0')
			{
				if (*pdest == *pstr)
				{
					const char* matchdest = pdest, *matchstr = pstr;

					while (*matchstr && *matchdest++ == *matchstr++);
					
					if (*matchstr == '\0')
						return pdest;
				}
				++pdest;
			}

			return NULL;
		}


		size_t Find(const char* str, size_t pos = 0)
		{
			const char* start = my_strstr(_str + pos, str);
			if (start)
			{
				return start - _str;
			}
			else
			{
				return npos;
			}
		}

		void Insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 15 : _capacity * 2;
				Reserve(newcapacity);
			}

			size_t end = _size;//size_t end = _size + 1;��������Ļ���'\0'��һ�������ˣ����Ͳ��õ���������
			while (end > pos)
			{
				_str[end] = _str[end - 1];//��ǰһ�����ڵ�ǰ��,����end�Ͳ��������֮�£����ͷ�壬�����ж���䣬end�������
				--end;
			}

			_str[pos] = ch;
			_size++;
			_str[_size] = '\0';//��ȷ����������'\0'
		}
		 
		void Insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				Reserve(_size + len);
			}

			size_t end = _size;
			while (end > pos)
			{
				_str[end - 1 + len] = _str[end - 1];
				--end;
			}

			while (*str)
			{
				_str[pos++] = *str++;
			}

			_size += len;
			_str[_size] = '\0';
		}

		void Erase(size_t pos, size_t len)
		{
			assert(pos);
			if (pos + len >= _size)
			{
				_size = pos;
				_str[_size] = '\0';
			}
			else
			{
				for (size_t i =  pos+ len; i < _size; ++i)
				{
					_str[pos++] = _str[i];
				}

				_size -= len;
				_str[_size] = '\0';
			}
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

	public:
		static const size_t npos;
	};

	const size_t String::npos = -1;

	String operator+(const String& s1, const String& s2)//����Ļ� ���ۺܴ�
	{
		String s = s1;
		s += s2.c_str();

		return s;
	}

	String operator+(const String& s1, const char* str)
	{
		String s = s1;
		s += str;

		return s;
	}


	////�����ʱ������'\0'�ͽ�����
	//ostream& operator<<(ostream& out, const String& s)
	//{
	//	out << s._str;
	//	return out;
	//}

	//ostream& operator<<(ostream& out, const String& s)
	//{
	//	out << s.c_str();//��ʱ������ԪҲ����
	//	return out;
	//}


	//�ǵ�ʵ�����������'\0'������ʵ�ֺ͵������йأ���������auto
	ostream& operator<<(ostream& out, const String& s)
	{
		for (auto ch : s)
		{
			out << ch;
		}

		return out;
	}

	void TestString1()
	{
		String  s1("hello");
		for (size_t i = 0; i < s1.Size(); ++i)
		{
			cout << s1[i] << " ";
		}
		cout << endl;

		String::iterator it1 = s1.begin();
		while (it1 != s1.end())
		{
			cout << *it1 << " ";
			++it1;
		}
		cout << endl;

		//��Χforѭ�����������޷������ߣ��޷�ɾ��
		for (auto ch : s1)
		{
			cout << ch << endl;
		}
	}

	void TestString2()
	{
		String s;
		s.PushBack(' ');
		s.Append("hello");
		s.PushBack(' ');
		s.Append("world ");
		s.Append("world ");
		s.Append("world");
		s.PopBack();
		s += '\0';
		s += "!!!!";

		////����������\0���������ڲ������õĵ�����
		//for (auto ch : s)
		//{
		//	cout << ch ;
		//}
		//cout << endl;

		//����'\0'����
		cout << s << endl;
	}

	void TestString3()
	{
		String file("test.cpp");
		size_t pos = file.RFind('.');
		cout << file.Substr(pos) << endl;

		String Url("https://blog.csdn.net/qq_41562665");
		size_t start = Url.Find("://");
		start += 3;
		size_t finish = Url.Find('/', start);

		cout << Url.Substr(start, finish - start) << endl;
	}

	void TestString4()
	{
		String s = "hello";
		s.Insert(0, ' ');
		s += "world";
		s.Insert(6, ' ');
		cout << s << endl;

		s.Insert(6, "winter!!!!");
		cout << s << endl;

		s.Erase(6, 10);
		cout << s << endl;
	}
}