#include <iostream>
#include <bitset>
using namespace std;

			int Add1(int a, int b)	{ return a + b; }
inline int Add2(int a, int b)	{ return a + b; }
inline int Sub(int a, int b)		{ return a - b; }

// 1. �ζ��� �Լ��� ������ �ð��� �̷������ �����̴�.
// 2. �ζ��� �Լ��� �Լ� �����Ϳ� ��Ƽ� ȣ���ϸ� ġȯ�� �� ����.

void foo(int(*f)(int, int))  // � �Լ��� ������ �� �� ����.
{
	int n = f(1, 2);
}

int main()
{
	Add1(1, 2);			//	ȣ��
	Add2(1, 2);			// ġȯ. ������

	foo(Add2);			// ȣ��
	int(*f)(int, int) = &Add2;
	f(1, 2);


}