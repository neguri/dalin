#include <iostream>

using namespace std;

struct Animal {
	virtual void Cry() { cout << "Animal cry" << endl; }
	virtual ~Animal() {}
};

struct Dog : public Animal {
	virtual void Cry() { cout << "Dog cry" << endl; }
};


Dog d;
Animal	f1() { return d; }   // �� ����. ���ʿ� �ü� ����.  -		move ȣ�� non polymorphic

Animal&& f2() {   // ���ʿ� �ü� ����. -- move polymorphic
	return move(d);
} 

Animal& f3() { return d; } // ���� ���� . ���ʿ� �� �� �ִ�.  - copy ȣ��

int main() {

	f1().Cry(); // animal cry
	f2().Cry(); // dog cry
	f3().Cry(); // dog cry

//	Dog d1 = f1(); // move
//	Dog d2 = f2(); // move
//	Dog d3 = f3(); //move	
}


// expression : �ϳ��� ������ ��� �� �� �ִ� �ڵ� ����

// lvalue: ǥ������ ����� lvalue ����
// xvalue: ǥ������ ����� rvalue ����
// prvalue: ǥ������ ����� ��(literal , �ӽ� ��ü)

f1(); // �� ��ȯ
f2(); // rvalue ���� ��ȯ
f3(); //lvalue ���� ��ȯ

int main() {

	class Point {};

	int n = 10;
	static_cast<int&>(n) = 10;		// �޸𸮰� ��ȯ . lvalue ����
	static_cast<int&&>(n) = 10;   // n . �̶�� �޸𸮴� ����. ������ lvalue�� �ƴ�. �� ���� �Ұ�. xvalue ��� ��
	n + 1 = 10;			// �� 11 ��ȯ. lvalue �ȵ�


	Point pt;
	// �Ʒ� �ڵ�� lvalue�� _rvalue(xvalue)�� ĳ�����ϰ� ����.
	Point pt2 = static_cast<Point&&>(pt);
}