#include <iostream>

using namespace std;

class Rect {
public:
	int x = 0, y = 0, w = 10, h = 10;
public:
	int setY(int a) { y = a; }
	//int getArea() {  // ��� ��� �Լ�!! . 
	int getArea() const {  // ��� ��� �Լ�!! . 
		//w = 20;  // error  . ��� ��� �Լ��̱� ������ �б⸸ ����
		return w * h;
	}
};

int main( )
{
     const Rect r;	// �����ڷ� �ʱ�ȭ
	//r.x = 10;				// error. const ��ü �̹Ƿ�
	//r.setY(10);		// error. const �� ���� ��ü�� ����Ǵ� ���̹Ƿ� ����

	r.getArea();  // getArea( ) �Լ� �ڿ� const�� ������ ���� ���� �߻�. 
}