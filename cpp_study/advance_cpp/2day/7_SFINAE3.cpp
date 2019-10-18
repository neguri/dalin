// 215 page
#include <iostream>
using namespace std;

void foo(...) { cout << "..." << endl; }
template<typename T> void foo(T a) { 
	typename T::type n;   // T �� int �̸� ���� �߻�
}


// SFINAE �� �Ʒ� 3���� ��츸 ��� ����
// 1. �Լ� ��ȯ Ÿ�� - ���� �θ� ���
template <typename T> typename T::type foo(T a) { return 0; }

// 2. �Լ� ���� : �������ڵ�, ��ȯ Ÿ���� ���� ��쿡 �ַ� ���
template<typename T> void foo(T a, typename T::type a = 0) {}

// 3. ���ø� ���� - �Լ� ��ü�� ����� �������� ���� ������ �ִ�
template<typename T, typename T2 = typename T::type> void foo(T a) {}
int main()
{
	foo(10);
}