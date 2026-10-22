#include <iostream>


namespace std//命名域，里面可放置变量，函数等。以解决C语言的命名冲突问题
{

}

using namespace std;//域完全展开:解除域限制,不应该在大型项目合作项目中使用否则会可能发生命名冲突

using std::cout;//域部分展开

void print(int a, int b = 337, int c = 1457);//不完全缺省

int main1()
{
	int a;
	std::cout << "Terraria" << endl;//;: 为域限定符,前面是域
	cout << "TheJourneyBegins--Relogic" << endl;// << 为
	cout << "please input:"<<endl;
	cin >> a;// >> 为
	cout << a << endl;

	print(1);
	print(1,2,3);
	return 0;

}


/*
缺省值
*/
//函数结构里可以赋予默认值，但缺省值必须从右往左
//这样做对应着传形式参数时只能从左往右传，不能跳跃着传
void print(int a, int b,int c)
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}





/*

函数重载

*/

/*
引用
*/
//权限放大缩小
int main()//引用相当于别称,语法上相较于指针不用开辟空间
{
	int a = 0;
	int& a1 = a;
	int& a2 = a;
	a2 = 666;
	cout << a2 << endl;

	const int b = 0;
	//int &b1 = b;//因为b被const修饰,b1属于权限放大，不可以
	const int & b1 = b;
	

	int c = 0;
	const int& c1 = c;//而权限缩小，可以

	int& d = b + c;//b+c被看作表达式，会产生临时变量，也是常量，不能去别名
	const int& d1 = b + c;//但是加const缺可以

	float e = 3.37;
	int& f = e;//给浮点数取int型别名会发生隐性类型转换，也会产生临时变量
	const int & f1 = e;//加const也是不会

	int& g = 555;//常量不能取别名
	const int& g1 = 555;//加const可以


}

/*
inline 
*/