#include <iostream>
#include <memory>

using namespace std;

class Point {
	int x, y;
public:
	Point(int a = 0, int b = 0) { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

// (2) new�� �������ؼ� ��ŭ �Ҵ��ϴ��� Ȯ������
void* operator new(size_t sz) {
	cout << "new: " << sz << endl;
	return malloc(sz);
}

// (5) make_shared �� ������ ������ ����
/*
template<typename T,  typename ... ARGS> 
shared_ptr<T> xmake_shared(ARGS&& ... args) {
	void* p = operator new(sizeof(T) + sizeof(������ü));

	// ��ü ������ ȣ��
	new (p) T(std::forward<ARGS>(args) ...);

	// ������ü ������ ȣ��
	shared_ptr<T> sp;
	sp.reset(p, ((char*)p) + sizeof(T));
	return sp;
}
*/

int main()
{
	// (1) �Ʒ� �ڵ�� ���� �޸� �Ҵ��� ��� �ϰ� �ɱ��? 
	// (3) 2�� �Ҵ�� : ��ü �Ҵ�  + ���� ��ü(ref counter ��) �Ҵ�
	shared_ptr<Point> sp1(new Point(1, 2));
	cout << "---" << endl;

	// (4) �޸𸮸� �ѹ��� �Ҵ�. �޸� ����ȭ ������ �پ��
	shared_ptr<Point> sp2 = make_shared<Point>(1, 2);

	// make_shared ����
	// 1. ��ü + ���� ��ü�� �ѹ��� �Ҵ��ϹǷ� "�޸� ����ȭ" ������ �پ���.
	// 2. �����ϴ�

	foo(shared_ptr<int>(new int), goo());
	// 1. new int
	// 2. goo()
	// 3. shared_ptr ����� 
	// ������ ����Ǵٰ� goo���� ���� ������ �޸� ����

	foo(make_shared<int>(), goo());  // �޸� ������ ����.

	foo(new int, goo()); //������ �ڵ�
	// �׷��� shared_ptr<int.> = new int;�� ���� ���ϴ� ����
}
int goo() { return 0; }
void foo(shared_ptr<int> sp, int n) {}
