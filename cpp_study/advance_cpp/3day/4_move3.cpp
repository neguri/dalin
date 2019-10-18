#include <iostream>

using namespace std;


class Buffer {
	int* resource;
	int size;
public:
	Buffer(int sz) : size(sz) { resource = new int[sz]; }
	~Buffer() { delete[] resource; }

	// C++11 �������� ���� �����ڸ� �־���.
	// �̸� �ִ� ��ü�� ���� ��ü�� ������ �˰��� ���

	// C++11 ���� : �ӽð�ü�϶� �����ϴ� ���
	//								�̸� �ִ� ��ü�϶��� �����ϴ� ����� �и��ؼ� ����ȭ����.

	Buffer(const Buffer& b) : size(b.size) {
		resource = new int[size];
		memcpy(resource, b.resource, sizeof(int)*size);
		cout << "���� ������" << endl;
	}

	// ���ڷ� �ӽð�ü�� �ö��� �޸𸮸� ��°�� ������ �ʿ䰡 ����.
	// �ּҸ� �����ؿ��� �ȴ�. 
	Buffer( Buffer&& b) : size(b.size) {  // <------(3)
		resource = b.resource;
		b.resource = 0;   // ���� �ּ� �����Ϳ� 0�� �־�� �ϹǷ�, const�� ���� ��.
		cout << "�̵� ������" << endl;
	}
};

Buffer foo() {
	Buffer buf(1024);
	return buf;
}

int main()
{
	Buffer ret = foo();  // �ӽ� ��ü�� ��츸 , ���� ���簡 �ʿ�
	cout << "----" << endl;
	Buffer b1(1024);
	cout << "----" << endl;
	Buffer b2 = b1;
}