#include <iostream>

using namespace std;

// Traits (Ư��):  Ÿ���� �پ��� �Ӽ��� �����ϴ� ���

template<typename T> void printv(T v) {
	// (1) �̷��� �� �� ���� ��? 
	if (T �� �����Ͷ��) {
		cout << v << ' ' << *v << endl;
	}
	else {
		cout << v << endl;
	}
}

int main()
{
	int n = 10;
	printv(n);
	printv(&n);
}
