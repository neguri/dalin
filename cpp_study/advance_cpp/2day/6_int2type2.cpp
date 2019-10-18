#include <iostream>
#include <type_traits>
using namespace std;
/*
template<typename T> void printv(T v)
{
	if (std::is_pointer<T>::value) {
		cout << v << " : " << *v << endl;
	}
	else {
		cout << v << endl;
	}
}
*/

template<typename T> void printv(T v)
{
	if (std::is_pointer<T>::value) {
		cout << v << " : " << *v << endl;
	}
	else {
		cout << v << endl;
	}
}

/*
�̷��� �����Ϸ��� ����µ�, int�� ���ؼ� *v�� �Ҽ� ����. ���� ����. 
�̸� �ذ��ؾ� ��.
3���� ����� ���� (ù��°�� c++17�� �ִ� if constexpr)
void printv(int v)
{
	if (false) {
		cout << v << " : " << *v << endl;
	}
	else {
		cout << v << endl;
	}
}
*/

int main()
{
	int n = 10;

	//printv(n);
	printv(&n);
}