#include <iostream>

using namespace std;

class Base {
public:
	Base() { cout << "Base()" << endl; }

	// derived ���� virtual ���� ���� �ǹ� ����.
	// �׷��� �ϸ� Base�� ���� �Ҹ��ڸ� �θ�.
	virtual  ~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base{
public:
	Derived() { cout << "Derived()" << endl; }
	 ~Derived() { cout << "~Derived()" << endl; }
};

int main()
{
	Base* p = new Derived;
	delete p;
}