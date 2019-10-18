#include <iostream>

using namespace std;

struct Animal {
	virtual void Cry() { cout << "Animal cry" << endl; }
	virtual ~Animal() {}
};

struct Dog : public Animal {
	virtual void Cry() { cout << "Dog cry" << endl; }
};

int main() {
	Dog d;				d.Cry();
	Animal& a1 = d; a1.Cry();
	Animal a2 = d; a2.Cry();   // ��ü �����̽��� �߻��ϰ�, a2���� dog �� �ƴ� animal �κг� ���´�.
}