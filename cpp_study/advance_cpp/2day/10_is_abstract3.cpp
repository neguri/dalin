#include <iostream>
#include <type_traits>

using namespace std;

class Shape {
	virtual void Draw() {};
};

/*
template<typename U> struct xis_abstract {
	template<typename T> static char check(T(*)[1]);  // static ���̴� ������ ��� �Լ� �̹Ƿ� ��ü ���� �θ��� ����
	template<typename T> static int check(...);

	static constexpr bool value = (sizeof(check<U>(0)) == sizeof(char));
};
*/
// int �� char �� ũ�Ⱑ ���� �� �����Ƿ�( int�� char���� ũ�ų� ����)

template<typename U> struct xis_abstract {
	typedef char YES[1];
	typedef char NO[2];

	template<typename T> static NO& check(T(*)[1]);  // static ���̴� ������ ��� �Լ� �̹Ƿ� ��ü ���� �θ��� ����
	template<typename T> static YES& check(...);

	static constexpr bool value = (sizeof(check<U>(0)) == sizeof(YES));
};

int main()
{
	cout << xis_abstract<Shape>::value << endl;
}