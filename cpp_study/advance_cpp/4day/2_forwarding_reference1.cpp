#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n = 10;

	// ���纻 ����. ���� ����
	auto a1 = n;
	auto a2 = 10;


	auto& a3 = n;
	//auto& a4 = 10;  // error

	// auto�� ���ø��� ����.
	// foo(T arg); foo(10) => 10�� ���� T�� ����
	// auto arg = 10;  10�� ���� auto ����
	auto&& a5 = n;
	auto&& a6 = 10;

	vector<bool> v(10, 0);
	auto			a10 = v[0]; /// �ӽ� ��ü�� �ִ� ��
	auto&		a11 = v[0]; // �ӽ� ��ü�� & �� ���� ������
	auto&&	a12 = v[0]; // && �� forwarding reference�� ���� �ƴ�. &&�� ��� Ÿ���� ���� �� ����
}