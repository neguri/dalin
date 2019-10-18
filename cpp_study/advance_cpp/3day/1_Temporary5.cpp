#include <iostream>

using namespace std;

//[1_Temporary5.cpp](1_Temporary5.cpp)

class Test {
public:
	// �Լ� �̸� �ڿ� '&'�� �ٿ� �ָ�, �ӽ� ��ü������ �θ� �� �ִ���, �Ϲ� ��ü���� ȣ�� ������ �Լ� ���� ������.
	// void foo()  { cout << "&" << endl; }  // (1) �ӽ� ��ü�� �θ� �� �ְ�, �̸� �ִ� ��ü�� �θ� �� ����
	void foo()  & { cout << "&" << endl; }	// (2) �̸� �ִ� ��ü�� �θ� �� ����
	void foo()  && { cout << "&&" << endl; }	// (2) �̸� ���� �ӽ� ��ü ������ ��� ����
};

int main()
{
	Test t;
	t.foo();
	Test().foo();  // &&
	((Test*)0)->foo();  // �ּҰ� �����Ƿ� �̸� �ִ� ��ü�� �Ǵ�. Test ��ü�� 0�� �ּҷ� ���� �� �Լ� ȣ��
}