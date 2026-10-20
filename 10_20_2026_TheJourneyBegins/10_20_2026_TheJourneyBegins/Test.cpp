#include <iostream>
#include <stdlib.h>

namespace std//命名域，里面可放置变量，函数等。以解决C语言的命名冲突问题
{

}

using namespace std;//域完全展开:解除域限制,不应该在大型项目合作项目中使用否则会可能发生命名冲突

using std::cout;//域部分展开

int main()
{
	int a;
	std::cout << "Terraria" << endl;//;: 为域限定符,前面是域
	cout << "TheJourneyBegins--Relogic" << endl;
	cin >> a;
	cout << a << endl;
	return 0;

}


/*
缺省值
*/




/*

函数重载

引用
*/