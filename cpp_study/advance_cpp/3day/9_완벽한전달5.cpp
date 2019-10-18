#include <iostream>

using namespace std;

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}
// �Ϻ��� �����Ϸ���
// 1. ���ڴ� ���纻�� �����Ǹ� �ȵȴ� - ����
// 2. const�� �ٿ��� �ȵȴ�.
// 3. int& �� int&& ������ �Լ��� 2�� �����Ѵ�.
// const int&, const volatime int& �� ������ �Ѵ�.

// => �Ʒ� �� �ڵ�� perfect forwarding �� ���� ����ϰ� �����Ѱ�. 

template<typename F> void chronometry(F f, int & arg) {
	f(arg);
}


// main -						chronometry -					hoo(int&&)
// 10(rvalue) ���� -> int&& arg (lvalue)  ->		�ٽ� rvalue�� ���� ����
template<typename F> void chronometry(F f, int&& arg) {
	// int&& arg = 10;
	// 10 : rvalue, arg: lvalue	
	//f(arg);
	f(static_cast<int&&>(arg));
}


int main()
{
	int n = 10;
	hoo(10);
	chronometry(hoo, n);
	chronometry(hoo, 10);
}