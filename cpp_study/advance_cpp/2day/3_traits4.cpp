#include <iostream>
#include <type_traits>

using namespace std;


template<typename T> void foo(T a)
{
	bool b = std::is_array<T>::value;
	bool c = std::is_array_v<T>;   // variable template�� c++14 ���� ������
	cout << b << endl;
	cout << c << endl;
}

int main()
{
	int n = 10;
	foo(n);
	foo(&n);
}