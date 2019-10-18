#include <iostream>
using namespace std;

class Animal {
public:
	virtual void Cry() { cout << "1" << endl; }
};

class Dog : public Animal {
public:
	// �Լ� �������̵�
	void Cry() {
		cout << "2" << endl;
	}
};

int main()
{
	Animal a; a.Cry();
	Dog		d; d.Cry();

	Animal *p = &d;
	p->Cry();
}

// p->Cry( )�� � �Լ��� ������ ��? => �Լ� ���ε�
// 1. static binding : ������ �ð��� �����Ϸ��� �Լ��� ����
//										������ ������ Ÿ������ ���� => Animal Cry()
//										=> Early Binding �̶�� �θ� (C++, C#)

// 2. dynamic binding :  ������ �ÿ� p �� ����Ű�� �޸� �����ϴ� ���� �ڵ� ����. ����� ���� �� ȣ��
//												Dog Cry()
//												Late Binding �̶�� �θ�
//												java, swift, kotlin, objective-C, 