#include <iostream>

using namespace std;

class Vector {
public:
	//  (2) 
	///Vector(int sz) {}
	explicit Vector(int sz) {}
};
// (1)
// call by value �� ���� ���� . copy initialization ���
// �Ʒ� ǥ���� ����������, ������.  Ÿ���� �ٸ��� ���� �ǹǷ�
// Vector v  = 10 ; �� ����. 
void foo(Vector v) {}


void goo(shared_ptr<int> sp, int n) {

}

int main()
{
	Vector v1(10);   // ok - ���� �ʱ�ȭ direct initialization
	// Vector v2 = 10;  //ok - ���� �ʱ�ȭ copy initializatoin (= �� �ʱ�ȭ) error . (2) ó�� �����ϸ� ������ 
	// foo(10); error
	//goo(new int, hoo()); // error 

	shared_ptr<int> sp = new int; // explicit ������ ����
	shared_ptr<int> sp(new int); // ok
}
