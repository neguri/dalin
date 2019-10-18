#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

class Test {
public:
	void operator () (int a, int b) & { cout << "&" << endl; }
	void operator () (int a, int b) && { cout << "&&" << endl; }
};

// �Լ��� ���ڷ� �ް� �ʹ�.
// template<typename T> void foo(const T& func) { (1)
template<typename T> void foo(T&& func) {
	
	// func(1, 2);  // (1) ������ func�� const�� ( ) �����ڰ� const ������� ��. 
	// func(1, 2); // (4) && �� �ƴ� &�� ȣ��. T&& func = T() �ε�, T()�� rvalue ������ func ��ü�� lvalue ��
	std::forward<T>(func)(1, 2);
}

int main()
{
	foo([](int a, int b) { return a + b; });
	Test t; foo(t);
	foo(Test()); // (3) && ȣ���� �Ǳ⸦ ���

}