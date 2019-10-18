#include <iostream>

using namespace std;

// ��� �������� ���� �� �ִ� �Լ��� ����� �ʹ�.

// ��� 1.  call by falue
// Ư¡ : ���纻�� ����, ũ�Ⱑ ū Ÿ���� ��� ������尡 �ִ�.
//void foo(int a) {}

// ��� 2. call by reference
// Ư¡ : lvalue�� �����ϴ�
//void foo(int& arg) {}

// ��� 3. call by  const lvalue reference
// Ư¡ : ���纻�� �ƴ����� const �̹Ƿ� ���� ������ �Ұ���
//void foo(const int& arg) {}

// ��� 4. �Լ��� 2�� �����.
// Ư¡ : ������ const �߰� ���� �״�� ���� �� �ִ�.
//				�� 2���� �Լ��� ������ �Ѵ�.
//void foo( int& arg) {}
//void foo( int&& arg) {}

//��� 5. forwarding reference�� ����ϸ� �ڵ����� 2���� �Լ��� �����ȴ�.
template<typename T> void foo(T&& arg) {
	cout << __FUNCSIG__ << endl;
}

int main()
{
	int n = 10;
	foo(n);  // T : int&  arg: int&
	foo(10);// T: int arg:int&&
	const int c = 10;
	foo(c);
	/*
	void __cdecl foo<int&>(int &)
	void __cdecl foo<int>(int &&)
	void __cdecl foo<const int&>(const int &)
	*/
}