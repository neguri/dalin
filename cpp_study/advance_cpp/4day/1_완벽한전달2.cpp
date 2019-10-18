#include <iostream>
#include <vector>

using namespace std;

class Data {};
class Test {
	Data data;
public:
	// setter �����
	void SetData(const Data& d) { data = d; }

	// (2) . 1�� ������ ���ؼ� move�� ���� setter�߰�
	//void SetData(Data&& d) { data = move(d); }

	// ==> move ������ �����ϱ� ���� �Լ��� �ΰ��� ������ ��

	// �׷���, �ߺ����� �ڵ� �ۼ��� ���� �ʱ� ����  forwarding reference �� ���
	// T&&	: Data& �� Data&&�� �Լ��� �ڵ� ���� (int�� ���޵ȴٸ�)
	template<typename T > void SetData(T&& d) {
	
		// �׷��ٸ� � ǥ���� �´� ���ΰ�?
		data = d;						// �̷��� �ϸ� �׻� ���縸 ��.
		
		// �̷��� �ϸ� �׻� move (�� ��ü�� const�� �ƴϰ� move �����ڰ� ������)
		data = std::move(d); 
		
		// forward�� main���� rvalue�� ������ rvalue��, lvalue�� ������ lvalue�� ĳ����
		// ����� forward< > �� �������.
		data = std::forward<T>(d);
	}
};

int main()
{
	Data d;
	Test t;
	t.SetData(d);
	t.SetData(move(d));  // (1) move ���� �ϰ� �ʹ�. 
}