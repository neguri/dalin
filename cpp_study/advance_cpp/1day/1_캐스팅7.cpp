#include <iostream>

using namespace std;

class Animal {
	// (5) ���� �Լ��� ������, ���� �Լ� ���̺��� ����� ���� �� �ȿ� Ÿ�� ������ ���� ��.
	// �� ��ä�� ���̺��� ����Ű�� �� ���� ����
	// �ᱹ ���� �Լ��� ���� ��ü�� dynamic_cast�� ����� �� ����.
public:
	virtual ~Animal() {

	}
};

class Dog : public Animal {
public:
	void Cry() {}
};

void foo(Animal* p) {
	// (1) Ȥ�� p �� Dog �̶�� �Ʒ� ó�� �ϰ� ����
	// p->Cry(); �׷��� ����

	// (2) �׷��� �̷���. Down Casting ������. (��� Ÿ���� �Ļ� Ÿ������)
	// (3) static cast �̹Ƿ� ������ �ð��� ó���ϰ� �Ǵµ�, ������ �ð��� dog���� �ƴ��� ��.
	//Dog* pDog = static_cast<Dog*>(p); // ����̶�� �������� �����Ƿ� ������ �� ��.
	//cout << pDog << endl;

	//(4) p�� ���� Dog�϶��� �����ؾ� ��
	// ������ ������ �ƴ� ���� �ð��� ������ �� ĳ����.
	// �׷��� �����ϸ� ������.
	Dog* pDog = dynamic_cast<Dog*>(p);
	cout << pDog << endl;

}

int main()
{
	Animal a; foo(&a);
	Dog		d; foo(&d);
}


// C++ ĳ����
// static cast
// reinterpret cast - ������ �ð� : ���� �ٸ� Ÿ�Կ� ���ؼ� ĳ����
// const_cast   - ������ �ð�
// dynamic_cast ���� �ð�(������尡 ����) - ��� ���迡 ���� ���� ���