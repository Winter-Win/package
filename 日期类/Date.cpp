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

//赋值拷贝构造的话，现有一个对象，直接赋值就行，如果现构造的话，就是直接拷贝构造了，没有赋值
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

//+=的话，加了之后，自身也变了，结果出来的也加一了
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

//+的话，只是结果加了一，自身没有变
Date Date::operator+(int days)
{
	Date ret(*this);
	ret += days;
	return ret;
}

//-=的话，自身减一了，结果是减一之后的结果
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

//-的话，结果是减一之后的，自身没有变
Date Date::operator-(int days)
{
	Date ret(*this);
	ret -= days;
	return ret;
}

//日期减日期，减出来的是一个整型，而且大的减小的话，减出来的是整数，小的减大的的话，减出来的的话是负数
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

//++d -> d.operator++(&d)   前置加加，减之后，留下来的自身直接变了
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

//d++ -> d.operator++(&d, 1)   后置加加，减之后，留下来的自身直接没变
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}


//d-- -> d.operator--(&d)	前置减减，减之后，留下来的自身直接变了
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

//d-- -> d.operator--(&d, 1)	后置减减，减之后，留下来的自身直接没变
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