#include <iostream>
#include <string>
using namespace std;
 
template <typename T, typename U > struct PAIR {
	T first;
	U second;
	PAIR() = default;
	 
	// (1) �����ڸ� ����� ����
	// rvalue, lvalue ��� �ޱ� ���� const�� ���δ�.
	PAIR(const T& a, const U& b) : first(a), second(b) {
		cout << "copy" << endl;
	}
	
	// (3) move�� ���ؼ� ���� ����
	PAIR(T&& a, U&& b) : first(move(a)), second(move(b)) {
		cout << "move" << endl;
	}

	// C++11 ���� : ������ (�Լ� ����)�� const T&�� �ַ� ���
	// C++11 ����: move ������ ���� 2���� �����ڸ� ������ ��.
	// 1. const T&
	// 2. rvalue refence ����: move ����


};

int main()
{
	PAIR<int, int> p1(3, 4);

	string s1 = "hello";
	string s2 = "world";
	PAIR<string, string> p2(s1, s2);
	cout << "----" <<endl;
	// (2) move �ϴ���  �������� Ÿ���� const�� �ޱ� ������ ���簡 ��
	PAIR<string, string> p3(move(s1), move(s2));
	cout << s1 << endl;
}