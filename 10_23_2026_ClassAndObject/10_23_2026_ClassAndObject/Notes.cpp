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
	void Init(int year=2,int month=4, int day=4)//形参位置里不能写this
	{
		// 		编译报错：			
		// error C2106 : “ = ” :左操作数必须为左值

			// this = nullptr;
			// this->_year = year
		/*
		类里允许显式写，但不需要，编译器会自动加
		*/
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

int main2()
{
	Date1 d1;
	Date1	d2;
	// d1.Init(&d1, 2024, 3, 31);
	d1.Init(2026, 10, 27);
	d2.Init(2026, 10, 26);

	d1.print();
	d2.print();

	return 0;
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

int main3_1()
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
int main3_2()
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

	//第三种就是没有显式创建的构造函数编译器自己创建的构造函数并初始化(不同编译器各不同),但往往不尽人意(初始化的值多是无用值比如随机值) \
	不一定能满足需求

	void print()
	{
		cout << _year<<"-" << _month <<"-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main4()
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


/*
拷贝构造函数
*/
//拷贝构造函数是构造函数的一种重载，其第一个对象必须是类类型的引用

class Date2
{
public:
	Date2()
	{
		_year = 1;
		_month = 1;
		_day = 1;
	}

	Date2(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date2(Date2& d)//拷贝构造函数
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	Date2(Date2* d)
	{
		_year = d->_year;
		_month = d->_month;
		_day = d->_day;
	}
	/*
	Date2(Date2 d)//错误写法
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	*/

	void print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
void func(Date2 d)
{
	cout << &d << endl;
	d.print();
}

Date2& func2()
{
	Date2 tmp(2026, 10, 31);
	tmp.print();
	return tmp;//传引用返回
}

int main()
{
	Date2 a(2026, 10, 31);
	Date2 b(a);// C++规定⾃定义类型对象进⾏拷⻉⾏为必须调⽤拷⻉构造，所以这⾥传值传参要调⽤拷贝构造
	// 	所以这⾥的a传值传参给d要调⽤拷⻉构造完成拷⻉，传引⽤传参可以较少这⾥的拷⻉

	func(a);
	
	cout << &a << endl;
	b.print();
	Date2 c = a;
	c.print();
	//假设在class Date2中的构造拷贝函数为
	/*
	Date2(Date2 d)//拷贝构造函数但没有&
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	再进行拷贝构造
	Date a(2026, 10, 31);
	Date b1(a);
	b1.print();//若这样做会造成 Date2(Date2 d) 的无限递归

	*/

	Date2 d(&a);//这是拷贝，是存在于类里的普通构造
	d.print();


	// Func2	返回了⼀个局部对象	tmp		的引⽤作为返回值

		// Func2		函数结束，		tmp	对象就销毁了，相当于了⼀个野引⽤
	Date2 ret = func2();

	ret.print();//在func2中传引用返回后栈帧被销毁,变成野引用

	return 0;
}

typedef int STDataType;
class Stack4
{
public:
	Stack4(int n = 4)
	{
		_a = (STDataType*)malloc(sizeof(STDataType) * n);
		if (nullptr == _a)
		{
			perror("malloc				申请空间失败	");
			return;
		}
		_capacity = n;
		_top = 0;
	}
	Stack4(const Stack4& st)
	{
		// 		需要对			_a指向资源创建同样⼤的资源再拷⻉值

		_a = (STDataType*)malloc(sizeof(STDataType) * st._capacity);
		if (nullptr == _a)
		{
			perror("malloc			申请空间失败			!!!");
			return;
		}
		memcpy(_a, st._a, sizeof(STDataType) * st._top);
		_top = st._top;
		_capacity = st._capacity;
	}
	void Push(STDataType x)
	{
		if (_top == _capacity)
		{
			int newcapacity = _capacity * 2;
			STDataType* tmp = (STDataType*)realloc(_a, newcapacity *
				sizeof(STDataType));
			if (tmp == NULL)
			{
				perror("realloc fail");
				return;
			}
			_a = tmp;
			_capacity = newcapacity;
		}
		_a[_top++] = x;
	}
	~Stack4()
	{
		cout << "~Stack()" << endl;
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}
private:
	STDataType* _a;
	size_t _capacity;
	size_t _top;
};
// 两个Stack实现队列

class MyQueue4
{
public:
private:
	Stack pushst;
	Stack popst;
};
//
//int main6()
//{
//	Stack4 st1;
//	st1.Push(1);
//	st1.Push(2);
//	// Stack	不显⽰实现拷⻉构造，⽤⾃动⽣成的拷⻉构造完成浅拷⻉
//
//		// 		会导致st1和st2⾥⾯的_a指针指向同⼀块资源，析构时会析构两次，程序崩溃
//
//		Stack4 st2 = st1;
//	MyQueue4 mq1;
//	// MyQueue⾃动⽣成的拷⻉构造，会⾃动调⽤Stack拷⻉构造完成	pushst / popst
//		// 的拷⻉，只要Stack拷⻉构造⾃⼰实现了深拷⻉，他就没问题
//
//		MyQueue4 mq2 = mq1;
//	return 0;
//}


//传值返回。传引用返回




/*
赋值重载，局部对象
*/