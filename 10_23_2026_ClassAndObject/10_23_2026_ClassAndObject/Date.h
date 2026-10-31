#pragma once
#include <iostream>

using namespace std;


class Date 
{

public:
	int GeAMonthDays()
	{
		int Month[] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
		
		
		/*if (_year%4==0&&_year&100!=0||_year%400==0)
		{
			Month[2]=29;
		}*/

	}


private:
	int _year;
	int _month;
	int _day;
};