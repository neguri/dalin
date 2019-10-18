#include <iostream>

using namespace std;

template<typename T> struct xreference_wrapper {
	T* obj;
public:
	xreference_wrapper(T& r) : obj(&r) {}
	operator T&() { return *obj; }
};


void foo(int& a) { a = 100; }

template<typename T> void Bind(T arg) {
	foo(arg);
}

template<typename T>
xreference_wrapper<T> xref(T& obj) {
	return xreference_wrapper<T>(obj);
}

int main()
{
	int n = 0; 

	// Bind(&n);   // T�� int* ���� int& �� ��ȯ�� �� ����. error
	
	// xreference_wrapper<int> r(n);
    // Bind(r);  // �ᱹ �ּҸ� ������ ��, �׷��� r�� int& �� ��ȯ ����

	// �ӽ� ��ü�� ������. 
	//Bind(xreference_wrapper<int>(n));
	// �׷��� �� ���.�׷��� ..xreference_wrapper�� ����� �ִ� �Լ��� ����
	Bind(xref(n));
	cout<< n << endl;
}
