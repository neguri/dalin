#include <iostream>

using namespace std;

void foo(int a) {}
void goo(int& a) { a = 100; }

// �Ϻ��� ����(perfect forwarding)
// ������ ���ڸ� �ٸ� �Լ����� �Ϻ��ϰ� ������ �ִ� ��

// Ư�� �Լ��� ������ �����ϴ� �Լ�
template<typename F, typename T>  
 
// (2) ����� ���ڸ� ������ ��� ����
//void chronometry(F f, T arg) {

// (3) ������ ����. �̷��� �ϸ� 10�� ������ �� ����. chronometry(foo, 10); ���� ����
 //void chronometry(F f, T& arg) { 

 // (4) 10�� �����ϱ� ���� const�� �ٿ���.  ������ chronometry(goo, n);  ���� ���� �߻�
// �׸��� ���� ���� ����
void chronometry(F f, const T& arg) {
	cout << "current time" << endl;
	f(arg);
	cout << "ellapsed time" << endl;
}

int main()
{
	int n = 10;
	//foo(10);
	chronometry(foo, 10);
	cout << "------------------" << endl;
	chronometry(goo, n); // (1) goo ���Ŀ� n�� 100���� ����Ǳ� ���������,�׷��� ����
	cout << "------------------" << endl;
	cout << n << endl;
}
