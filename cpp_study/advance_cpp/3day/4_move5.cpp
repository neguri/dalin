#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	const string s1 = "hello";	// (1) const ��ü�� move�ص� �ڿ��� �״�� ������ ����
	//string s2 = s1;
	string s2 = std::move(s1);
	cout << s1 << endl;

	vector<int> v1(10, 3);
	//vector<int> v2 = v1;			// (2) ����
	vector<int> v2 = std::move(v1);	//(3) ����. �����͸� ����

	cout << v1.size() << endl;
}