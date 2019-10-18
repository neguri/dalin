#include <iostream>
#include <vector>

using namespace std;

class Point {
	int x, y;
public:
	Point(int a, int b)			 : x(a), y(b)		 { cout << "Point()" << endl; }
	Point(const Point& p) : x(p.x), y(p.y) { cout << "Point(const Point)" << endl; }
		~Point() { cout << "~Point" << endl; }
};

int main()
{
	vector<Point> v;
	// v�� 1,2 �� �ʱ�ȭ�� Point�� �ְ� �ʹ�
	// 1. Point ��ü ���� �� �ֱ� -> ��ü ����(1) + ����(1)  = �ΰ� ����
	//Point p1(1, 2);
	//v.push_back(p1);
	//cout << "--------" << endl;

	// 2. ��� : move�����ڷ� ���� -> Point ��ü���� move ���� �ȸ�������� , �ᱹ �ΰ� ����
	//Point p1(1, 2);
	//v.push_back(move(p1));

	//cout << "--------" << endl;
	//3.  ��� : �ӽ� ��ü ��� -> �ӽ� ��ü �̹Ƿ� �ΰ��� ��ü ���� (�ٸ� �ӽ� ��ü�̹Ƿ� ���� ������ �ı�)
	// (2) �� ����� ����� ����������, ��ü�� �ٷ� �����ϴϱ� �׳��� �̰� ����.
	//v.push_back(Point(1, 2));
	//v.push_back({ 1, 2 }); 
	//cout << "--------" << endl;

	// 4. ��� : ��ü�� �ܺο��� ������ ���� vector���� ���� �� �ֵ��� ��
	//					��, ��ü�� ���鶧 �ʿ��� ������ ���� ����
	v.emplace_back(1, 2);  // �� �Լ��� ���������� new Point(1,2)�� �θ�
	// => ����� emplace_back ����.
	v.emplace_back(3, 4);
}