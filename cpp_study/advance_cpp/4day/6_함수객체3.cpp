#include <iostream>
#include <bitset>
using namespace std;

// �ߺ����� �ʰ� ������ ���ϰ� �ʹ�.
// ���� ���� �ʿ�

// �Լ��� ������ ������ ���°� ����.
// �Լ� ��ü�� ��� 1. ���¸� ���´�.

class URandom {
	//  ��� �����͸� ���� ���¸� ǥ���� �� �ִ�.
	bitset<10> bs;
public:
	URandom() { bs.set(); }

	void reset() { bs.set(); }

	int operator()() {
		if (bs.none())  return -1;
		int k = -1;
		while (!bs.test(k = rand() % 10));
		rand() % 10;
		return k;
	}
};
/*
int random() {
	return rand() % 10;
}
*/
int main()
{
	URandom random;
	for (int i = 0; i < 10; i++) {
		cout << random() << endl;
	}
}