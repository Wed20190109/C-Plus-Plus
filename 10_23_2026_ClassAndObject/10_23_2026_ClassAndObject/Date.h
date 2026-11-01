#pragma once
#include <iostream>

using namespace std;



class Date 
{

public:
	void print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	Date(int year,int month,int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	bool operator<(const Date& day);
	bool operator<=(const Date& day);
	bool operator>(const Date& day);
	bool operator>=(const Date& day);
	bool operator==(const Date& day);
	bool operator!=(const Date& day);

	Date operator+=(int day);
	Date operator+(int day);

	Date operator-(int day);
	Date operator-=(int day);

	int operator-(const Date& day);

	int GetAMonthDays(int year,int month)//判断天数增加时该月的天数上限，月进位后会动态变化
	{

		int Month[] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
		
		if (month==2&&((year%4==0&&year%100!=0)||year%400==0))
		{
			Month[2] = 29;
		}
		else
		{
			Month[2] = 28;
		}
		return Month[month];
	}


private:
	int _year;
	int _month;
	int _day;
};