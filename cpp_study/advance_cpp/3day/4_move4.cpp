#include <iostream>

using namespace std;


class Buffer {
	int* resource;
	int size;
public:
	Buffer(int sz) : size(sz) { resource = new int[sz]; }
	~Buffer() { delete[] resource; }

	Buffer(const Buffer& b) : size(b.size) {
		resource = new int[size];
		memcpy(resource, b.resource, sizeof(int)*size);
		cout << "���� ������" << endl;
	}


	Buffer(Buffer&& b) : size(b.size) {
		resource = b.resource;
		b.resource = 0; 
		cout << "�̵� ������" << endl;
	}
};

Buffer foo() {
	Buffer buf(1024);
	return buf;
}

int main()
{
	Buffer ret = foo();	 // move
	Buffer b1(1024);
	Buffer b2 = b1;		 //copy
							 
    //Buffer b3 = b2;													// (1) �� ������ ���̻� b2�� �ʿ� ����. move ������ �� ����.
	Buffer b3 = static_cast<Buffer&&>(b2);     // (2) move�����ϱ� ���ؼ� b2�� rvalue�� ĳ����
	//Buffer b4 = std::move(b3);							 // (3) ���� ���� casting��  move �ȿ��� ó���ϰ� ����(ǥ�� ���)

	const Buffer cb(1024);

	Buffer b5 = cb;													 // const ��ü �̹Ƿ� ���� ����
	//Buffer b6 = static_cast<Buffer&&>(cb); // (4) ���� ����. const �Ӽ����� ��ȯ �Ұ�
	Buffer b6 = static_cast<const Buffer&&>(cb); // (5) ���縦 �θ�. && �� ĳ���������� const�� �־ ���縦 ȣ��
	Buffer b7 = std::move(cb);   // ���� ������

	// ��� : const ��ü�� move �� �� ����.
}