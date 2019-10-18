// https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/include/utils/TypeHelpers.h

/* 
template<typename TYPE>
typename std::enable_if<traits<TYPE>::has_trivial_copy>::type
inline
copy_type(TYPE* d, const TYPE* s, size_t n) {
	memcpy(d, s, n * sizeof(TYPE));
}

template<typename TYPE>
typename std::enable_if<!traits<TYPE>::has_trivial_copy>::type
inline
copy_type(TYPE* d, const TYPE* s, size_t n) {
	while (n > 0) {
		n--;
		new(d) TYPE(*s);
		d++, s++;
	}
}
*/
// 103.page
#include <iostream>

using namespace std;

class Point {
	int x, y;
public:
	Point(int a = 0, int b = 0) :x(a), y(b) {
		cout << "Point()" << endl;
	}

	~Point() { cout << "~Point()" << endl; }

};
/*
int main()
{
	// 1. �޸𸮸� �Ҵ�
	// 2. �����ڸ� ȣ��
	Point* p1 = new Point(1, 2);

	// 1. �Ҹ��� ȣ��
	// 2. �޸� ����
	delete p1;
}
*/
int main()
{
	// �޸� �Ҵ�� ������ ȣ���� �и�
	// 1. �޸� �Ҵ� . C�� mallock �� ���� ( �����ڴ� �Ҹ��� ����)
	Point* p2 = static_cast<Point*>(operator new(sizeof(Point)));
	cout << p2 << endl;

	// 2. �Ҵ�� �޸𸮿� ������ ȣ�� - Placement new ��� �����
	// new Point(1, 2); �޸� �Ҵ� +  ������ ȣ��		
	new (p2) Point(1, 2);   // �����ڸ� ȣ��

	// 3. �Ҹ��ڸ� ȣ��
	p2->~Point();  // �޸� ���� ���� �Ҹ��ڸ� ȣ��. �����ڴ� p2->Point(1,2) ó�� �� �θ�.
	
	// 4. �Ҹ��� ȣ�� ���� �޸𸮸� ����
	operator delete(p2);
	
}