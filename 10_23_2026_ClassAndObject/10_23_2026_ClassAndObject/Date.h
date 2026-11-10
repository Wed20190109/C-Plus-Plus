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

	int operator-(const Date& day);//两个日期间隔

	/*
	++,--也能重载,分左右（二元规定左边是第一个参数）
	后置版需要在结尾
	
	*/

	Date operator++(int);//可不加形参名因为不接受
	Date operator++() ;
	//后置++--应复用前置++--,因为后置++--创建了临时变量。前置复用后置会有两次创建临时变量(前置一次后置一次)，后置复用前置只有一次创建
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