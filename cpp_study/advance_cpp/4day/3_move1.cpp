#include <iostream>
#include <type_traits>

using namespace std;

template<typename T> void foo(T a)
{
	// type traits ����� ����

	// 1. Ÿ�� ���� - T�� Ÿ���� ���� �� �ִ�.
	bool b1 = is_pointer<T>::value;     // C++11
	bool b2 = is_pointer_v<T>;				// C++ 14

	//2. ����� Ÿ�� ��� - ������ ������ Ÿ���� ���ϱ�.
	//remove_pointer<T>::type n;  -> type�� ������, type���� �𸣴� typename�� ����� ��.
	typename remove_pointer<T>::type n;
	remove_pointer_t<T> n2;    //C++ 11
}

int main()
{

}