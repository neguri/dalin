#include <iostream>

using namespace std;

// �� ĳ���� : �ӽ� ��ü�� ����� �ȴ�.
// ���� ĳ����: �ӽ� ��ü�� �������� �ʴ´�.

struct Base {
	int value = 10;
	Base() {
		cout << "Base()" << endl;
	}
	Base(const Base& d) {
		cout << "Base copy" << endl;
	}
};

struct Derived : public Base { 
	int value = 20; 
	Derived() {}
};

int main()
{
	Derived d;
	cout << d.value << endl;

	// ��� Ŭ���� �ع� �����ϱ�
	// �� ĳ���� vs ���� ĳ����
	cout << static_cast<Base>(d).value << endl;			// �ӽ� ��ü�� ������. ���⼭ ��µǴ� 10�� �ӽð�ü�� 10��. ������ �޸�
																										// ���� �����ڰ� �Ҹ��� ��.
	cout << static_cast<Base&>(d).value << endl;

	//static_cast<Base&>(d).value = 30;   // ������ ��
	//static_cast<Base>(d).value = 30;     //  ������ �ȵ�. �ֳĸ� �ӽ� ��ü�� ��ȣ�� ���ʿ� �� �� ����.
																			// ���� �׻� �� ĳ���� �ϸ� �ȵǰ�, ���� ĳ������ �ؾ� ��.
}
