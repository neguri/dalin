#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

// C++�� 4�� ĳ����
// static_cast : �⺻ ĳ����
//							1. ǥ�� Ÿ���� ������ ĳ����
//							2. void* => �ٸ� Ÿ������ ��ȯ ���
//							3. ���ü��� ���� Ÿ���� �ּҴ� ĳ���� �ȵ�.
// reinterpret_cast
// const_cast
// dynamic_cast

int main()
{
	double  d = 3.4;
	int			n = d; // double �̶� data �ս��� ���� �� ����
	int			n_s = static_cast<int>(d);  // ǥ�� Ÿ���� ������ ĳ���� �ϴ� ���� ���

//	int* p1 = malloc(100);  // C���� ���� void *�� �ٸ� �����ͷ� �Ͻ������� �� ��ȯ��
	                                             // C++ �� �ȵ�

	int* p2 = static_cast<int*> (malloc(100));  // C++������ �̷��� �� ��ȯ �ϵ��� ��.

	//int* p3 = static_cast<int*> (&d); // double* -> int* �� ��ȯ. ������ ���� type�̱� ������ �ȵ�. 
																	 //  �� �ؾ� �Ѵٸ� ,reinterpret_cast�� ����ؾ� ��

	// int&& 	r1 = n;
	int&& r1 = static_cast<int&& >(n);  // rvalue�� lvalue�� ����, �� �Ӽ��� �����ϴ� ĳ����
	int&		r2 = 10;
	int&		r2 = static_cast<int&> (10); // ����. lvalue�� r value�� ���� �Ұ�

	// =>> ����� c++������ static_cast<> �� �������.
}