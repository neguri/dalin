#include <iostream>

using namespace std;

class Rect {
public:
	int x = 0, y = 0, w = 10, h = 10;
public:
	int setY(int a) { y = a; }
	int getArea()  const {  // ��� ��� �Լ�!! . 
		//w = 20;  // error  . ��� ��� �Լ��̱� ������ �б⸸ ����
		return w * h;
	}
};

//void foo(Rect r) {
void foo(const Rect& r) {   // ������� ������带 ���̱� ���� const &�� �����ϰ� �Ǵµ�,
													//  getArea( ) const { �� �Ǿ�� ��.
													// �� const refence �� ��������, ��� �Լ��� ��� ��� �Լ����� ��.
	int n = r.getArea();
}

int main()
{
	 Rect r;	// �����ڷ� �ʱ�ȭ
	foo(r);
}