#include <iostream>
#include <type_traits>

using namespace std;

template<typename T> void foo(T a) {
	// T�� ������ ���ο� ���� �ٸ� �� �ϱ�
	if (is_pointer<T>::value) {

		// *a = 10; �� ���� �� �����ϴ� �ҽ��� ����� �� ����
		// 1. *a = 10 �� ���� �ҽ��� ����Ϸ���, if constexpr ���
		// 2. true_type, false_type���� �����ε�
	}
	else {

	}

	if constexpr (is_pointer<T>::value) {
		*a = 10;
	}

	foo_imp(a, is_pointer<T>());
}

template<typename T> void foo_imp(T a, true_type) {}
template<typename T> void foo_imp(T a, false_type) {}

// 3. �Լ� ���ø��� 2�� ����� enable_if �� ���ǿ� ���� ����ϵ��� ��.
template<typename T>
typename enable_if<is_pointer<T>::value>::type foo(T a) {}

template<typename T>
typename enable_if<!is_pointer<T>::value>::type foo(T a) {}

// ����� ���� ������ true_type/false_type -> enable_if -> if const_expr

int main()
{

}