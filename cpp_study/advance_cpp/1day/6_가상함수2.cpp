#include <iostream>
using namespace std;

// �����Ϸ��� ������ �ÿ� ��� �����Լ��� �ּҸ� �޸𸮿� �����ؾ� ��.
// ���� �Լ��� ������ 4�� ũ���� �����Լ� ���̺��� ������.
void* animal_table[] = {		Animal_RTTI ����, &Animal::Foo, &Animal::Goo, &Animal::Cry};

class Animal {
	int age;
	void* vtptr;
public:
	Animal() : vtptr(animal_table){}

	virtual void Foo() {}
	virtual void Goo() {}
	virtual void Cry() { cout << "1" << endl; }
};
void* dog_table[] = { Dog_RTTI ����, &Animal::Foo, &Animal::Goo, &Animal::Cry };

class Dog : public Animal {
	int color;
	void* vtptr;
public:
	Dog() :vtptr(dog_table) {}
	void Cry() {
		cout << "2" << endl;
	}
};

int main()
{
	Animal a;
	Dog		d;
	Animal *p = &d;
	p->Cry(); // p->vtptr[3](p); ��� ���� �ڵ� ����
}
