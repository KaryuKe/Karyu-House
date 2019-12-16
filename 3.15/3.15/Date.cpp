#include<iostream>
#include "Date.h"
using namespace std;
Date::Date(int m1,int d1,int y1)
{
	setMonth(m1);
	setDay(d1);
	setYear(y1);
}
void Date::setDay(int d1)
{
	d = d1;
}
void Date::setYear(int y1)
{
	y = y1;
}
void Date::setMonth(int m1)
{
	if (m1 <= 12)
	{
		if (m1 >= 1)
			m = m1;
		else m = 1;
	}
	else
		m = 1;
}
int Date::getDay()
{
	return d;
}
int Date::getMonth()
{
	return m;
}
int Date::getYear()
{
	return y;
}
void Date::displayDate()
{
	cout << getMonth() << "/" << getDay() << "/" << getYear() << endl;
}