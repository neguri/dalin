
#include <iostream>

using namespace std;

class Empty {};

template<typename T, typename U> struct PAIR {
	T first;
	U second;

	PAIR() = default;

	template<typename A, typename B>  // (2) ������template�� �и� �ؾ� ��
	//PAIR( A&& a, B&& b) { // (1) < �̷��� �ϸ� forwardig �� �ƴ�. 
	PAIR( A&& a, B&& b) :	first(std::forward<A>(a)), 
													second(std::forward<B>(b)){ // (3) �ʱ�ȭ ����Ʈ�� �и�
		//first = std::forward<A>(a);
		//second = std::forward<B>( b);
	}

	T& getValue1() { return first; }
	U& getValue2() { return second; }
};

int main() {
	PAIR<int, int> p(4, 5);

	PAIR<Empty, int > p2;
	cout << sizeof(p2) << endl; // 8 ����. empty �̴� 4�� ������ �ƴѰ�? 
}