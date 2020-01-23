#include <iostream>
#include <memory>
#include <string>

using namespace std;

struct People {
	string name;
	People() = default;
	People(string n) : name(n) { }
	~People() { cout << name << " �ı�" << endl; }
	// shared_ptr<People> bestFriend;  // -> �Ϲ� �����ͷ� ����

	// ��� ����Ÿ�� ���� ���� ���� �ʴ´�.
	// People* bestFriend;

	weak_ptr<People> bestFriend; 
	// ���� ����� �������� �ʴ� ����Ʈ ������. 
	// ��ü �ı� ���� ���� ����
};

int main()
{

	shared_ptr<People> sp1 = make_shared<People>("Kim");
	{
		shared_ptr<People> sp2 = make_shared<People>("Lee");

		sp1->bestFriend = sp2;  // weak�� shared�� ȣȯ
		sp2->bestFriend = sp1;
	}

	if (sp1->bestFriend.expired()) {   // expired() �� �Ǵ� ����
		cout << "��ü �ı���" << endl;
}