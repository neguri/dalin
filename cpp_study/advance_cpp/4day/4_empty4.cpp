#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
	//vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	list<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = v.begin();
	++p;	// ��� �ݺ��ڴ� ++  ������ �����ϴ�.
	
	// p = p + 5;	// ���� ���� �ڵ� : ���� ���� �ݺ��ڸ� ����
	// container �� Ÿ���� ����, p++ or p = p+5 �� �ϵ��� ��
	advance(p, 5); // <-- �� ����� ����

	cout << *p << endl;

}