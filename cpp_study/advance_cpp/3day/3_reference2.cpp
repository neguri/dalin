#include <iostream>

using namespace std;

// __FUNCTION__ : �Լ� �̸� . C++ ǥ��
// __FUNCSIG__ : �Լ� �̸� + signature  (vc++)
//									__PRETTY_FUNCTION__ (g++)


void foo(int& a) { 	cout << __FUNCSIG__ << endl;}
void foo(const int& a) { 	cout << __FUNCSIG__ << endl;}
void foo(int&& a) { 	cout << __FUNCSIG__ << endl;}

int main()
{
	int n = 10;
	foo(n);		// 1�� -> (1�� ������) 2�� ������
	foo(10);	// 3�� -> (3�� ������) 2��

	int& r1 = n; 
	foo(r1);			// 1�� -> (1�� ������) 2�� ������

	int&& r2 = 10;
	// >>>> �߿� !!! ���� ������? 1����. 10�� rvalue ������, r2�� lvalue ��.�׷��� 1������ ����. ������ 2������.
	foo(r2); 
	foo(r2+1);    //  3������ ��. ������ 2��

	foo(static_cast<int&&> (r2));// 3������
	/*
	https://en.cppreference.com/w/cpp/language/static_cast
	If new_type is an rvalue reference type, static_cast converts the value of glvalue, 
		class prvalue, or array prvalue (until C++17)any lvalue (since C++17) expression 
		to xvalue referring to the same object as the expression, 
	*/
	foo(static_cast<int&> (10));   // casting error
	// int&, int&& : ������ Ÿ��
	// rvalue, lvalue: ǥ���Ŀ� ���� �Ӽ�
}