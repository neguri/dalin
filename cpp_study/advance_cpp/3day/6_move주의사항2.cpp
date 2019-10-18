#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Data {

};

class Test {
	Data data;
public:
	// C++11 �������� �Ʒ� �Ѱ��� ��
	void SetData(const Data& d) {	data = d;	}

	// C++11 ���Ŀ��� �Ʒ�ó�� move �����ϴ� �͵� ����� ��� ��
	void seData(Data&& d) { data = move(d); }
};

int main()
{
	vector<string> v;
	string s1 = "Hello";

	v.push_back(s1);
	cout << s1 << endl;  // Hello ���

	v.push_back(move(s1));
	cout << s1 << endl;   // Hello ��� �ȵ�
}