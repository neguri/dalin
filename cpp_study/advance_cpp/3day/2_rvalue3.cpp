#include <iostream>
using namespace std;

int main()
{
	int n = 10;
	int* p = &n;

	// decltype�� �����ϴ�  ��Ģ 
	// 1 : ���� �̸��� �ִ� ���
	//		->  �ش� ������ ������ �����ؼ� Ÿ�� ����
	decltype(n) d1;  // int d1
	decltype(p) p2;  // int* p2

	// 2: ������ �����ڰ� ���Ե� ǥ������ �ִ� ���
	//		-> �ش� ǥ������ ��ȣ�� ���ʿ� �� �� ������ ����, <-> �ƴϸ� �� Ÿ��
	decltype(*p) d ;		// int& d3; �̷��� �Ǳ� ������ error. decltype(*p) d = n ; �̶�� ������ ���� �ƴ�
	decltype(n + 1) d4;  //	int d4
	decltype(++n) d5 ; // int&d5; error.
	decltype(n++) d6; //int d6

	decltype(n) d7; // int
	decltype(10) d8; // int
	//decltype((n)) d9; // int& 
	decltype((10)) d10; // int
}