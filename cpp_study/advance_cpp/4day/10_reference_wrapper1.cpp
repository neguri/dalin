#include <iostream>

using namespace std;

// C++ ����: �ѹ� ����Ų �޸𸮴� ������ �� ���� . 
// ������ ��� ���� ���� �� ���� �̵��Ѵ�.
/*
int main()
{
	int n1 = 10;
	int n2 = 20;

	int& r1 = n1;
	int& r2 = n2;

	r1 = r2;

	cout << n1 << endl;
	cout << n2 << endl;
	cout << r1 << endl;
	cout <<r2 << endl;
}
// ����ϸ� ��� 20
*/

/*
int main()
{
	int n1 = 10;
	int n2 = 20;

	// reference wrapper : �̵� ������ ����. ������ ������ �̵����� �ʰ�, ���� �����.
	reference_wrapper<int> r1 = n1;
	reference_wrapper<int> r2 = n2;

	r1 = r2;

	cout << n1 << endl;
	cout << n2 << endl;
	cout << r1 << endl;
	cout << r2 << endl;
}

*/

// � ��ü�� ����ų �� �ִ°��� ������ �ۿ� ����.
// 1. �ּҸ� ����
// 2. ��¥ ����Ÿ������ ��ȯ ����

template<typename T> struct xreference_wrapper {
	T* obj;
public:
	xreference_wrapper(T& r) : obj(&r) {}

	// ��¥ ����ȭ ȣȯ �Ǿ�� ��.  - reference ó�� �����ϴ� ���� �ϳ� ����� ����
	// ���� �ϴ� ���� �����Ϸ��� �˾Ƽ� �������
	operator T&() { return *obj; }
};

int main()
{
	int n1 = 10;
	int n2 = 20;

	// reference wrapper : �̵� ������ ����. ������ ������ �̵����� �ʰ�, ���� �����.
	xreference_wrapper<int> r1 = n1;
	xreference_wrapper<int> r2 = n2;

	r1 = r2;

	cout << n1 << endl;
	cout << n2 << endl;
	cout << r1 << endl;
	cout << r2 << endl;
}
