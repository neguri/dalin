
#include <iostream>
#include <type_traits>
#include <tuple>

using namespace std;

class Empty {};

int main() {
	tuple<Empty, int > t;
	cout << sizeof(t )<< endl;
	// g++		: 4 (compressed  pair �� �� �ʿ� ����)
	// vc++	: 8
}