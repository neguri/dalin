#include <iostream>
using namespace std;


/*

class RefCounted {
	mutable int m_count = 0;
public:
	void ref() const {												// ��� ��� �Լ� �ȿ����� ���� �����ϰ��� �Ҷ�, mutable�� ���� ���� ��
		++m_count;
	}
	void deref() const {				// void deref(RecCounted* this)
														//  �̷��� �ϰ� ������ RefCounted������ Truck�� �� �� ����.
		if (--m_count == 0)  delete (Truck*)this;      
	}

	// ���� �Ҹ��ڴ� ������尡 �ִ�. �Ҹ��ڸ� �������� ���� ���� ������ ��.
protected:
	 ~RefCounted() { cout << "RefCounted dtor" << endl; }
};

// Truck�� ���� ����� �����ϰ� �ʹ�.

class Truck : public RefCounted {
public:
	~Truck() { cout << "Truck dtor" << endl; }
};
*/


// page 71. CRTP ��� . Curiously Recurring TemplatePattern
template<typename T> class RefCounted {
	mutable int m_count = 0;
public:
	void ref() const {
		++m_count;
	}
	void deref() const {
		if (--m_count == 0)  delete (T*)this;       // CTRP ���
	}
	// ���� �Ҹ��ڴ� ������尡 �ִ�. �Ҹ��ڸ� �������� ���� ���� ������ ��.
protected:
	~RefCounted() { cout << "RefCounted dtor" << endl; }
};


class Truck : public RefCounted<Truck> {
public:
	~Truck() { cout << "Truck dtor" << endl; }
};

int main()
{
	Truck* p = new Truck;
	p->ref();
	p->deref();
}