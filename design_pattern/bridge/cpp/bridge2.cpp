
#include <iostream>

using namespace std;


struct IMP3 {
    virtual void Play()  = 0;
    virtual void Stop() = 0;
    virtual ~IMP3(){}
};

class IPod :public IMP3 {
public:
    void Play(){ cout<<"play ipod"<<endl;}
    void Stop(){ cout<<"stop ipod"<<endl;}
};

void Sleep(int i) {
    cout<<"sleep"<<endl;
}

class MP3 {

    IMP3* pImpl;
public:
    MP3(){
        pImpl = new IPod;
    }
    void Play() { pImpl->Play();}
    void Stop() { pImpl->Stop();}
    void PlayOneMinute() { pImpl->Play(); Sleep(1); pImpl->Stop();}
};

class People {
public:
    void UseMP3(MP3* p) {
        p->Play();
        p->PlayOneMinute();
    }
};

int main()
{


}

