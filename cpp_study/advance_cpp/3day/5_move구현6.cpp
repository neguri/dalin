#include <iostream>
#include <string>
#include <vector>

using namespace std;

// rule of 0
// �ڿ� ������ ���� �ϴ� �ڵ�� ������ ����.

// const char* => string
// int* buff = vector;
// �׷��� �����Ͱ� �ʿ��ϸ� => ����Ʈ������ ���

class People {
	string		name;
	string		addr;
	int			age;
public:
	People(string n, int a, string ad) : name(n), age(a), addr(ad) {
		
	}
	~People() {
	}
};

int main()
{
	People p("kim", 10, "seoul");
}
