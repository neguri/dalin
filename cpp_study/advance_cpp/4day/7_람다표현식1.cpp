#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
	// ���� ǥ���� 
	// Ȱ�� 1. STL ��� �� �˰��� �Լ��� ���ڷ� ����
	sort(x, x + 10, [](int a, int b)  { return a < b; });

	// Ȱ�� 2. auto ������ ��Ƽ� �Լ�ó�� ���
	auto f = [](int a, int b) -> int { return a + b; };  // �� ��ü�δ� �Լ��� �ƴ϶� ��ü��. (�Լ�, �ӽ� ��ü)

	int n = f(1, 2);
	
	auto f1 = []() {};  // Ŭ������ ������µ�, �ӽ� ��ü 
	//auto& f2 = []() {};  // �ӽ� ��ü �̹Ƿ� rvalue . ����
	auto&& f3 = []() {};  // rvalue �̹Ƿ� forwarding referece ��. 

	decltype(f1) f4;		// error. ����ǥ������ default �����ڴ� ����.
	decltype(f1) f5(f1);
}

/*
https://en.cppreference.com/w/cpp/language/lambda
Constructs a closure: an unnamed function object capable of capturing variables in scope.
*/