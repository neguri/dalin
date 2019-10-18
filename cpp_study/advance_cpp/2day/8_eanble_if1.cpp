// page 77
#include <iostream>

using namespace std;

// C++11 ���� enable_if �� ǥ����

template<bool b, typename T = void> struct enable_if {
	typedef T type;
};

// �κ� Ư��ȭ �Ҷ��� T = void �� ���� default �� ����� �� ����.
template< typename T> struct enable_if <false, T>{
	
};

int main()
{
	enable_if<true, int>::type				n1;	// int �� ��.
	enable_if<true, double>::type		n2;	 // double �� ��
	enable_if<true>::type						n3;  // void Ÿ���� ��. ������ void ������ ���� �� �����Ƿ� error

	enable_if<false, int>::type				n4;  //error. type ��ü�� �������� ����.
}