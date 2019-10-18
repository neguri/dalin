#include <iostream>
#include <type_traits>

using namespace std;

class Sample1 {
public:
	virtual void foo() {
		cout << "foo" << endl;
	}
	Sample1() {} // �ƹ��ϵ� �������� trivial ���� ����.(�����Ϸ��� ��)
};

class Sample2 {
public:
	void foo() {
		cout << "foo" << endl;
	}

	Sample2() = default; // �ƹ��ϵ� ���ϴ� ���� �����Ϸ��� �� �� ����. trivial ��. �׷��� �� ����� ��õ
};


int main()
{
	// trivial ���� Ȯ���ϴ� �Լ�
	cout << is_trivially_default_constructible_v<Sample1> << endl;
	cout << is_trivially_default_constructible_v<Sample2> << endl;
}
