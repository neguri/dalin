#include <iostream>

using namespace std;

int main()
{
	int n = 10;
	int* p1 = &n;
	int* * p2 = &p1; // ������ ������ ������

	int& r1 = n;
	int&& r2 = n;   // ���۷����� ���۷��� - error
}