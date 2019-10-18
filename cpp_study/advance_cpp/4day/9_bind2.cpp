#include <iostream>
#include <functional>

using namespace std;
using namespace std::placeholders;

void foo(int a, int b, int c, int d) {
	printf("%d %d %d %d\n", a, b, c, d);
}

void goo(int) { cout << "goo" << endl; }

int main()
{
	// �Ϲ� �Լ� ������ ����
	// 1. �Լ��� ��´�. �Լ� ��ü�� ���� �� ����. 
	// 2. ������ ������ �ٸ� �Լ��� ���� �� ����. 
	void(*func)(int);


	// C++ : �Լ� ������ ��� function�� ������� C++11
	function<void(int)> f;   
	f = bind(&foo, 1, 2, 3, _1); // ȣ���� �ƴϰ� f ��� �Լ��� ���� ����.
	f(10);
	
	f = [](int a) { cout << "lambda" << endl; };
	f(10);

	// C++ GUI ���Է��� : nana (C++11/14�� Ȱ���� ���̺귯��)

}