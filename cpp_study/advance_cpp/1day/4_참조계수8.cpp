#include <iostream>
#include <atomic>

// https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/include/utils/LightRefBase.h
using namespace std;


// ���� ������ ���� ����Ѵ�. �׷��� MACRO�� �����
#define WTF_MAKE_NONCOPYABLE(classname)		\
				classname(const classname&) = delete;			\
				classname& operator=(const classname&) = delete;

template<typename T> class RefCounted {
	// �Լ� ���� �������� ���� �����ڿ� ���� �����ڸ� �����Ѵ�.
	// ���� �����ڿ� ���� �����ڸ� ����ϸ� ������ ����

	//RefCounted(const RefCounted&) = delete;
	//RefCounted& operator=(const RefCounted&) = delete;

	// �Ʒ� ��ũ�θ� ����ϸ� ���� ������ ��ġ �� �� ����.
	WTF_MAKE_NONCOPYABLE(RefCounted)
	
	mutable atomic<int> m_count = 0;
public:
	RefCounted() = default;
	void ref() const {
		m_count.fetch_add(1);
	}
	void deref() const {
		if (m_count.fetch_sub(1) == 1)  delete static_cast<const T*>(this);
	}

protected:
	// ���� �Ҹ��ڴ� inline ������ �������� ���ؼ� �ٿ���
	inline ~RefCounted() { cout << "RefCounted dtor" << endl; }
};


class Truck : public RefCounted<Truck> {
public:
	Truck() = default;
	~Truck() { cout << "Truck dtor" << endl; }

	Truck(const Truck& t) {
		// �� ����� ����. ��� Ŭ������ ���� ������ �����ϰų�
		// ��� Ŭ������ ���� �����ڸ� ȣ�� ���� ����
		// �����Ϸ��� ����� �ִ� ������ ��� Ŭ���� ���� ������ ȣ��
	}
};

int main()
{
	Truck* p1 = new Truck; 	p1->ref();
	Truck* p2 = p1;					p2->ref();

	Truck* p3 = new Truck(*p1);
	p3->ref();

	p1->deref();
	p2->deref();

}
