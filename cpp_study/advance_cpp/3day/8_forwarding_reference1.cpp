#include <iostream>

using namespace std;

// int&		: int Ÿ���� lvalue�� ����
// int&&		: int Ÿ���� rvalue�� ����
// T&			: ������ Ÿ���� lvalue�� ���� �� �ִ�.
// T&&		: ������ Ÿ�� &, && ��� ���� �� �ִ�. -> 'forwarding reference' ��� �θ�
//					'universal reference' ��� �θ��⵵ ��(effective c++)

void f1(int&) {}  
void f2(int&&) {}   

// T&&   : ������ Ÿ���� lvalue �� rvalue �� ��� �޴´�.
// ���ڷ� n(lvalue   )�� ������		 T: int&,		T&& a: int &
// ���ڷ� 10(rvalue)�� ������		 T:int,			T&& a: int&&
// �ᱹ, f4(int&)�� f4(int&&) �Լ� �ΰ� ��δ� �����ϴ� ��

// T�� ������ Ÿ���̹Ƿ� T& ���� T�� �� �� ����
template<typename T> void f3(T&		a) { 
	cout << "f3: " <<  __FUNCSIG__ << endl;;
}
template<typename T> void f4(T&&  a) {
	cout << "f4: " << __FUNCSIG__ << endl;;
}

int main()
{
	int n = 10;
	// 1. ����ڰ� Ÿ���� ��������� �����ϴ� ��� 
	// <int >�� ���� ��������� Ÿ���� ���� ---> collapsing ��Ģ�� ����
	cout << "f3 : ����� Ÿ�� ����" << endl;
	f3<int>(n);		// T& : int &  f3(int& a) ��� �Լ��� ������
	f3<int&>(n);		//T& : int& &   f3(int& a) ��� �Լ��� ������. (collapsing�� ���ؼ�)
	f3<int&&>(n);		//T& : int&& &   f3(int& a) ��� �Լ��� ������. (collapsing�� ���ؼ�)
	cout << "------------" << endl;
	// 2. ����ڰ� Ÿ���� �������� �ʴ� ���
	// �Լ� ���ڸ� ���� �����Ϸ��� T Ÿ���� �����ؾ� �Ѵ�.
	f3(n);  // T�� int
	
	//f3(10);  // ������ ����. rvalue�� & �� ���� ���� �� ����.

	cout << "f4 : ����� Ÿ�� ����" << endl;
	// 1. Ÿ���� ��������� �����ϴ� ���
	f4<int>(10);					// T&& : int&&			f4(int&& a) ����
	f4<int&>(n);				// T&& : int& &&		f4(int& a) ����  - collaping
	f4<int&&>(10);			// T&& : int&& &&	f4(int&& a) ���� 
	cout << "------------" << endl;
	// 2.	Ÿ���� �������� ������ �����Ϸ��� ���ڸ� ���� Ÿ���� �����ؾ� �Ѵ�
	f4(n);			// T: int&           T&&: int& && => int&  a�� Ÿ��: int&
	f4(10);		// T:int				T&& : int&&  => int&&	a�� Ÿ��: int&&
}