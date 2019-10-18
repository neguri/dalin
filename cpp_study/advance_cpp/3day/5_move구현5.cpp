#include <iostream>
#include <string>


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
		cout << "People copy ctor " << endl;
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

	People(People&& p) noexcept (is_nothrow_constructible<string>::value)
				:name(std::move(p.name)), age(p.age), addr(p.addr) {
		cout << "people move ctor " << endl;
		p.addr = nullptr;
		p.age = 0;
	}

	People& operator=(People&& p) noexcept {
		cout << "move = " << endl;
		name = p.name;
		age = p.age;

		delete[] addr;
		addr = std::move(p.addr);
		p.addr = nullptr;
		p.age = 0;
		return *this;
	}
};

// ��Ģ 1. ���� �迭�� move �迭�� ��� �������� ������
//				�����Ϸ��� ��� ������ ������ ������ �ش�.				


class Home {
	People p;
public:
	Home() : p("kim", 10, "seoul") {}

	Home(const Home& h) : p(h.p) {
		cout << "Home copy constructor" << endl;
	}


	// (3) ����Ʈ move �����ڸ� ����� �޶�� �����Ϸ����� �˷���
	// �׷��� ������, �����Ϸ��� ���� �����ڸ� ����ڰ� ���������, move �����ڵ�
	// ���� ���� �����ؼ� �����Ϸ��� ����� ���� �ʴ´�.
	// �׷��� �Ʒ� ������ ������ Home h3 = move(h1); ���꿡 ���� ���� �����ڰ� �Ҹ��� �ȴ�.
	Home(Home&&) = default;

};

int main()
{
	Home h1;
	Home h2 = h1;
	Home h3 = move(h1);  // (1) �����Ϸ��� move �����ڸ� ����� ��
}
