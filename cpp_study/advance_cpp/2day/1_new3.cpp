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
	
	// value�� ������, Ȥ�� ���ָ� T�� default ���� ��� : zero initialization �̶�� �θ�
	// T ��  primitive �Ǵ� �������̸�  : 0
	//           user type�̸� ����Ʈ ������

	vector(int s, T value = T()) : sz(s) {
		
		// 1. �̷��� �����̳ʸ� �����, �ȵ�. ����Ʈ ������ ������ ���� ����
		// �ᱹ �����̳� ���� �� �䱸 ���� �� ������ ���� ��
		//buff = new T[sz];

		// 2. ���� �̷��� ������ ��
		buff = static_cast<T*>(operator new(sizeof(T)*s));

		// 3. �Ҵ�� �޸𸮿� ������ ȣ��
		// ������ T �� � Ÿ������ �𸣴� � �����ڸ� �θ� �� ����.
		// ���� �����ڸ� �θ��� ���� �⺻ ����

		// 4. �޸� �Ҵ� �� ������ ȣ�� �� ���� ��Ȳ �߻��� �ڿ������� �ϵ��� ��
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
		
	}

	~vector(){
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

}