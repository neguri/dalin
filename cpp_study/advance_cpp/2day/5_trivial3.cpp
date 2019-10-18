#include <iostream>
#include <type_traits>
using namespace std;

// https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/include/utils/TypeHelpers.h

// �����Ҷ� ��� ��Ҹ� �ѹ��� ������ ������,
// �ƴϸ� �ϳ��� ������ ���鼭 ������ ������.
template<typename T>
void copy_type(T* dst, T* src, int sz) {
	if (is_trivially_copyable_v<T>) {
		// ���� �����ڰ� �ϴ� ���� ����
		cout << "���� �����ڰ� �ϴ� ���� ����" << endl;
		memcpy(dst, src, sizeof(T)*sz);
	}
	else {
		cout << "���� �����ڰ� �ϴ� ���� ������ ��� ��ҿ� ���� ����" << endl;
		while (sz--) {
			new (dst) T(*src);
			++dst, ++src;
		}
	}

}

struct Point1{
	int x, y;
};

struct Point2 {
	int x, y;
	
	Point2(const Point2& p) : x(p.x), y(p.y){
	}

	Point2() = default;
};

struct Point3 {
	int x, y;

	Point3(const Point3 & p) = default;

	Point3() = default;
};


int main()
{
	char s1[10] = "Hello";
	char s2[10];

	// �Ϲ�ȭ ������ ������
	//strcpy(s2, s1);

	copy_type<char>(s2, s1, 10);

	Point1 p1[10];
	Point1 p2[10];
	copy_type<Point1>(p2, p1, 10);

	Point2 p3[10];
	Point2 p4[10];
	copy_type<Point2>(p3, p4, 10);

	Point3 p5[10];
	Point3 p6[10];
	copy_type<Point3>(p5, p6, 10);
}

/*
// https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/include/utils/TypeHelpers.h
template<typename TYPE>
typename std::enable_if<traits<TYPE>::has_trivial_copy>::type
inline
copy_type(TYPE* d, const TYPE* s, size_t n) {
	memcpy(d,s,n*sizeof(TYPE));
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