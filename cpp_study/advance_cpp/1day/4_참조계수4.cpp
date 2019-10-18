#include <iostream>
using namespace std;

class RefCounted {
	mutable int m_count = 0;
public:
	void ref() const {												// ��� ��� �Լ� �ȿ����� ���� �����ϰ��� �Ҷ�, mutable�� ���� ���� ��
		++m_count;
	}
	void deref() const {				// void deref(RecCounted* this)
		if (--m_count == 0)  delete this;
	}
	// ��� Ŭ���� Ÿ���� �����ͷ� ������ �� �Ļ� Ŭ������ �Ҹ��ڰ� ȣ��ǰ� �Ϸ��� 
	// ���� �Ҹ��ڸ� ����ؾ� �Ѵ�.
protected: 
	 virtual ~RefCounted() { cout << "RefCounted dtor" << endl; }
};

// Truck�� ���� ����� �����ϰ� �ʹ�.

class Truck : public RefCounted {
public:
	 ~Truck() { cout << "Truck dtor" << endl; }
};


int main()
{
	Truck* p = new Truck;
	p->ref();
	p->deref();
}