#include <iostream>
#include <type_traits>
using namespace std;
>> ���� ����
class Point {
public:
	int x, y;
};


#define CHECK_VALUE_CATEGORY(...)											\
if (is_lvalue_reference<decltype ((__VA_ARGS__)) >::value)  \
	cout << __VA_ARGS__<<" : lvalue" << endl;								\
else if(is_rvalue_reference<decltype ((__VA_ARGS__)) >::value)	\
		cout << __VA_ARGS__<<" : rvalue(xvalue)" << endl;			\
else																													\
	cout << __VA_ARGS__<<" : rvalue(prvalue)" << endl;



int main()
{
	// value category�� �����ϴ� ���
	int n = 0;
	CHECK_VALUE_CATEGORY(10)
	Point pt;
	CHECK_VALUE_CATEGORY(pt)
	CHECK_VALUE_CATEGORY(Point())
	CHECK_VALUE_CATEGORY(Point().x)
}