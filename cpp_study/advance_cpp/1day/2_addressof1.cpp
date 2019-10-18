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
	Point pt;
	cout << &pt << endl;  // & �����ڸ� �� ���� �Ͽ��� ������ �ּҸ� ������ �� �� ����. pt.operator&()

	Point* p1 = &pt;
	cout << p1 << endl;  
	cout << "----" << endl;
	//step 1. char* Ÿ�Կ� ��� ����
	char* p2 = reinterpret_cast<char*>(&pt); // &pt �̹Ƿ� 0.
	
											 //char* p3 = &reinterpret_cast<char>(pt); 
									// 1.  reinterpert_cast�� �� ĳ���ÿ��� ��� �Ұ�
									// 2.	�� ĳ������ �ӽ� ��ü�� ����� ������ , �ּ� ������ ���� ���� �ǹ� ����. 
	
	
	char* p4 = &reinterpret_cast<char&>(pt);  //  �̷��� �ϸ� �ּҸ� ������ �� �� ����
	cout << p4 << endl;
	cout << "----" << endl;
	// step 2. Point type�� �־� ����
	Point* p5 = reinterpret_cast<Point*>(&reinterpret_cast<char&>(pt));
	cout << p5 << endl;
	Point* p6 = &reinterpret_cast<Point&>((pt));
	cout << p6 << endl;   // �̷��� �����ϸ� Point& ������ 0 �� ����.

	// char �� �ƴ� int�� �Ͽ��� ��
	Point* p7 = reinterpret_cast<Point*>(&reinterpret_cast<int&>(pt));
	cout << p7 << endl;
}