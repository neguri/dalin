#include <iostream>
using namespace std;

class AAA
{
public:
	typedef int DWORD;
	static int value;
};

int AAA::value = 0;

template<typename T> void foo(T t) {
	// (1) AAA Ŭ���� �ȿ� �ִ� DWORD�� ����ϴ� �� : int n
	AAA::DWORD n;

	// (2) T �� ������ Ÿ���̶� static ��� �������� typedef ���� �� �� ����
	//T::DWORD b; ������.

	//(3) T::�̸� => ������ static ������ �ؼ�
	// typename T:: �̸� => "�̸�"�� static ������ �ƴ� Ÿ������ �ؼ��ؾ� ��.
	int n2 = T::value;

	// (4) typename�� ���� ���� ������ �߻��ϰ�, typename�� �ݵ�� �ʿ���
	typename T::DWORD n3;
}

int main()
{
	AAA	a;
	foo(a);
}