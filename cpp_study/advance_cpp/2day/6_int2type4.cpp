#include <iostream>
#include <type_traits>
using namespace std;

// �̷��� ���� ���� ������ �߻���.
// �����Ϸ��� printv_pointer( ) ������� ������ ��

template<typename T> void printv_imp(T v, YES)
{
	cout << v << " : " << *v << endl;
}

template<typename T> void printv_imp(T v, NO)
{
	cout << v << endl;
}

template<typename T> void printv(T v)
{
	// if ���� ���� �б� : ���� �ð� �б� (������ �Ҷ��� �����Ѵٰ� ����)
	/*
	if (std::is_pointer<T>::value) {
		printv_pointer(v);
	}
	else {
		printv_not_pointer(v);
	}
	*/

	// �Լ� �����ε��� ���� �б� : ������ �ð� �б�
	printv_imp(v, ? );

}

int main()
{
	int n = 10;
	printv(n);
	printv(&n);
}