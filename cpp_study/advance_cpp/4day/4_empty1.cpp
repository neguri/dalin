//73 page
#include <iostream>

using namespace std;

// Empty Ŭ����, non static member data�� ���� �Լ��� ���� Ŭ����
class Empty {
	public:
	~Empty() {}
};

int main()
{
	Empty e;
	cout << sizeof(e) << endl;  //  1

	// �ٽ�: empty class�� ũ��� 1

}