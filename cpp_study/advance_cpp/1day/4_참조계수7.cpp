#include <iostream>
#include <atomic>

// https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/include/utils/LightRefBase.h
using namespace std;

template<typename T> class RefCounted {
	// multi thread ȯ�濡�� �����ϰ� ���� �̷��� ��.
	mutable atomic<int> m_count = 0;
public:
	void ref() const {
		m_count.fetch_add(1);
	}
	void deref() const {
		if (m_count.fetch_sub(1)  ==  1)  delete static_cast<const T*>(this);  
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
