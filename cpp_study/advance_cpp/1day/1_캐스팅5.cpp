#include <iostream>

using namespace std;
/*
int main()
{
	const int c = 10;

	// int* p1 = &c;   error
	int* p1 = (int*)&c;
	//int* p1 = static_cast<int*>(&c);   //error
	//int* p1 = reinterpret_cast<int*>(&c);   //error
	int* p2 = const_cast<int*>(&c);   // ���� Ÿ���� const �Ӽ��� ����

	volatile int n = 10;   // volatile : ����ȭ ���� ����
	//int* p3 = &n;
	volatile int* p3 = &n;
	int* p2 = const_cast<int*>(&n);
}
*/

int main()
{
	// c�� �ּҸ� p�� �������� �Ҷ�,
	const int c = 10;
	// char* p = &c; // error
	// char* p = static_cast<char*>(&c);  //error
	//char* p1 = reinterpret_cast<char*>(&c);   // const ���Ű� �ȵǾ ����
	char* p2 = reinterpret_cast<char*>(const_cast<int*>(&c));   //  �ѹ��� ĳ��Ʈ�� ���� �ʰ�, �ι��� ĳ������ �ؾ���.
}
