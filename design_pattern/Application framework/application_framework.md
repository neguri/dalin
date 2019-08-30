�������α׷��� �帧�� �̸� ���� �Ѱ�  

1. CWinApp���� �Ļ��� Ŭ������ �����ϰ�
2. Init(), Exit(), Run()���� �����Լ��� �����ϸ�, �� �ܰ迡�� �� ���� ����
3. ���������� ����ڰ� ���� ��ü�� ���������� �Ѱ� ����

application framework�� �⺻���� ������

``` cpp
class CWinApp;

CWinApp* g_app = nullptr;

class CWinApp {
public:
    CWinApp() {g_app = this;}
    virtual bool Init(){ return false;}
    virtual int Exit() {return false;}
    virtual int Run()  {return false;}
};

int main()
{
    if(g_app->Init() == true) {
        g_app->Run();
    }

    g_app->Exit();
    cout<<"main"<<endl;
    return 0;
}


class MyApp : public CWinApp {
public:
    virtual bool Init() {
        cout<<"init"<<endl;
        return true;
    }

    virtual int Exit() {
        cout<<"finished"<<endl;
        return false;
    }

    virtual int Run()  {return false;}
};

MyApp theApp;
```

