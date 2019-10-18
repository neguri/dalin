#include <iostream>
#include <string>
#include <vector>

using namespace std;

class People {
	string		name;
	int			age;
	char*		addr;
public:
	People(string n, int a, const char* ad) : name(n), age(a) {
		addr = new char[strlen(ad) + 1];
		strcpy(addr, ad);
	}
	~People() {
		delete[] addr;
	}

	People(const People& p) :name(p.name), age(p.age) {
		cout << "copy ctor " << endl;
		addr = new char[strlen(p.addr) + 1];
		strcpy(addr, p.addr);
	}

	People& operator=(const People& p) {
		cout << "copy = " << endl;
		if (&p == this) return *this;
		name = p.name;
		age = p.age;

		delete[] addr;
		addr = new char[strlen(p.addr) + 1];
		strcpy(addr, p.addr);
		return *this;
	}

	// move ������
	// �߿� !!!: ��� ����� ���ؼ� move�� �Űܾ� ��
	// (1) ���ܰ� �߻����� �ʰ� ������ ��
	// (2)  ���⼭ noexcept �� �ٿ��� ��. �׷��� ������ resize( )���� ���縸 ��
	
	
	// People(People&& p) noexcept  (3) �Ʒ�ó�� �ٲ� �� ����. 
	// std::string ���� ���ܰ� ������ ��� �ϳ�?
	
	//People(People&& p)  // (4) �̷��� �����, resize( ) �Ҷ� ���� �����ڸ� �θ��� ��
	People(People&& p) noexcept (is_nothrow_constructible<string>::value) // (5) �̰� ������ resize �� �� �� �̵� �����ڸ� �θ�
		
		:name(std::move(p.name)), age(p.age), addr(p.addr) {
		cout << "move ctor " << endl;
		p.addr = nullptr;
		p.age = 0;
	}

	People& operator=(People&& p) noexcept {
		cout << "move = " << endl;

		// ǥ�ؿ� �Ʒ��� ���ǵǾ� ���� �ʴ�. .
		// �ڱ� �ڽſ��� �̵��ϴ� ���� ������
		// if (&p == this) return *this;
		 
		name = p.name;
		age = p.age;

		delete[] addr;
		addr = std::move(p.addr);
		p.addr = nullptr;
		p.age = 0;
		return *this;
	}
};

int main()
{

	People p("kim", 5, "seoul");

	People p1 = p; // ������ ���� ������
	People p2 = move(p); // ������ move ������

	// ���ܰ� ���� ���� move �����ڸ� �θ�. , ���ܰ� ������ ��������ڸ� �θ��� �Ǹ�,
	// move �����ڿ� noexcept Ű���尡 �ִ��� Ȯ���ؾ� ��.
	// ���� std::vector< > ���� �Ϳ� ��ü ���� �� �ش� ��ü�� move �����ڿ� noexcept�� ���� ������ ȿ���� ����.
	People p3 = move_if_noexcept(p2);
	 
	// move_if_noexcept �� ����
	People p4 = is_nothrow_move_constructible<People>::value ? move(p3) : p3;
	
	cout << "------------" << endl;

	// default �����ڰ� �����Ƿ� �ӽ� ��ü�� �Ѱܾ� ��.
	vector<People> v(3, People("kim", 5, "Seoul"));
	cout << "--------------" << endl;
	v.resize(5, People("kim", 5, "Seoul"));
	cout << "--------------" << endl;
}
