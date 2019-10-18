#include <iostream>
using namespace std;

template<typename T> class vector {
	T* buff;
	int sz;
public:

	vector(int s, T value = T()) : sz(s) {
		buff = static_cast<T*>(operator new(sizeof(T)*s));
		try {
			std::uninitialized_fill_n(buff, sz, value);
		}
		catch (...) {
			operator delete(buff);
		}
	}
	~vector() {
		for (int i = 0; i < sz; i++) {
			buff[i].~T();
		}
		operator delete(buff);
	}
	T& operator[] (int idx) {
		return buff[idx];
	}
};


template<> class vector <bool> {
	int* buff;
	int sz;
public:

	vector(int s, bool value = false) : sz(s) {
		int cnt = sz / 32 + 1;
		buff = static_cast<int*>(operator new(sizeof(int)*cnt));
		
		// buff ���� sz ��Ʈ�� value�� ä���

	}
	~vector() {
		operator delete(buff);
	}

	// bit�� ��ȯ�ؾ� �ϴµ� ��� ��ȯ�� �� ������???
	?& operator[] (int idx) {
		return buff[idx];
	}
};

int main()
{
	vector<int> v(10);
	// (1) bool�� �����ϱ⿣ �޸� ���� �ִ�.
	vector<bool> v2(30);
}