#include <iostream>

using namespace std;

class Car {
public:
	void Go() { cout << "Car  Go" << endl; }
	~Car() { cout << "~Car" << endl; }
};


// �Ʒ� �ڵ尡 �ٽ���
// ����: ������ ��ü�� �ٸ� Ÿ���� ������ ������ �ϴ� ��
// ����: -> �� * �� �� �����ؼ� ������ ó�� ���̰� �ϴ°�

// ����: raw pointer �� �ƴ� ��ü�̴�.
//				����/����/�Ҹ��� ������ �߰��� �۾��� �� �� �ִ�.
//				��ǥ�� Ȱ���� �Ҹ��ڿ��� �ڵ� ���� ���.

class Ptr {
	Car* obj;
public:
	Ptr(Car* p = 0) : obj(p) {}
	~Ptr() { delete obj; }
	Car* operator->() { return obj; }
	Car& operator*() { return *obj; }		// �ٽ� .. �ݵ�� '����' �����ؾ� ��
};

int main()
{
	Ptr p = new Car;  //    Ptr p(new Car), ptr ��ü�� car�� ���� ����
	p -> Go();   // ( p.operator->())Go() => (p.operator->())->Go()
	(*p).Go();
}