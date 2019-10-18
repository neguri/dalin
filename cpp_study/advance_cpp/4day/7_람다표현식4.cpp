#include <iostream>
using namespace std;

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}
void koo(int a, int b, int c) {}
void joo() {}

// C++11 �������� ���ø�
// return ������ ���� �ְ�, ���� ���� �ְ�. �׷��� decltype(aut0)�� �ٿ���
template<typename F, typename ... T>
decltype(auto) chronometry(F&&  f, T&& ...arg) {
	return invoke(std::forward<F> (f),
								std::forward<T>(arg)...);
}

int main()
{ 
	hoo(1);
	chronometry(hoo, 10);
	chronometry(koo, 10, 20, 30);
	chronometry(joo);
}