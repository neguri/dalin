#include <iostream>
#include <memory>
#include <string>

using namespace std;

struct People {
	string name;
	People(string n) : name(n) { }
	~People() { cout<< name << " �ı�" << endl; }
	weak_ptr<People> bestFriend;
};

int main()
{
	shared_ptr<People> sp1;
	weak_ptr<People> wp1;

	shared_ptr<People> sp2 = make_shared<People>("Kim");

	// sp1 = sp2; // ���� ��� 2
	wp1 = sp2;  // ���� ��� ���� ����. 
	cout << sp2.use_count() << endl;

	//---------------------
	shared_ptr<People> sp3 = make_shared<People>("lee");
	shared_ptr<People> sp4 = sp3;
	weak_ptr<People> wp4 = sp3;

	// �Ʒ� �ڵ�� �����Ѱ�? 
	string s1 = sp4->name;   // sp�� ���� �ִ� ���� ��ü�� �ı��� �� ����. 
								// dangling �����Ͱ� ���� �� ����. 

	//string s2 = wp4->name; 	// error. wp4�� ��� �ִٰ� �ص� ��ü�� ��� �ִٴ� ������ ����
	// �׷��� -> �� *  =�����ڰ� ������ �Ǿ� ���� �ʴ�.

	// wp�� �����Ϸ���,  ���� ����� �ø��� �����ؾ� �Ѵ�.
	// ���� ����� �ø��� ����� "shared_ptr"�� ������ �Ѵ�.

	shared_ptr<People> sp5 = wp4.lock();  // lock �ϴ� ���߿� sp3�� �Ҹ��ڴ� �ȺҸ�.
	if (sp5) {
		string s3 = sp5->name;
	}
}
