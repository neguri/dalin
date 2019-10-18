
#include <iostream>
#include <type_traits>

using namespace std;

class Empty {};

// �Ʒ� �ڵ尡 boost library �� �ִ� compressed pair ���̺귯��

template<typename T, typename U, bool b = is_empty_v<T>>
struct PAIR;
//{
 // ������� ������ �ȸ���� �ȵ�. ������� �����Ƿ� {} ��� ����
//};

// ���ǿ� ���� PAIR�� �κ� Ư��ȭ�Ѵ�.
template<typename T, typename U> struct PAIR <T, U, false>{
	T first;
	U second;
	PAIR() = default;
	template<typename A, typename B>
	PAIR(A&& a, B&& b) : first(std::forward<A>(a)),
		second(std::forward<B>(b)) {
	}
	T& getValue1() { return first; }
	U& getValue2() { return second; }
};


template<typename T, typename U> struct PAIR <T, U, true> : public T {
	U second;
	PAIR() = default;
	template<typename A, typename B>
	PAIR(A&& a, B&& b) : T(std::forward<A>(a)),
		second(std::forward<B>(b)) {
	}
	T& getValue1() { return *this; }
	U& getValue2() { return second; }
};

int main() {
	PAIR<Empty, int > p2;
	cout << sizeof(p2) << endl;
	PAIR<int, int > p3;
	cout << sizeof(p3) << endl;
}