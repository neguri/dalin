#include <iostream>
#include <type_traits>
using namespace std;


template<typename T> void printv(T v)
{
	// (1) �̺κ��� �����ϵǾ ������.
	//if (std::is_pointer<T>::value) {
	
	// (2) C++17 ���� ������ ���� if ��
	// ���ø����� ������ �������� ������ �ڵ带 �������� �ʴ´�.
	if  constexpr (std::is_pointer<T>::value) {
		cout << v << " : " << *v << endl;
	}
	else {
		cout << v << endl;
	}
}


 void printv(int v)
{
	 // (3) �����Ϸ��� �Ʒ��� ���� �Լ��� ����� ��.
	 // ������ ���� �����Ƿ�, ������ �Ǵ°��� �ƴϰ� �ƿ� �ڵ� ���� �ȵ�.
	 // /std:c++latest �� �߰��ؼ� �����ؾ���. (Ȥ�� std:c++17)
	if  constexpr (false) {
		
	}
	else {
		cout << v << endl;
	}
}



int main()
{
	int n = 10;
	printv(n);
	printv(&n);
}