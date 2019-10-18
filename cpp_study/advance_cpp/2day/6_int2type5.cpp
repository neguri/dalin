#include <iostream>
#include <type_traits>
using namespace std;

template<int N> struct int2type {
	enum { value = N };
};

template<typename T> void printv_imp(T v, int2type<1>) {
	cout << v << " : " << *v << endl;
}

template<typename T> void printv_imp(T v, int2type<0>) {
	cout << v << endl;
}

template<typename T> void printv(T v){
	printv_imp(v,		int2type<is_pointer<T>::value>());
							// int2type<0> �� �ϸ� Ÿ���� �ǹǷ�, ( ) �� �ٿ��� �ӽ� ��ü�� ����.
							// �Լ��� ���޵Ƿ��� type�� �ƴ϶� ���̳� ��ü�� �Ѿ�� ��.
}

int main()
{
	int n = 10;
	printv(n);
	printv(&n);
}

// �ᱹ ������ Ÿ������ ���� �����
// ���ڷ� �Լ��� �����ε� �ϰ� ��.