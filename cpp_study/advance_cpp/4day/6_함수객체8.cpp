#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
	sort(x, x + 10);  // ������ ���� ����

	// ����å ���� 1. �Ϲ� �Լ� ��� - �� ��å�� ġȯ �ȵ� . ����
	// sort(x, x+10, cmp1);
	
	// 2. �Լ� ��ü ���
	greater <int> f;
	sort(x, x + 10, f);

	// ��ü() : () ������ ȣ��
	// Ÿ��() : �ӽ� ��ü ����
	sort(x, x + 10, greater<int>());  // f�� ����� �� ���� �ӽ� ��ü �����ϴ� ���� ����

	// 3. C++11 ���ʹ� ���� ǥ������ ���
	// [] : lambda introducer : ���� ǥ������ ���۵��� �˷���. �� �޺κ��� �׳� �Լ��� ���ָ� ��
	sort(x, x + 10, [](int a, int b) { return a < b; });

	// �� �ڵ�(����)�� �ۼ��ϸ� �����Ϸ��� �Ʒ� �ڵ带 ����
	class ClosureType {
	public:
		inline bool operator()(int a, int b)  const { 
			return a < b;
		}
	};
	sort(x, x + 10, ClosureType());
	// ������� ������.

	for (int a : x) {
		cout << a << ' ';
	}
}
