#include <iostream>

using namespace std;

struct A { int a; };
struct B { int b; };
struct C : public A,  public B{ int c; };


int main()
{

	/*
	ccc �� �޸� ����
	|a					|  1000
	|b					|  1004
	|c					|
	
	*/

	C ccc;
	A* pA = &ccc;  // 1000
//	B* pB = &ccc; // 1004

//	B* pb = (B*)&ccc; //1004
//	B* pB = static_cast<B*>(&ccc); //1004
						// &ccc �ּҿ��� B�� ��ġ�� ã�Ƽ� �ּ� ��ȯ
						// �ش� �ּҿ� B�� ������ ������ ��� ����
						// �׷��� ������ �Ҷ�, &ccc + sizeof(A) �̷��� �ؼ� 4����Ʈ Ŀ��
	B* pB = reinterpret_cast<B*>(&ccc); //1000
					// & ccc�ּҸ� ������ B ó�� ����. ������ ������ �ϴ� 

	pB->b = 100;  // �̷��� �ϸ� a�� 100�� �� �ϸ�
	cout << &ccc << endl;
	cout << pA	 << endl;
	cout << pA->a	 << endl;  // 100 �� ����. 
	cout << pB	<< endl;
}