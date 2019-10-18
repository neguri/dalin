// 215 page
#include <iostream>
using namespace std;

// 1. foo(10) -> template ������ ����ϱ�� ����
// 2. T::type �� int::type���� ġȯ�ϰ� �Ǹ� , �߸��� ǥ���� ����
// ������ ������ �ƴ϶� �ĺ������� ����

// 3. �ٸ� ������ foo �� ������ ��� ����
// "ġȯ ���д� ������ �ƴϴ�", substitution failure is not an error. (SFINAE)

// T�� int�̸� T::type �̶� ǥ���� ����
template<typename T> typename T::type foo(T a) { cout << "T" << endl;  return 0; }
template<typename T> void foo(T a) { cout << "T" << endl;  }
 
//void foo(int	 a) {	cout << "int" << endl; }
void foo(...) { cout << "..." << endl; }



int main()
{
	foo(10);
	// 1. int
	// 2. T -> template 
	// 3. ..
}