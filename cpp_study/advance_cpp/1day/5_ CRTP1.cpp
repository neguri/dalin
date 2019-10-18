#include <iostream>

using namespace std;
/*
template<typename T> 
class Window {
public:
	void msgLoop() {			// void msgLoop(Window* this)
		// �̺�Ʈ �߻��� ����ϴٰ� Ư�� ��� �Լ� ȣ��
		LButtonDown();
		// (2) �̷��� ���� ����
		//static_cast<MyWindow*> (this)->LButtonDown();
		static_cast<T*> (this)->LButtonDown();
	}
	// void LButtonDown() { cout << "Window LButton" << endl; }  virtual �̶��� ������ Ÿ���� ���� ����, table�� ����
	// (1)�׷��� ���� �Լ� ������尡 ������ virtual �� ������ ��.
	 void LButtonDown() { cout << "Window LButton" << endl; }
};

// (3) CRTP �������� ����.  ���� �Լ��� ����� �� ���� �ӵ��� ����.
class MyWindow : public Window <MyWindow>{
//class MyWindow : public Window {
public:
	void LButtonDown() {
		cout << "MyWindow LButton" << endl;
	}
};

int main()
{
	MyWindow w;
	w.msgLoop();  // (msgLoop(&w))
	return 0;
}

*/

// T �� ������� �ʴ� ��� �Լ��� ��� Ŭ������ �Űܾ� ��. (thin template, template hoisting)

class Window {
	int handle;
public:
	void moveWindow() {
		LButtonDown();
	}
};

template<typename T>
class MsgWindow : public Window{
public:
	void msgLoop() {
		LButtonDown();
	}
	void LButtonDown() {
			static_cast<T*> (this)->LButtonDown();
	}
};

class MyWindow : public MsgWindow <MyWindow>{
//class MyWindow : public Window {
public:
	void LButtonDown() {
		cout << "MyWindow LButton" << endl;
	}
};

int main()
{
	MyWindow w;
	w.msgLoop();  // (msgLoop(&w))
	return 0;
}
