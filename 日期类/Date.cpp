#include "Date.h"

void Date::Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

/*Date(int year = 1900, int month = 0, int day = 0)
{
	_year = year;
	_month = month;
	_day = day;
}*/

int Date::GetMonthDay(int year, int month)
{
	int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && (year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return 29;
	}

	return monthArray[month];
}


Date::Date(int year, int month, int day)
{
	if (year >= 0 &&
		month > 0 && month < 13 &&
		day > 0 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "Date Invalid" << endl;
	}
}

//~Date();

Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

//��ֵ��������Ļ�������һ������ֱ�Ӹ�ֵ���У�����ֹ���Ļ�������ֱ�ӿ��������ˣ�û�и�ֵ
Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//cout << "Date& operator=(const Date& d)" << endl;
	return *this;
}

//+=�Ļ�������֮������Ҳ���ˣ����������Ҳ��һ��
Date& Date::operator+=(int days)
{
	/*Date ret(*this);
	ret._day += days;
	while (ret._day > GetMonthDay(ret._year, ret._month))
	{
	ret._day -= GetMonthDay(ret._year, _month);
	ret._month++;
	if (ret._month == 13)
	{
	ret._year++;
	ret._month = 1;
	}
	}
	return ret;*/

	if (days < 0)
	{
		return *this += -days;
	}
	_day += days;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}

//+�Ļ���ֻ�ǽ������һ������û�б�
Date Date::operator+(int days)
{
	Date ret(*this);
	ret += days;
	return ret;
}

//-=�Ļ��������һ�ˣ�����Ǽ�һ֮��Ľ��
Date& Date::operator-=(int days)
{
	if (days < 0)
	{
		return *this -= -days;
	}
	_day -= days;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

//-�Ļ�������Ǽ�һ֮��ģ�����û�б�
Date Date::operator-(int days)
{
	Date ret(*this);
	ret -= days;
	return ret;
}

//���ڼ����ڣ�����������һ�����ͣ����Ҵ�ļ�С�Ļ�������������������С�ļ���ĵĻ����������ĵĻ��Ǹ���
int Date::operator-(const Date& d)
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}
	return n*flag;
}

//++d -> d.operator++(&d)   ǰ�üӼӣ���֮��������������ֱ�ӱ���
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

//d++ -> d.operator++(&d, 1)   ���üӼӣ���֮��������������ֱ��û��
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}


//d-- -> d.operator--(&d)	ǰ�ü�������֮��������������ֱ�ӱ���
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

//d-- -> d.operator--(&d, 1)	���ü�������֮��������������ֱ��û��
Date Date::operator--(int)
{
	Date tmp(*this);
	tmp -= 1;
	return tmp;
}

bool Date::operator==(const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator<(const Date& d)
{
	return (_year < d._year)
		|| (_year == d._year && _month < d._month)
		|| (_year == d._year && _month == d._month && _day < d._day);
}

bool Date::operator<=(const Date& d)
{
	return *this < d || *this == d;
}

bool Date::operator>(const Date& d)
{
	return !(*this <= d);
}

bool Date::operator>=(const Date& d)
{
	return !(*this < d);
}

bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}


int main()
{
	Date d1(2018, 11, 30);
	d1.Print();

	Date d2(2018, 11, 15);
	d2.Print();

	/*cout << (d1 == d2) << endl;
	cout << (d1 != d2) << endl;
	cout << (d1 < d2) << endl;
	cout << (d1 >= d2) << endl;
	cout << (d1 > d2) << endl;
	cout << (d1 <= d2) << endl;*/

	/*d1 = d2;
	d1.Print();*/

	/*Date d3 = d2 + 100;
	d3.Print();*/
	/*(d2 + 100).Print();
	(d2 += 100).Print();
	(d2 - 100).Print();
	(d2 -= 100).Print();
	(d2++).Print();
	(++d2).Print();
	(d2--).Print();
	(--d2).Print();*/

	cout << d1 - d2 << endl;

	system("pause");
	return 0;
}