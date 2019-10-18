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

// (3) ���⼭ const �� ���� ���� �߻�. �ӽ� ��ü�� �ޱ� ���ؼ� const�� ����
// (4) Ȥ�ö� foo( ) ������ ��ü�� ���� �� ���� �־ const�� ���̱⵵ ��.
void foo( const Point& p) {}  

int main()
{
	Point p(0, 0);
	// (1)  p�� foo( ) �Լ������� �ʿ���. ��� ��ü���� �ʿ��Ѱ� �ƴ�
	foo(p);
	cout << "--------" << endl;
	// (2) �ӽ� ��ü�� ������ foo( )�Լ������� ���. 
	// �Լ� ���ڷθ� ����Ϸ��� �ӽ� ��ü�� ���� �����ϴ� ���� ����
	foo(Point(1, 2)); 
}