#include <iostream>
#include <memory>
#include <string>

using namespace std;



struct People {
	string name;
	People(string n) : name(n){ }
	~People() { cout << name << " �ı�" << endl; }
	shared_ptr<People> bestFriend;
};

int main()
{

	shared_ptr<People> sp1 = make_shared<People>("Kim");
	 shared_ptr<People> sp2 = make_shared<People>("Lee");

	// ���θ� ����Ų�� (cycle reference) - ���� . �޸� ���� �ȵ�
	sp1->bestFriend = sp2;
	sp2->bestFriend = sp1;
}