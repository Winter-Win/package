#include "Date.h"

void Date::Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

//获取合法日期，day
int Date::GetMonthDay(int year, int month)
{
	static const int MonthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && 
		(year % 4 == 0 && year % 100 != 0) || 
		year % 400 == 0)
	{
		return 29;
	}

	return MonthArray[month];
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

//d2(d1);
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	return *this;
}

Date& Date::operator+=(int days)
{
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

Date Date::operator+(int days)
{
	Date ret(*this);
	ret += days;
	return ret;
}

Date& Date::operator-=(int days)
{
	if (days < 0)
	{
		return *this -= -days;
	}
	_day -= days;
	while (_day <= 0 || _day > GetMonthDay(_year, _month))
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}

	return *this;
}

Date Date::operator-(int days)
{
	Date ret(*this);
	ret -= days;
	return ret;
}

int Date::operator-(const Date& d)
{
	Date Max = *this;
	Date Min = d;
	int flag = 1;
	if (*this < d)
	{
		Max = d;
		Min = *this;
		flag = -1;
	}
	int n = 0;
	while (Min != Max)
	{
		++Min;
		++n;
	}
	return n * flag;
}

//++d -> d.operator++(&d) 前置++，返回的是值变了的
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

//d++ -> d.operator++(&d, 1) 后置++，返回的是值未变的
Date Date::operator++(int)
{
	Date ret(*this);
	*this += 1;
	return ret;
}

//d-- -> d.operator--(&d) 前置--，返回的是值变了的
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

//d-- -> d.operator--(&d, 1) 后置--，返回的是值未变的
Date Date::operator--(int)
{
	Date ret(*this);
	*this -= 1;
	return ret;
}


bool Date::operator==(const Date& d)
{
	return (_year == d._year) &&
		(_month == d._month) &&
		(_day == d._day);
}

bool Date::operator<(const Date& d)
{
	return (_year < d._year) ||
		((_year == d._year) && (_month < d._month)) ||
		((_year == d._year) && (_month == d._month) && (_day < d._day));
}

bool Date::operator<=(const Date& d)
{
	return (*this < d) || (*this == d);
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


//引用  保证支持连续输出
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "-" << d._month << "-" << d._day << endl;

	return out;
}

istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;

	return in;
}