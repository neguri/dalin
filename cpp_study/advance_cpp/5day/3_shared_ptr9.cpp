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
	shared_ptr<People> sp = make_shared<People>("Kim");
	
	shared_ptr<People> = new (People)("Kim");
	weak_ptr<People> = sp;
}

// ���� ��ü�� �Ʒ� 4���� ������ ����
// 1.  ��ü ����
// 2. ��ü �ּ�
// 3. weak ptr counter
// 4.  ������

// �׷��� shared ptr�� ���� ��ü�� ���� �Ǵ� ������ weak ptr�� ���� �ɶ���.
// �ֳĸ� weak ptr���� use_count ���� ���� �ҷ��� �ϱ� ����. 