#include <iostream>

using namespace std;

// �ߺ����� �ʰ� ������ ���ϰ� �ʹ�.
// ���� ���� �ʿ�

// �Լ��� ������ ������ ���°� ����.
int random() {
	return rand() % 10;
}

int main()
{
	for (int i = 0; i < 10; i++) {
		cout << random() << endl;
	}
}