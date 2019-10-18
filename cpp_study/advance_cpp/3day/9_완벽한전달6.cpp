#include <iostream>
using namespace std;

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}

// ���
// 1. int&, int&& �� 2���� ������ �Ѵ�
// 2. int&& �������� �ٸ� �Լ��� �����Ҷ� rvalue�� ĳ�����ؼ� ����
/*
template<typename F> void chronometry(F f, int & arg) {
	//f(arg);
	f(static_cat<int&>(arg)); // �ʿ� ���� ĳ����, �־ ���� ���� ����.
}

template<typename F> void chronometry(F f, int&& arg) {
	f(static_cast<int&&>(arg));
}
*/

// n (lvalue) ���� => T: int& t&& :int&
// 10(rvalue) ���� => T: int, T&& : int&&
// ��, �Ʒ� ���ø��� 2��° ���ڰ� n ���� 10������ ���� ���� 2�� �Լ� ����
template<typename F, typename T> void chronometry(F f, T&& arg) {
	
	// �Ʒ� ĳ������ ?
	// 2��° ���ڿ� ���� �ٸ� ĳ������ ��

	// 2��° ���ڰ� 10(rvalue)�� ������ rvalue�� ĳ����
	// 2��° ���ڷ� n(lvalue)�� ������ lvalue�� ĳ����
	//f(static_cast<T&&>(arg)); 

	//�� ����� ���ִ� �Լ��� ����
	f(std::forward<T>(arg));
}

int main()
{
	int n = 10;
	//hoo(10);
	chronometry(hoo, 10);
	chronometry(goo, n);
}