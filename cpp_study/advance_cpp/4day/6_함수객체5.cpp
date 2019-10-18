#include <iostream>
#include <bitset>
using namespace std;

// 1. �Ϲ� �Լ��� �ڽŸ��� Ÿ���� ����.
//		signature(���� ���ڿ� ����)�� �����ϸ� ���� Ÿ��
// 2. �Լ� ��ü�� �ڽŸ��� Ÿ���� �ִ�.
//		signaure�� �����ص� �ٸ� Ÿ��

struct Plus {
	inline int operator() (int a, int b) { return a + b; }
};

struct Minus {
	inline int operator() (int a, int b) { return a - b; }
};

// void foo(Plus p)
// ���ڷ� �پ��� ��å(�Լ�)�� ���� �� �ִµ�, 
// ��å�� �ζ��� ġȯ�� ������ �ڵ�
// �Լ� ��ü + ���ø����� ����� ���
template<typename T> 
void foo(T f) 
{
	int n = f(1, 2);  
}


int main()
{
	Plus p; foo(p);			// foo(Plus) �Լ� ����
	Minus m; foo(m);		// foo(Minus) �Լ� ����
}