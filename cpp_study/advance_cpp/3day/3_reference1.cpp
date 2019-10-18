#include <iostream>

using namespace std;

int main()
{
	// ���۷��� ��Ģ
	// 1. non const lvalue reference�� lvalue�� ����Ų��
	int n = 0;
	int& r1 = n;					// 0k
	int& r2 = 10;				// error

	// 2. const reference�� lvalue �� rvalue ��� ����Ų��
	// ���� : rvalue�� �׻� const �� ���� �ƴϴ� . Point(0, 0)�� �ӽ� ��ü�� ������ ���
	const int& r3 = n;			//ok
	const int& r4 = 10;		// ok
	//ARM(annotated reference manual)�� ���� ����

   // 3. C++11 . const ���� rvalue ����Ű�� ������ �ʿ��ߴ�.
	// rvalue reference�� rvalue�� ����ų �� �ִ�.
	int&& r5 = n;			// error 
	int&& r6 = 10;		// ok
}