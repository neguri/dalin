#include <iostream>
#include <atomic>

using namespace std;

//https://github.com/WebKit/webkit/blob/master/Source/WTF/wtf/RefCounted.h

	  // ���� ������ ���� ����Ѵ�. �׷��� MACRO�� �����
#define WTF_MAKE_NONCOPYABLE(classname)		\
				classname(const classname&) = delete;			\
				classname& operator=(const classname&) = delete;



// �ڵ� �޸𸮸� ���̱� ����
// template Ŭ���� �ȿ��� T�� ������� �ʴ� ��� ����� ��� Ŭ������ �ű�. 
// ��� Ŭ������ template�� �ƴϾ�� ��
// �׷��� ������ �� ��� �Լ��� ������.

// Thin template (237 page) 

class RefCountedBase {
protected:
	mutable atomic<int> m_count = 0;
public:
	void ref() const {
		m_count.fetch_add(1);
	}
};

template<typename T> class RefCounted :  public RefCountedBase{
	WTF_MAKE_NONCOPYABLE(RefCounted)

public:
	RefCounted() = default;
	void deref() const {
		if (m_count.fetch_sub(1) == 1)  delete static_cast<const T*>(this);
	}

protected:
	inline ~RefCounted() { cout << "RefCounted dtor" << endl; }
};


class Truck : public RefCounted<Truck> {
public:
	Truck() = default;
	~Truck() { cout << "Truck dtor" << endl; }
};


int main()
{
	Truck* p1 = new Truck; 	p1->ref();
	Truck* p2 = p1;					p2->ref();

	p1->deref();
	p2->deref();

}
