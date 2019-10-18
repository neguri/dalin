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

	// (2) �����ڸ� ������ �غ���
	// T operator[] (int idx) { ���� ��ȯ�ϸ� �ȵ�. ���� ��ȯ�ϸ� , v[0] = 0; ���� ������ �� �� ����
		T& operator[] (int idx) {
		return buff[idx];
	}
};

int main()
{
	vector<int> v(10);

	// (1) �Ʒ� �ڵ尡 �Ƿ��� ������ �����Ǹ� �ؾ� ��
	v[0] = 100;			// v.operator[](0) = 100;
	cout << v[0] << endl;
}