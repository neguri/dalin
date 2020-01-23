#define USING_GUI
#include <iostream>
#include <string>
#include "cppmaster.h"

#include <map>

using namespace std;
using namespace cppmaster;

class Window;

map<int, Window*> this_map; 
// �Ǵ� �ڵ� ���̶�� �θ�
// ��κ��� GUI ���̺귯���� �� ������ ����

class Window {
	int handle;
public:
	void Create(string title) {
		handle = ec_make_window(&handler, title);
		this_map[handle] = this;
	}
	// static���� this�� ��� this�� �����ϴ� �ڷ� ������ �ʿ���
	static int handler(int hwnd, int msg, int a, int b) {
		Window* self = this_map[hwnd];
		switch (msg) {
		case WM_LBUTTONDOWN:     self->OnLButtonDown(); 	break;
		case WM_KEYDOWN:					self->OnKeyDown(); break;
		}
		return 0;
	}

	virtual void OnLButtonDown() {}
	virtual void OnKeyDown() { }
};

class Frame : public Window {
public:
	virtual void OnLButtonDown() { cout << "Frame Button" << endl; }
	virtual void OnKeyDown() { cout << "Frame Key" << endl; }
};

int main()
{
	Frame f;
	f.Create("A");
	ec_process_message();
}