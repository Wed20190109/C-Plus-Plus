#include "Date.h"

//Date Date::operator+=(int d)
//{
//	while (d>0)
//	{
//		GetAMonthDays(d._month);
//	}
//	;
//}
Date Date::operator+=(int day)//+=版，自身会改变
{

	_day+=day;
	while (_day> GetAMonthDays(_year,_month))
	{
		_day -= GetAMonthDays(_year, _month);
		_month++;
		if (_month == 13)
		{
			_month = 1;
			_year++;
		}
	
	}
	return *this;
}
Date Date::operator-=(int day)
{
	_day -= day;
	while (_day < GetAMonthDays(_year, _month))
	{
		_day += GetAMonthDays(_year, _month);
		_month--;
		if (_month == 0)
		{
			_month = 12;
			_year--;
		}
		if (_day > GetAMonthDays(_year, _month))
		{
			_day -= GetAMonthDays(_year, _month);
			_month++;
		}
	}
	
	return *this;
}
//Date Date::operator-=(int day)
//{
//	if (day < _day)
//	{
//		day -= _day;
//		day = -day;
//		_day = day;
//		return *this;
//	}
//	else if (day == _day)
//	{
//		_month--;
//		if (_month == 0)
//		{
//			_year--;
//			_month = 12;
//        }
//		_day = GetAMonthDays(_year, _month);
//	}
//	else
//	{
//		while (day > _day)
//		{
//			day -= _day;
//			_month--;
//			_day = GetAMonthDays(_year, _month);	
//
//			if (day  == _day)
//			{
//				_month--;
//				_day = GetAMonthDays(_year, _month);
//			}
//
//			if (_month == 0)
//			{
//				_month = 12;
//				_day = GetAMonthDays(_year, _month);
//				_year--;
//			}
//			
//		}
//	
//	}
//	
//
//	return *this;
//}

Date Date::operator+(int day)
{
	Date tmp=*this;
	tmp._day += day;
	while (tmp._day > GetAMonthDays(tmp._year, tmp._month))
	{
		tmp._day -= GetAMonthDays(tmp._year, tmp._month);
		tmp._month++;
		if (tmp._month == 13)
		{
			tmp._month = 1;
			tmp._year++;
		}

	}
	return tmp;
}

Date Date::operator-(int day)
{
	Date  tmp = *this;
	if (day < tmp._day)
	{
		day -= tmp._day;
		day = -day;
		tmp._day = day;

		return *this;

	}
	else if (day == tmp._day)
	{
		tmp._month--;
		if (tmp._month == 0)
		{
			tmp._year--;
			tmp._month = 12;
		}
		tmp._day = GetAMonthDays(tmp._year, tmp._month);
	}
	else
	{
		while (day > GetAMonthDays(tmp._year, tmp._month))
		{
			day -= GetAMonthDays(tmp._year, tmp._month);
			tmp._month--;

			if (day -= GetAMonthDays(tmp._year, tmp._month) == 0)
			{
				tmp._month--;
				tmp._day = GetAMonthDays(tmp._year, tmp._month);
			}
			if (tmp._month == 0)
			{
				tmp._month = 12;
				tmp._year--;
			}

		}
	}


	return tmp;
}


int main()
{
	cout << "operator+= Test" << endl;
	Date Today(2026,11,1);
	Today += 100;
	Today.print();

	cout << "operator+ Test" << endl;
	Date Today2(2026, 11, 1);
	Date c=Today2+ 3;
	c.print();

	cout << "operator-= Test" << endl;
	Date Today3(2026, 11, 1);
	Today3 -= 555;
	Today3.print();

	cout << "operator- Test" << endl;
	Date Today4(2026, 11, 1);
	Date d = Today4-100;
	d.print();

}