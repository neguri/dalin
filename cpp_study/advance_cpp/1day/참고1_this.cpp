
#include <iostream>
using namespace std;

class Base {

public:
	void foo() {}
};

class Point : public Base {

	int x, y;
public:
	void set(int a, int b) { x = a, y = b; }   // void set(Point* this, int a, int b) 
	int getX() const { return x; }  // int getX(const Point* this) �� ����Ǵ� ����. �׷��� �Լ� ������ ���� �����ϸ� ������.
};

int main()
{
	Point p1, p2;
	p1.set(10, 20);		// set( ) �Լ��� �Ѱ��� ����� ���Ƿ�, set(&p1, 10, 20) ���� ������ ��
	p2.set(30, 40);		// set(&p2, 30,40)
	p1.getX();
}