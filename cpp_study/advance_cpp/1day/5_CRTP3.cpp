#include <iostream>
using namespace std;
/*
class MaxObject {
	static int cnt;
public:
	MaxObject() { if (++cnt > 5) throw 1; }
	~MaxObject() { --cnt; }
};
int MaxObject::cnt = 0;
class Truck : public MaxObject{
};

class Car : public MaxObject {
};

int main() {
	Truck t1[3];
	Car		t2[2];
}
*/

// CRTP�� ����ؼ� ���� �ٸ� ��� Ŭ������ ����� �ڵ�

template<typename T>
class MaxObject {
	static int cnt;
public:
	MaxObject() { if (++cnt > 5) throw 1; }
	~MaxObject() { --cnt; }
};

// Ŭ���� ���ø��� static ����� �ܺο��� �����ϴ� ���
template<typename T>  int MaxObject<T>::cnt = 0;

class Truck : public MaxObject <Truck>{
};

class Car : public MaxObject <Car>{
};

int main() {
	Truck t1[3];
	Car		t2[3];
}