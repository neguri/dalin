#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

// �Ʒ� �� �Լ��� ���� Ÿ���� �ٸ� �Լ�
inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

struct Less {
	inline bool operator()(int a, int b) { return a < b; }
};

struct Greater {
	inline bool operator()(int a, int b) { return a > b; }
};


template<typename T> void foo(T f) {
	bool b = f(1, 2);
}

int main()
{
	Less f1;
	Greater f2;

	foo(cmp1);		// T: bool(*) (int,int)
	foo(cmp2);		// T: bool(*) (int,int)
	foo(f1);				// T: Less
	foo(f2);				//T: Greater

	// 1. ������ �ϸ� foo �Լ��� � �����ǳ�?  +>3��
	// 2. foo�� �����ϰ� �Լ��� � �ִ°�?
   // D:\supari\advcpp\4day > cl 6_�Լ���ü7.cpp / FAs / Ob1
	//	/Ob1 : �ζ��� ġȯ ����
	// /FAs: ����� �ҽ� ����� �޶�� 
}