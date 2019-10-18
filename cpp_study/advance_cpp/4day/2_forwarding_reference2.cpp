#include <iostream>

template<typename T> class Test {
public:
	void foo(T&& arg) {}

	template<typename U> void goo(U&& arg) {}
};

int main()
{
	int n = 0;

	Test<int> t; //  �� ���� T�� Ÿ���� ������. int

	t.foo(n); // error .forwarding reference�� �Ƿ���, ȣ���ϴ� ���� Ÿ���� �����Ǿ�� ��. 
					// ������ ������ ȣ���ϱ� ������ T��int�� Ÿ���� �����Ǿ� ����
					// Test �� class template�̰�  foo( )�� �Լ��� ���ø��� �ƴ�. 
					//&&�� ��� Ÿ���� �� ��������, ���� ������ �ƴ϶� ���� ������ ���� ���� �Ǿ�� ��.
	t.foo(10);

	t.goo(n);  // goo�� �Լ��� ���ø� ��.  goo�� & �� && �ΰ��� �Լ��� ������
	t.goo(10);
}