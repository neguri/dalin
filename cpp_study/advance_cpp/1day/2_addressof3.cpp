#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	// �ּ� �����ڸ� ������
	Point* operator&()  const {
		return nullptr;
	}
};

template<typename T> 
T* xaddressof(T& obj)  {   // �ּҸ� �����;� �ϴϱ�, ���簡 �ƴ� ������ �;� ��.
	// 1 . ����� ����
	//T* p = const_cast<T&>(obj);
	// 2. �ٸ� Ÿ������ ĳ����
	//T* p = &reinterpret_cast<char&>(const_cast<T&>(obj));
	// 3. ������ Ÿ������ ����

//	T* p = reinterpret_cast<T*>( &reinterpret_cast<char&>(const_cast<T&>(obj)));

	T* p = reinterpret_cast<T*>(   // const Point* �� ��ȯ
				&const_cast<char&>(  // const volatile ����. volatile ���� ������ ������ volatile�� ���� �� �־�
				reinterpret_cast<const volatile char&>(obj)));

	return p;
}

int main() {
	const Point pt;
	const Point* p1 = reinterpret_cast<const Point*>(&reinterpret_cast<char&>(const_cast<Point&>(pt)));

	// �̷��Ե� ������, const �Ӽ��� �������Ƿ� const�� �ٿ���� �Ѵ�.
	Point* p2 = reinterpret_cast<Point*>(&reinterpret_cast<char&>(const_cast<Point&>(pt)));
	cout << p1 << endl;
	cout << p2 << endl;

   const Point* p3 = xaddressof(pt);
	cout << p3 << endl;

}