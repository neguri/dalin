#include <iostream>
#include <memory>

using namespace std;

int main()
{
	int* p1 = new int;

	shared_ptr<int> sp1(p1);  // ���� ��ü ����
	shared_ptr<int> sp2(p1); // �ٸ� ���� ��ü �� ����

	// �ٽ� : �ڿ��� ȹ���� �Ŀ�, �ڿ��� �����͸� �ڿ� ���� ��ü�� ������ �ȵ�

	// �ڿ��� ȹ���� �ڿ� ���� ��ü�� ����� ���� ���ÿ� �ؾ���
	shared_ptr<int> sp3(new int);  // �̷��� �ϴ°��� ����. �� make_shared�� ��� ��

	//  RAII : Resource Acquision Is Initialization.
}