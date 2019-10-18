#include <iostream>

using namespace std;
/*
class A {
	int a;
public:
	void foo() { cout << "1" << endl; }
};

class B {
	int b;
public:
	void goo() { cout << "2" << endl; }
};

int main ()
{
	A aaa;
	B* p = reinterpret_cast<B*>(&aaa);
	p->goo();  // 2 goo(p)
	return 0;
}
*/

/*
class A {
	int a;
public:
	virtual void foo() { cout << "1" << endl; }
};

class B {
	int b;
public:
	virtual void goo() { cout << "2" << endl; }
};

int main ()
{
	A aaa;
	B* p = reinterpret_cast<B*>(&aaa);
	p->goo();  // 1 , p->vtptr[1]() �̶�� ���� �ڵ� ����
	return 0;
}
*/

/*
class A {
	int a;
public:
	virtual void foo() { cout << "1" << endl; }
};

class B {
	int b;
public:
	void goo() { cout << "2" << endl; }
};

int main()
{
	A aaa;
	B* p = reinterpret_cast<B*>(&aaa);
	p->goo();  // 2
	return 0;
}
*/
class A {
	public:
	virtual void foo(int n = 10) { cout << "A " << n<< endl; }
};

class B : public A {
public:
	virtual void foo(int n = 20) { cout << "B " << n << endl; }
};

int main()
{
	A* p = new B;
	p->foo();
	// B  , 10
	// default ���� �����ϴ� ���� ���� ������ �ϴ� ����. �׷��� ���ڸ� ���� ���ϸ� 10 �� ������ ����
	// p->vtptr[1](10) �̶�� ���� �ڵ带 ����
	// �ᱹ �����Լ����� default parameter�� ����ϸ� �ȵ�
	return 0;
}
