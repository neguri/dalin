// 143 page
#include <iostream>
using namespace std;

/*
(1) . ����ȵǴ� �Լ�
int foo(int a) {
	cout << "foo" << endl;
	return 0;
}
*/
// (2) �̷��� �Լ� �ٵ� ���� ���� �־ �����̵ȴ�.
int foo(int a);

int main()
{
	int n = 0;
	cout << sizeof(n) << endl;				// 4 byte
	cout << sizeof(&foo) << endl;		// �ּ��� ũ�� 32bit ȯ�� 4
	//cout << sizeof(foo) << endl;		// error. �Լ��� ����ϴ� �ڵ� �޸𸮴� ���� �� ����
	cout << sizeof(foo(n)) << endl;	// ��ȯ���� ũ��. "foo" ��� ��µ��� ����. (�򰡵��� ����)

	// �򰡵��� �ʴ� ǥ����
	// unevaluated expression 
	// �Լ� ȣ����� ������ �Լ��� ȣ������ �ʴ� ��
	sizeof(foo(0));
	decltype(foo(0)) m;  // foo(0) ȣ�� �� ��ȯ�ϴ� Ÿ�԰� ���� Ÿ���� m
	const type_info& r = typeid(foo(0));   // 
	bool b = noexcept(foo(0));   // ���� ���ɼ���  ������ true, ������ false

}