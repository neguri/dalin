#include <iostream>
#include <type_traits>

using namespace std;

class Shape {
	virtual void Draw() {};
};

// 1. ������ �����ϴ� ��쿡�� �Լ��� ȣ��

// �߻� Ŭ����
// 1. ��ü�� ���� �� ����
// 2. ������ ������ ���� �� �ִ�.
// 3. �迭�� ����Ű�� �����ʹ� ���� �� ����.
//template<typename T> char check(T a);
template<typename T> int check(T(*)[1] );
template<typename T> char check(...);


int main()
{
	if (sizeof(check<Shape>(0)) == sizeof(char)) {
		cout < "�߻� �ƴ�" << endl;
	}
	else {
		cout << "�߻�" << endl;
	}
}