//1_temporary.cpp

//https://github.com/WebKit/webkit/blob/master/Source/WTF/wtf/Scope.h
/*
	ScopeExit(const ScopeExit&) = delete;
	ScopeExit& operator=(const ScopeExit&) = delete;
	ScopeExit& operator=(ScopeExit&&) = delete;
*/

#include <iostream>

using namespace std;

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

// Temporary�� Ư¡

int main()
{
	Point p(0, 0);
	p.x = 10;

	//Point(0, 0).x = 10;  // (1) Ư¡ 1. temporary�� lvalue�� �� �� ���� ( = �� ���ʿ� �� �� ����)
											// temporary�� ��� ? ����� �ƴ�
	Point(0, 0).set(10, 20); // (2) ����� �ƴϱ� ������ ����. �̷��� ���� ������ vector���� BitProxy�� ���� ���

	Point* p1 = &p;
	Point* p2 = &Point(0, 0);  //(3) tempory�� �ּҸ� ���� �� ����. �����ٿ� �Ѿ�� ��ü�� �����Ƿ�

	// Ư¡ 3
	Point& r1 = p;			// �̸��� �ִ� ��ü�� ������ ����ų �� �ִ�.
	
	//Point& r2 = Point(0, 0);		// �̸��� ���� ��ü�� �����ٿ��� �������Ƿ� ������ ����ų �� ����.
	
	const Point& r3 = Point(0, 10); // (4)  const ������ temporary�� ����ų �� ����. ������ r3�� ����� ����
																// temporary materialization �̶�� ����
	
	// �� �ڵ��� ������ : temporary�� ����� �ƴѵ� ��� �����θ� ����ų �� �ִ�.
	// C++11���� ��� �� ������ ����Ű�� ��
	Point&& r4 = Point(0, 0);
	r4.x = 10;

}