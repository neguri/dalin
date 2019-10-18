#include <iostream>

using namespace std;

// 1. Ŭ���� �ȵ� ������ ������ ������ ���� ���� ������ ����.
// 2. �ݵ�� ���� �����ڸ� ����ڰ� ������ �Ѵ�.

class Buffer {
	int* resource;
	int size;
public:
	Buffer(int sz) : size(sz) { resource = new int[sz]; }
	~Buffer() { delete[] resource; }

	// (2) ���� ���縦 �ϴ� ���� ������ �����
	Buffer(const Buffer& b) : size(b.size) {
		resource = new int[size];
		memcpy(resource, b.resource, sizeof(int)*size);
	}
};

int main()
{
	Buffer b1(1024);
	Buffer b2 = b1;  // (1) �̼��� ���� ���簡 �Ǿ� ����� �װ� ��
}