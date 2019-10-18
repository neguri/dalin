#include <iostream>
using namespace std;

template<typename T> class RefCounted {
	mutable int m_count = 0;
public:
	void ref() const {
		++m_count;
	}
	void deref() const {
		//if (--m_count == 0)  delete (T*)this; 
		//if (--m_count == 0)  delete static_cast<T*>(this);       //   RecCounted �� Truck�� ��� ����� ���� ���� ����. static_cast. error
		
		if (--m_count == 0)  delete static_cast<T*>(const_cast<RefCounted*>(this));       

		//   deref( ) �Լ��� const Ÿ���̱� ������, this �� const* �� �Ǿ� ����. �׷��� const_cast�� ���ؼ� const�� �����ؾ� ��.
		if (--m_count == 0)  delete static_cast<const T*>(this); 
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
