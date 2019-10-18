#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

void goo(int a, int b) { cout << "goo" << endl; }

template<typename T, typename... ARGS> 
void foo(T&& f, ARGS&& ... args) {
	f(std::forward<ARGS>(args)...);
}


int main()
{
	foo(goo,1,2);

	// ��� �Լ� ������ ����� ���
	//void(Test::*f)(int) = &Test::hoo; // �ٽ� 1

	// f(1,2); // error ��ü�� ����

	Test test;
	// test.f(10); // error. f��� ��� �Լ��� ����.
}