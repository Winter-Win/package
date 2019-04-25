#pragma once

#include <iostream>
#include <stdlib.h>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
private:
	int _year;
	int _month;
	int _day;

public:


	void Print();
	//Date(int year = 0, int month = 0, int day = 0) :_year(year), _month(month), _day(day){}
	int GetMonthDay(int year, int month);
	Date(int year, int month, int day);
	//~Date();
	Date(const Date& d);
	Date& operator=(const Date& d);
	Date& operator+=(int days);
	Date operator+(int days);
	Date& operator-=(int days);
	Date operator-(int days);
	int operator-(const Date& d);
	//++d -> d.operator++(&d)
	Date& operator++();
	//d++ -> d.operator++(&d, 1)
	Date operator++(int);
	//d-- -> d.operator--(&d)
	Date& operator--();
	//d-- -> d.operator--(&d, 1)
	Date operator--(int);

	bool operator==(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator!=(const Date& d);
};
