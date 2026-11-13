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
	
	while (day>0)
	{
		if (_day > day)
		{
			_day -= day;
			day = 0;
			
		}
		else//_day<day
		{
			day -= _day;
			_month--;
			if (_month == 0)
			{
				_month = 12;
				_year--;

			}
			_day = GetAMonthDays(_year, _month);
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

//Date Date::operator-(int day)
//{
//	Date tmp = *this;
//	
//	while (day > 0)
//	{
//		if (tmp._day > day)
//		{
//			tmp._day -= day;
//			day = 0;
//
//		}
//		else
//		{
//			day -= tmp._day;
//			tmp._month--;
//			if (tmp._month == 0)
//			{
//				tmp._month = 12;
//				tmp._year--;
//
//			}
//			tmp._day = GetAMonthDays(tmp._year, tmp. _month);
//		}
//	}
//
//	return tmp;
//}

Date Date::operator-(int day)//这里不写完整的 while (tmp._day > GetAMonthDays(tmp._year, tmp._month)) 的话是因为重载复用
{
Date tmp = *this;
tmp -= day;//这里的 "-=" 是Date Date::operator-=(int day)的-=复用
return tmp;

}

bool Date::operator<(const Date &day)
{

	if (_year != day._year)
	{
		return _year < day._year;
	}
	if (_month != day._month)
	{
		return _month < day._month;
	}
	return _day < day._day;
	
}

bool Date::operator==(const Date& day)
{
	return (_year == day._year &&
		_month == day._month &&
		_day == day._day);
}

bool Date::operator<=(const Date& day)
{
	return (*this < day) || (*this == day);
}

bool Date::operator>(const Date& day)
{
	return !(*this == day) && !(*this< day);
}

bool Date::operator>=(const Date& day)
{
	return (*this > day) || (*this == day);
}


bool Date::operator!=(const Date& day)
{
	return !(*this == day);
}

Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;
	return tmp;
}

Date Date::operator++()
{
	*this += 1;
	return *this;
}

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	cout << "请输入年月日";
	in >> d._year >> d._month >> d._day;
	if(d.CheckDay())
	return in;
}

bool Date::CheckDay()
{
	if (_month < 1 || _month>12 || _day<1 || _day>GetAMonthDays(_year, _month))
	{
		return false;
	}
	else {
		return true;
	}
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
	Today3 -= 100;
	Today3.print();

	cout << "operator- Test" << endl;
	Date Today4(2026, 11, 1);
	Date d = Today4-100;
	d.print();

	cout << "operator< Test" << endl;
	Date Today5(2026, 11, 9);
	Date Today51(2026, 11, 10);
	cout << (Today51 == Today5) << endl;

}