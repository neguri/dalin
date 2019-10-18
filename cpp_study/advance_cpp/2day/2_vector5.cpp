#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector<int> v1(10);
	vector<bool> v2(10);

	auto a1 = v1[0];
	auto a2 = v2[0];

	cout << typeid(a1).name() << endl;
	cout << typeid(a2).name() << endl;

	// �ٽ� 1
	// modern effective c++. vector<bool> �� ��ȯ�ϴ� ���� bool �� �ƴ�.
	/*
	class std::_Vb_reference<struct std::_Wrap_alloc<class std::allocator<unsigned int> > >
	*/

	for (auto a : v1) 
		cout << a << endl;

	// �ٽ� 2: range for �� ����ϸ�, auto& ��� ����. �ֳĸ� �ӽ� ��ü�̹Ƿ�
	// �����̳ʰ� temporary(rvalue)�� ��ȯ�ϴ� ��찡 ����. auto&&(forwarding reference)�� ����
	//for (auto& a : v2)  // error
	for (auto&& a : v2)
		cout << a << endl;
}