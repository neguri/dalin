#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono;

// ��� ���� �� �ڱ� �̸� ������ ��. CRTP
class ConnectDB :  public enable_shared_from_this<ConnectDB> {

	// �����带 ����ϴ� Ŭ������ �ִٸ�
	// �ڽ��� ������ �������� ����� �� ���� �����ؾ� �Ѵ�
	// �ڽ��� ����Ű�� ����Ʈ �����Ͱ� �־�� �Ѵ�.
	shared_ptr<ConnectDB> holdMe;

public:
	// ������ 1. this�� raw pointer�̹Ƿ� ���� ��ü�� ���� ������
	// ������ 2.�����ڿ����� �����尡 �����Ǳ� ���̴�. ���� ����� ������ �ʿ� ����.
	/*
	ConnectDB() : holdMe(this) {
	}
	*/

	void start() {
		// holdMe = this; // error. 

		holdMe = shared_from_this(); // �ܺο��� ������� ���� ��ü�� �����ϰ� ���ش�.

		thread t(&ConnectDB::Main, this);
		t.detach();
	}

	virtual void Main() {
		
		// (2) �׷��� �̷��� ��.
		shared_ptr<ConnectDB> sp(holdMe);
		holdMe.reset();

		this_thread::sleep_for(3s);
		cout << "DB����" << endl;
		// ��� ����Ÿ �����


		 holdMe.reset();  // << �̰� �����ϰ� �׽�Ʈ�غ��� ���̸� Ȯ�� ����
				// (1) �̷��� �ϸ� ���ʿ��� ���� �߻��� �������. 
	}
	~ConnectDB() {
		cout << "�ı�" << endl;
	}
};

int main()
{
	{
		shared_ptr<ConnectDB> p(new ConnectDB);
		p->start();
		// (1) ���� ���������� ���ŵ�. ���߿� ���� �߻�
	}
	
	getchar();
}

/*
https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/include/utils/Thread.h
	
	volatile bool           mRunning;
			sp<Thread>      mHoldSelf;

https://github.com/aosp-mirror/platform_system_core/blob/master/libutils/Threads.cpp

int Thread::_threadLoop(void* user)
{
	Thread* const self = static_cast<Thread*>(user);

	sp<Thread> strong(self->mHoldSelf);
	wp<Thread> weak(strong);
	self->mHoldSelf.clear()

*/