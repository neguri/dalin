#include <iostream>

using namespace std;

class Point {
public:
	Point(int a, int b) {}
	Point(const Point& p)		{ cout << "copy" << endl; }
	Point(Point&& p)				{ cout << "move" << endl; }
};


// ���ø��� ���鶧 ���ڸ� T&�� �Ұ��ΰ� ? T&&�� �Ұ��ΰ�?
// T& : lvalue�� �ްڴ�
// T&& : lvalue�� rvlaue ��� �ްڴ�

/*
// template <typename T> T&& xmove(T& arg) {  // (1)
template <typename T> T&& xmove(T&& arg) { //(2)
	// xmove(lvalue) : T�� int&
	// xmove(rvalue) : T�� int
		return static_cast<T&&>(arg);
}
*/

template <typename T> remove_reference<T> && xmove(T&& arg) {
	// ���� ������ T�� ������ ������ �ִ� ���� ����
	// �׷��� remove_reference�� ���� ���� Ÿ���� ������ ��
	return static_cast<remove_reference<T> &&>(arg);
}


int main()
{
	Point p1(1, 2);
	Point p2 = p1;
	Point p3 = static_cast<Point&&>(p2); // move
	//Point p4 = move(p3);  move �� ����� ����
	Point p4 = move(p3);  //move 1�̸� move�ε�, 2�̸� copy�� ��. ���ϴ� ����� �ƴ�.
	Point p5 = move(Point(1,2));  //move


	// �Ʒ� �Լ��� � �����ڸ� ȣ���ϳ�?
	// 1. ���ڴ� 2���� ������
	// 2. ����
	// 3. move
	Point pt = Point(1, 2);

	// C++ 98: �ӽð�ü�� ����� ���� �����ڷ� pt�� ����
	// C++11 : �ӽ� ��ü�� ����� move �����ڷ� pt�� ����
	// �����Ϸ��� ����ȭ �ϸ鼭 ���� ������, move ������ ȣ�� ����
	// C++17 : ���������� �ӽð�ü�� ������ �ʰ� ���� 2���� ������ ȣ��

	/*
		gcc a.cpp -std:c++98 --fno-elide-constructors
		gcc a.cpp -std:c++11 --fno-elide-constructors
		gcc a.cpp -std:c++17 --fno-elide-constructors
	*/
}