#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	// �ּ� �����ڸ� ������
	Point* operator&()  const {
		return nullptr;
	}
};

int main() {
    const Point pt;
	const Point* p1 = reinterpret_cast<const Point*>(&reinterpret_cast<char&>(const_cast<Point&>(pt)));
	
	// �̷��Ե� ������, const �Ӽ��� �������Ƿ� const�� �ٿ���� �Ѵ�.
	Point* p2 = reinterpret_cast< Point*>(&reinterpret_cast<char&>(const_cast<Point&>(pt)));
	cout << p1 << endl;
}