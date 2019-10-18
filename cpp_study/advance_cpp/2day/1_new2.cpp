// �� ����� ��?

#include <iostream>

using namespace std;

class Point {
	int x, y;
public:
	Point(int a , int b) :x(a), y(b) {
		cout << "Point()" << endl;
	}
	~Point() { cout << "~Point()" << endl; }
};

int main()
{
	// Point ��ü�� ���� �Ѱ� �����
	Point* p1 = new Point(0, 0);
	// ���� 10�� �����
	
	// Point* p2 = new Point[10];  // �����ڸ� �θ� ���� ����.
	// �ذ� ��� =>

	// ����Ʈ �����ڰ� ���� ��ü�� ������ �����Ϸ���,
	// �޸� �Ҵ�� ������ ȣ���� �и�

	// 1. �޸� �Ҵ�
	Point* p2 = static_cast<Point*>(operator new (sizeof(Point) * 10));
	// 2. ������ ȣ��
	for (int i = 0; i < 10; i++) {
		new(&p2[i]) Point(0, 0);
	}

	//  ��� �� �Ҹ��� ȣ���� �ı�
	for (int i = 0; i < 10; i++) {
		p2[i].~Point();
	}
	operator delete(p2);

	// �޸� ���� �Ҷ�, �Ʒ�ó�� ����ϸ� �˼� ���� ������ �ϰ� ��
	// delete []p2; 
}