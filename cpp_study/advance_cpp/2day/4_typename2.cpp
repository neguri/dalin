#include <iostream>
//#include <vector>

using namespace std;

template<typename T> class vector {
public:
	typedef unsigned int size_type;
	// size( )��� ��� �Լ��� �־�� �ϰ�
	// size_type �̶�� ���� �����Ǿ� �־�� ��
	size_type size() const { return 10; }
};

//void foo(vector<int>&v) {
template<typename T> void foo(vector<int>&v) {
	// ? �� �� ������ Ÿ����? 
	//? = v.size();
	vector<int>::size_type n = v.size();
	typename T::size_type n = v.size();
}
 
int main()
{
	vector<int> v(10);
	foo(v);
}