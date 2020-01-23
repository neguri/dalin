#include <iostream>
#include <memory>
#include <type_traits>

using namespace std;

template<typename T> class xenable_shared_from_this {
public:
	weak_ptr<T> wp;
	shared_ptr<T> shared_from_this() {
		return wp.lock();
	}
};

class Point : public xenable_shared_from_this <Point> {
	int x, y;
	
	// wp�� ��ӹ���

public:
	void foo() {
		shared_ptr<Point> p = shared_from_this();
	}
};

class RefManagr {};

// shared _ptr�� ������ ����
template<typename T> class shared_ptr {
	T* obj;
	RefManagr* manager;
public:
	shared_ptr(T* p) {
		obj = p;
		manager = new manager; // ���� ��ü �ʱ�ȭ

		// T��  xenable_shard_from_this �� ���� ��� �޾Ҵٸ�. 
		if (is_base_of_v<xenable_shared_from_this<T>, T>) 
			obj->wp = *this;

	}
};

int main()
{
	shared_ptr<Point> sp(new Point);
	
}