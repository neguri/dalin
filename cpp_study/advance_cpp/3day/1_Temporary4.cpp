//  Temporary�� �Լ� ��ȯ Ÿ��
#include <iostream>

using namespace std;

//[1_Temporary4.cpp](1_Temporary4.cpp)
class Point {
public:
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) {
		cout << "Point()" << endl;
	}
	~Point() { cout << "~Point()" << endl; }
	void set(int a, int b) { x = a;  y = b; }
	void print() { cout << x << ' ' << y << endl; }
};


// 1. �Լ� ����
// void foo(Point pt) {} // call by value : ���纻 ��ü�� ����
void foo(Point& pt) {} // call by reference  : ���纻  ���� �ȵ�

Point pt(0, 0);
// 2. �Լ� ��ȯ Ÿ��
// ���纻�� ��ü�� ��ȯ��. ���� ��ü�� Ÿ�Ը� �ְ� �̸��� ����. (�ӽ� ��ü)
// �׷��� goo().x = 10;  �� ������ ���� �߻� (�ӽ� ��ü�� ���� ���� �� �� �����Ƿ�)
Point goo() { return pt; }	

// ���ݽ��� ��ȯ��.
Point& hoo() { return pt; }

Point& koo()
{
	Point p(0, 0);
	// !!! ���� ���� ������ ������ ��ȯ�ϸ� �ȵ�
	return p;	
}

int main()
{
	Point p;
	foo(p);
	// ���۷����� ��ȯ�ϴµ�, ��ȭ�ϴ� �Ϳ� �̸��� ����. 
	// ������Global�� ����� ��ü�� ��ȯ�� ���̰� ���� �����ϰ� ����
	hoo().x = 10, hoo().print();
	pt.print();
}	