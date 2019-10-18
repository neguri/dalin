#include <iostream>
using namespace std;

//[2_rvalue1.cpp](2_rvalue1.cpp)
int x = 0;
int foo() { return x; }
int& goo() { return x; }

// lvalue : ��ȣ�� ���ʿ� �� �� �ִ� ǥ�� �� 
//					lvalue to rvalue conversion  (�����ʿ��� �� �� �ִ�)
//					�� �Ӹ� �ƴ϶� �̸�(�޸�)�� ������, ���� ��(�� ��)�� �Ѿ ����
//					�ּ� �����ڷ� �ּҸ� ���� �� �ִ�.
//					������ ��ȯ�ϴ� �Լ�

//	rvalue : ��ȣ�� �����ʿ��� �� �� �ִ�.
//					�̸�(�޸�)�� ���� ���� �Ŀ��� ����
//					�ּ� �����ڷ� �ּҸ� ���� �� ����

int main()
{
	// v1 : lvalue, 20 : rvalue
	int v1 = 10, v2 = 10;
	// 10 = v1; // ����. �޸𸮰� ����
	v1 = 20;		
	v2 = v1;

	int* p1 = &v1;
	// int* p2 = &10;  // ����
	
	// foo() = 10; // ����
	goo() = 10;

	10; // rvalue
	"Hello";  // lvalue : ���ڿ� ���ͷ��� lvalue�� �ϱ�� ��.
//	"Hello"[0] = 'h';  // ���� C �����Ϸ��� ���
									// ������ const char[] �̹Ƿ� ����
									// ���ڿ��� ª���� �׳� �ڵ� �޸𸮷� �ö�����
									// ���ڿ��� ��� ���� ������ �޸𸮿� �ø���, �����ͷ� ����Ŵ

	const int c = 10; 
	//c = 20;  // error. immutable lvalue ��� �θ�

	// ������ �´� ���� ?
	// error . C �����Ϸ��� ���������, ǥ�ؿ��� ���� �ʴ� ǥ����
	//char* s1 = "hello";				
	const char* s1 = "hello";
}