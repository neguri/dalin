#include <iostream>
using namespace std;

class Car {
	int speed;
	//int m_count = 0;
	mutable int m_count = 0;
public:
	void ref() const {												// ��� ��� �Լ� �ȿ����� ���� �����ϰ��� �Ҷ�, mutable�� ���� ���� ��
		++m_count;
	}
	void deref() const {
		if (--m_count == 0)  delete this;
	}

protected: // protected �� ��ü �ܺο��� ȣ�� �ȵǹǷ�,  ��ü��  stack�� ���� �� ���� ��. ������ heap�� ����� ��.
	~Car() { cout << "car dtor" << endl; }
};

Car* p;

int main()
{
	const Car* p1 = new Car;
	p1->ref();					// �ƹ��� ��ü�� ��� ��ü���� ���� ����� ���氡���ؾ� ��
	p1->deref();
}