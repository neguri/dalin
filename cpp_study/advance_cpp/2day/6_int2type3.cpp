#include <iostream>
#include <type_traits>
using namespace std;

// �̷��� ���� ���� ������ �߻���.
// �����Ϸ��� printv_pointer( ) ������� ������ ��

template<typename T> void printv_pointer(T v)
{
	cout << v << " : " << *v << endl;
}

template<typename T> void printv_not_pointer(T v)
{
	cout << v << endl;
}

template<typename T> void printv(T v)
{
	if (std::is_pointer<T>::value) {
		printv_pointer(v);
	}
	else {
		printv_not_pointer(v);
	}
}

int main()
{
	int n = 10;

	printv(n);
	printv(&n);
}