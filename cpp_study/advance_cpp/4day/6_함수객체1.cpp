#include <iostream>

using namespace std;

// function object : �Լ�ó��( ) �� ����ؼ� ȣ�� ������ ��ü
// ������ callable object ��� �� ���

struct Plus {
	int operator() (int a, int b) {
		return a + b;
	}
};

int main()
{
	Plus p;					// ��ü
	int n = p(1, 2);		// ��ü�� �Լ�ó�� ���
									// p.operator()(1,2) 
	cout << n << endl;
}