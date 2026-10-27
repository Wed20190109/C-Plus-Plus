#include <iostream>
using namespace std;
/*
类
*/
//创建类
//访问限定符： public,private,protected
class Stack//class类,默认划给private
{

public:
	void Init();
private:
	int _capacity;//只是声明，未定义。
	//成员变量一般在开头加_方便区分，当然不是硬性要求

};

struct Queue//struct类,默认划给public
{

public:
	void Init();
private:
	int _capacity;
	void print();
};

//C++兼容C的struct的用法


//类定义了⼀个新的作⽤域，类的所有成员都在类的作⽤域中，在类体外定义成员时，需要使⽤::作    \
⽤域操作符指明成员属于哪个类域。

int main1()
{
	Queue A;//创建对象A
	return 0;
}


/*
隐含指针this
*/
/*

Date类中有Init与Print两个成员函数，函数体中没有关于不同对象的区分，那当d1调⽤Init和
Print函数时，该函数是如何知道应该访问的是d1对象还是d2对象呢？那么这⾥就要看到C++给了
⼀个隐含的this指针解决这⾥的问题

编译器编译后，类的成员函数默认都会在形参第⼀个位置，增加⼀个当前类类型的指针，叫做this
指针。⽐如Date类的Init的真实原型为，
void Init(Date* const this, int year,
int month, int day)

类的成员函数中访问成员变量，本质都是通过this指针访问的，如Init函数中给_year赋值，
>_year = year;
this

C++规定不能在实参和形参的位置显⽰的写this指针(编译时编译器会处理)，但是可以在函数体内显
⽰使⽤this指针。

*/
class Date1
{

public:
	// void Init(Date* const this, int year, int month, int day)
	void Init(int year=2,int month=4, int day=4)
	{
		// 		编译报错：			
		// error C2106 : “ = ” :左操作数必须为左值

			// this = nullptr;
			// this->_year = year
		this->_year = year;
		this ->_month = month;
		this ->_day = day;
		
	}
	void print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date1 d1;
	Date1	d2;
	// d1.Init(&d1, 2024, 3, 31);
	d1.Init(2026, 10, 27);
	d2.Init(2026, 10, 26);

	d1.print();
	d2.print();


}




class ExampleA
{
public:
	void Print()
	{
		cout << "A::Print()" << endl;
	}
private:
	int _a;
};

int main22()
{
	ExampleA* p = nullptr;
	p->Print();//ExampleA能运行
	return 0;
}


class ExampleB
{
public:
void Print()
{
cout << "A::Print()" << endl;
cout << _a << endl;
}
private:
int _a;
};
int main23()
{
	ExampleB* p = nullptr;
	p->Print();//ExampleB却不能运行
	return 0;
}


/*
构造函数
*/
//构造函数不是字面上的创造开空间,而是初始化作用
class Date
{
public:
	//使用规则:
	Date()//直接使用类名
	{
		_year = 1;
		_month = 1;
		_day = 1;
	}

	Date(int year, int month, int day)//全缺省函数也算构造函数
	{
		_year = year;
		_month = month;
		_day = day;
	}//虽然全缺省构造函数与直接使用类名构造函数构成函数重载但是有语法歧义

	//第三种就是没有显式创建的构造函数编译器自己创建的构造函数并初始化(不同编译器各不同),但往往不尽人意(初始化的值多是无用值比如随机值)

	void print()
	{
		cout << _year<<"-" << _month <<"-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main2()
{
	Date B(1,2,3);
	B.print();
	Date B1;//用无参构造函数时不能加(),不然会识别成 函数
	B1.print();

	return 0;
}
/*
析构函数
*/
//析构函数并不是构造函数的反义，或者反作用。而是释放空间
//一个类只能有一个析构函数，若没有显式定义则编译器自己搞一个
//
typedef int STDataType;
class Stack3
{
public:

	void Date()
	{
		int year;
		int month;
		int day;
	}
	/*
	有资源申请的情况存在时一定要自己定义析构，不然可能会导致内存泄露；没有申请资源的情况如Date可以不用写析构，用编译器生成的
	*/
	Stack3( int n) 
	{
		_a = (STDataType*)malloc(sizeof(STDataType) * n);
		if (_a == nullptr)
		{
			perror("malloc fail");
		}
	}

	~Stack3()//析构函数为：~类名() 
	{
		free(_a);
		_top = 0;
		_capacity = 0;
	}
private:
	STDataType * _a;
	int _top;
	int _capacity;
};