#include <iostream>
#include <string>

using namespace std;

// rule of 3
// �����Ͱ� �ְ� �����ڿ��� �ڿ� �Ҵ��ϸ�
// �Ҹ���, ���� ������, ���� �����ڰ� �ʿ��ϴ�.

class People {
	string		name;
	int			age;
	char*		addr;
public:
	People(string n, int a, const char* ad) : name(n), age(a) {
		addr = new char[strlen(ad) + 1];
		strcpy(addr, ad);
	}
	~People() {
		delete[] addr;
	}

	// �����Ͱ� ����� �����ϱ�, ���� �����ڸ� �� ������ ��
	People(const People& p) :name(p.name), age(p.age) {
		addr = new char[strlen(p.addr) + 1];
		strcpy(addr, p.addr);
	}

	// ���� �����ڸ� ���� ���� ��κ� ���� �����ڵ� �ʿ��ϴ�
	// �׷��� ������ ���� ���� ���α׷��� ���� ��

	// ��Ģ 1. ������ ��ȯ���� �ڽ��� ������ �ؾ� �Ѵ�.
	// ��Ģ 2. �ڽŰ��� ������ �����ؾ� �Ѵ�
	// ��Ģ 3. ��� Ŭ������ �ִٸ� ��� Ŭ������ ���� �����ڵ� ȣ���ؾ� ��
	// ��Ģ 4. ���ܿ� �����ϰ� �ۼ��ؾ� �Ѵ�.

	People& operator=(const People& p) {

		// �ڽŰ��� ���� ����
		// p1 = p1 �̷��Ե� �����ѵ�, �׷��� delete [] addr���� ���� �߻�.
		// �ֳĸ� int i; i = i; �� ������ �����ϹǷ�, ����� �߻��� �� �ִ� ����
		if (&p == this) return *this;

		// ��� Ŭ������ �ִٸ� ��� Ŭ������ ���� �����ڵ� ȣ���ؾ� �Ѵ�.
		// Base::operator=(p); (��� ���� Ŭ������ ���)

		// ��� ������ �����Ͱ� �ƴϸ� �׳� ����
		name = p.name;
		age = p.age;

		// �����ʹ� ���� �޸𸮸� �����ϰ�, ���ο� �޸𸮿� ����
		delete[] addr;
		addr = new char[strlen(p.addr) + 1];
		strcpy(addr, p.addr);
		return *this;
	}
};

int main()
{
	People p1("kim", 10, "seoul");
	People p2 = p1;  // ���� ������
	p2 = p1;					// ���� ������ p2.operator=(p1)

	int n  = 10;
	(n = 20) = 30;
}