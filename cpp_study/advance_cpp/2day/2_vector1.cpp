#include <iostream>

using namespace std;

class Point {
	int x, y;
public:
	Point(int a, int b) :x(a), y(b) {
		cout << "Point()" << endl;
	}

	Point(const Point& p)
	{
		cout << "Point copy" << endl;
	}

	~Point() { cout << "~Point()" << endl; }
};

template<typename T> class vector {
	T* buff;
	int sz;
public:

	vector(int s, T value = T()) : sz(s) {
		buff = static_cast<T*>(operator new(sizeof(T)*s));

		/*
		int cnt = 0;
		try {
			for (int i = 0; i < sz; i++) {
				// new (&buff[[i]) T;			// ����Ʈ ������
				new(&buff[i])T(value);  // ���� ������
				cnt = i;
			}
		}
		catch (...) {
			// ������ ȣ�⿡ ������ ��ü�� �ٽ� �Ҹ��� ȣ��
			for (int i = 0; i < cnt; i++) {
				buff[i].~T();
			}
			operator delete(buff);
		}
		*/

		// buff ���� sz ������ ŭ value�� ä���� (���� ������)
		// �����ϸ� ������ ���� �Ҹ� �� ȣ�� �� ���� �߻�
		try{
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
};

int main()
{
	vector<int> v(10);
	Point pt(0, 0);
	vector<Point> p(10, pt);

	// Ȥ��
	vector<Point>p2(10, { 0,0 });
}