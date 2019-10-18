//1_temporary.cpp

//https://github.com/WebKit/webkit/blob/master/Source/WTF/wtf/Scope.h
/*
	ScopeExit(const ScopeExit&) = delete;
	ScopeExit& operator=(const ScopeExit&) = delete;
	ScopeExit& operator=(ScopeExit&&) = delete;
*/

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
};

// �ٽ� 1.  temporary�� ����� ���
//          	2. temporary�� ����
int main()
{
	//Point p(1, 1);  // (1)  �̸��� �ִ� ��ü (named object) . ���� ������ �Ѿ �޸� ����
								// (2) ����: ��ü�� ������ ���� ��

	//Point (1, 1);  // (3) unnamed object, temporary(object) 
							// (4) ����: ������ ��. �̸��� ���� ������ �ٸ� ������ ��� �Ұ�
	Point(1,1), cout<<"x"<<endl; // (5) �̷��� ����� ��ü�� ������ Ȯ���� �˼� ����
	cout << "------" << endl;
}