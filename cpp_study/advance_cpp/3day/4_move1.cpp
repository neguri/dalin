#include <iostream>

using namespace std;

class Point {
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}
	
	// 1. ���� ������ ��� 1. call by value
	// �̷��� ���� �� ����. ��������� ������ �����ϰ� ��
	// ���ڰ� �Ѿ�� ���簡 �ǰ�, �ٽ� ���� ������ �Ҹ���, �ٽ� ���� , �ٽ� ���� ������..���� �ݺ�
	//Point(Point pt) {}

	// 2. ���� ������ ��� 1. call by reference
	// ��� ����. ���� ����
	// ����: rvalue�� ���� �� ����.
	// ���� ��ȯ�ϴ� �Լ��� ��ȯ���� ���� �� ����. 
	Point(Point&) {}

	// 3. ���� ������ ���  call by const lvalue reference
	// lvalue �� �ƴ϶� rvalue ��� ���� �� �ִ�.
	Point(const Point& pt) : x(pt.x), y(pt.y) {}
};

Point foo() {
	Point p;
	return p;
}

int main()
{
	Point p1;					// ����Ʈ ������ (���ھ��� default ������ ����)
	Point p2(1, 2);		// ���� 2���� ������
	Point p3(p2);			// Point(Point)�� ������ �ʿ�
	Point p4(Point(0,0));			// Point(Point)�� ������ �ʿ�

	Point ret = foo();	// foo���� ���ϵǴ� ���� �ӽ� ��ü, rvalue. 2�� ���� �����ڷδ� �� �ڵ带 ó�� ����.
}