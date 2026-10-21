#include <iostream>


namespace std//命名域，里面可放置变量，函数等。以解决C语言的命名冲突问题
{

}

using namespace std;//域完全展开:解除域限制,不应该在大型项目合作项目中使用否则会可能发生命名冲突

using std::cout;//域部分展开

void print(int a, int b = 337, int c = 1457);

int main()
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

引用
*/