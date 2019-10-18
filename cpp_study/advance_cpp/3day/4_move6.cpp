#include <iostream>
#include <vector>
#include <string>

using namespace std;



// �˰��� �Լ� ���۰� move

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


template <typename T> void Swap(T& a, T& b) {
	// ���� �����ڿ� ���� swap - ������
	/*
	T tmp = a;
	a = b;
	b = tmp;
	*/
	// move �����ڿ� ���� swap - ������

	T tmp = std::move(a);
	a = std::move(b);  // move ���� ������.
	b = std::move(tmp);
}

int main()
{
	Buffer b1(1024);
	Buffer b2(1024);
	Swap(b1, b2);

	string s1 = "hello";
	string s2 = "world";
	Swap(s1, s2);
	cout << s1 << s2 << endl;

	int n = 10; 
	int n1 = static_cast<int&&>(n);  // ������ �����̹Ƿ� ������� ����.
	int n2 = move(n);								// �����Ҵ�� �ڿ��� ������ �������� ���� �ƴ�
}