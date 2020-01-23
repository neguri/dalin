#include <iostream>
using namespace std;

class Shape {
public:
	
	void foo() { cout << "foo" << endl; }
	virtual void Draw() { cout << "Shape" << endl; }
};

class Rect : public Shape {
public:
	virtual void Draw() { cout << "Rect" << endl; }
};

int main() {
	void (Shape::*f1)() = &Shape::foo;
	void (Shape::*f2)() = &Shape::Draw;
	// f2���� ���� ��� �ֳ�?
	// �Լ� �ּҰ� �ƴ�, �����Լ� ���̺� ���� index ����

	Rect r;
	(r.*f2)();
	(((Shape&)r).*f2)();
}