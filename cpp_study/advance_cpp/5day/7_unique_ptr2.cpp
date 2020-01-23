#include <iostream>

using namespace std;

// ���������� ����ϱ� ���� template���� ����

template<typename T>
class xunique_ptr {
	T* obj;
public:
	explicit xunique_ptr(T* p = 0) : obj(p) {}
	~xunique_ptr() {
		delete obj;
	}
	T* operator->() { return obj; }
	T& operator*() { return *obj; }

	// ����� ������ ����
	// ���� ���� ���� ����.
	xunique_ptr(const xunique_ptr&) = delete;
	xunique_ptr& operator = (const xunique_ptr& p) = delete;
};

int main()
{
	// xunique_ptr<int> p1 = new int;  // error explicit ������ ���� ��
	 xunique_ptr<int> p1(new int);
	*p1 = 10;
	cout << *p1 << endl;

	//xunique_ptr<int> p2 = p1;  // ���� ������

	cout << "--" << endl;
}