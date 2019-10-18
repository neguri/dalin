
#include <iostream>

using namespace std;

class Car {
	int speed;
	int m_count = 0;
public:
	void ref() {
		++m_count;
	}
	void deref() {
		if (--m_count == 0)  delete this;
	}

protected: // protected �� ��ü �ܺο��� ȣ�� �ȵǹǷ�,  ��ü��  stack�� ���� �� ���� ��. ������ heap�� ����� ��.
	~Car() { cout << "car dtor" << endl; }
};

Car* p;

int main()
{
	Car* p1 = new Car;
	p1->ref();					// ��Ģ 1. ��ü�� ���� �� ���� ��� ����
	Car*p2 = p1;
	p2->ref();					// ��Ģ 2. ��ü �ּ� ���� �� ���� ��� ����

	p2->deref();				// ��Ģ 3. ��� �� ���� ��� ����
	p1->deref(); 

	//Car c; // ���� ���� reference count �� ����ϸ�, stack ��ü�� ���� �� ���� �ϴ°�, 195 page, onlyHeap Ŭ����
				// ����� �Ҹ��ڸ� protected: �� �ִ°�. �׷��� heap�� ����� �ۿ�

	//Car::~Car( ) �� �����Ϸ��� ����� ��� �ϴµ�, protected �� ���� ���� ����. �ᱹ ���� ����
}