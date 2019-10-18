#include <iostream>
using namespace std;

// trivial : �ϴ� ���� ����.

class Sample {
public:
	// �����ڰ� �ϴ� ���� ����. �� �ƴϰ� �ϴ� ���� ����
	// ������ �����ڸ� ȣ������ ������ ���� �߻���.
	virtual void foo() {
		cout << "foo" << endl;
	}
};

int main()
{
	Sample* p = static_cast<Sample*>(operator new(sizeof(Sample)));
	
	// �Ʒ��� ������ �θ��� �ڵ尡 ������ �����
	// �ֳĸ� foo( ) �Լ��� ���� �Լ��� , vtptr �ʱ�ȭ �ϴ� �κ��� ���� ��.
	new (p) Sample;
	p->foo();
}

// ��� : trivial �� ����
// 1. �����Լ��� ����,
// 2. ��ü�� ����� ���ų�, ��ü�� ����� �����ڰ� trivial �ϰ�
// 3. ��� Ŭ������ ���ų�, ��� Ŭ������ �����ڰ� trivial �ϰ�
// 4. ����ڰ� ���� �����ڰ� ���ٸ�,
// => �����ڴ� trivial �ϴ�.

// �����ڸ� �����Ϸ��� ����� �شٰ� �ؼ�, �����ڰ� �ϴ� ���� ���� ���� �ƴ�