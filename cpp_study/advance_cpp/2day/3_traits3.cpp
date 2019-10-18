#include <iostream>
using namespace std;


template<typename T> struct xis_reference {
	static constexpr bool value = false;
};

template<typename T> struct xis_reference <T&> {
	static constexpr bool value = true;
};

template<typename T> struct xis_reference <T&&>{
	static constexpr bool value = false;
};

/*
int main()
{
	cout << xis_reference<int>::value << endl;		// false
	cout << xis_reference<int&>::value << endl;	// true
}
*/
//�׷��� �����ؼ� ���� ������

template<typename T> 
bool xis_reference_v = xis_reference<T>::value;

int main()
{
	cout << xis_reference<int>::value << endl;		// false
	cout << xis_reference<int&>::value << endl;	// true
	cout << xis_reference_v<int&><< endl;	// true
}


//----------------------------
// Template�� 4���� ������ ����.
template<typename T> class list {};						// Ŭ���� ���ø�
template<typename T> void foo(T a) {} ;	// �Լ� ���ø�
template<typename T> using List = list<T>; // using ���ø�
template<typename T> bool v = xis_reference<T>::value // variable template (���� ���ø�)
//v<int> // == xis_pointer<int>::value �� ���� �ǹ�
