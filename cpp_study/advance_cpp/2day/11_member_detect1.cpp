#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

class Test {
public:
	Test(int n) {}
	void resize(int n ) {}
};

template<typename T> T xdeclval();  // declval �� ǥ����. �ٽ� ������ ����.
// T&& �� �´� ǥ����
// https://en.cppreference.com/w/cpp/utility/declval


template<typename U> struct has_resize_function {
	typedef char YES[1];
	typedef char NO[2];

	// template<typename T> static YES& check(decltype(T().resize(0) )* n);  (2)
	// template<typename T> static YES& check(decltype(T().resize(0) )* n);  * �� ���̴� ������ void Ÿ���� ��츦 ����ؼ�. 
	// T() �� default �����ڰ� �־�� ��.
	template<typename T> static YES& check(decltype(xdeclval<T>().resize(0))* n);
	template<typename T> static NO& check(...);

	static constexpr bool value = (sizeof(check<U>(0)) == sizeof(YES));
};

int main()
{
	cout << has_resize_function<vector<int> >::value << endl;
	cout << has_resize_function<Test>::value << endl; // (3) Test�� ��� default �����ڰ� ��� 0 �� ����
}