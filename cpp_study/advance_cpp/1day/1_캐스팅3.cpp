#include <iostream>

using namespace std;

// C++�� 4�� ĳ����
// reinterpret_cast
// 1. ���� �ٸ� Ÿ���� �ּҸ� ĳ����
// 2. ���� <-> ������ ĳ����
// 3. ���� �ٸ� Ÿ���� ���� �������� ĳ����
int main()
{
	double  d = 3.4;
	int*		p1 = (int*)&d;											// ok. ������ �Ǽ� ����, �ǵ����� �� �� ����.
	//int*		p2 = static_cast<int*>(&d);					// double�� int�� ������ ��� casting �Ұ�. 
	int*		p3 = reinterpret_cast<int*>(&d);		// ok, casting �ϴ� �ǵ��� Ȯ�� ����

	//int*		p4 = 10;							// c������ ������, c++���� �ȵ�
	int*		p5 = (int*) 10;				//   c++���� �̷��� ������
	//int*		p6 = static_cast<int*> (10);				// error �߻�
	int*		p7=  reinterpret_cast<int*> (10);	// ok


}