#include <iostream>
#include <functional>

using namespace std;
using namespace std::placeholders;

void foo(int a, int& b) { b = 100; }

int main()
{
	function<void(int)>f;
	/* 
	{
	int n = 0;
	f = bind(&foo, _1,n);  // n�� ���� �����ؼ� ����. ����� ����� �ı�.
	}
	*/

	int n = 0;
	f = bind(&foo, _1, ref(n));  // << ref�� ��� ���峪?
	f(10);
	cout << n << endl;
}