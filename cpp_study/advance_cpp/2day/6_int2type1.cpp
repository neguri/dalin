#include <iostream>

using namespace std;


// template �� �ι� ������ �Ѵ�.
// 1. T�� ���� ���� �κ��� ������ �����Ѵ�.
//		T�� ������ �ִ� �ڵ�� �������� �ʴ´�.

// 2. ���� ����ϸ� T Ÿ���� �����ǰ�, ���� �Լ�(Ŭ����)�� �ڵ尡 ����
//		������ �Լ��� �ٽ� ������(��������)�Ѵ�.
//		����: c++ template guide 2nd edition

template <typename T> void foo(T a)
{
	*a = 10;
	goo(a);  // ���� �ƴ�
	goo();	// ���� 
}

int main()
{
	
}