#include <iostream>
#include <vector>

using namespace std;

class TextView {

    std::string data;
    std::string font;
    int         width;
public:
    TextView(string s, string fo="gulim", int w = 24) : data(s), font(fo), width(w) {}
    void Show(){cout<<data<<endl;}
};



class Shape {
public:
    virtual void Draw(){cout<<"Draw Shape"<<endl;}
};

class Rect : public Shape {
public:
    virtual void Draw(){cout<<"Draw Rect"<<endl;}
};

class Circle : public Shape {
public:
    virtual void Draw(){cout<<"Draw Circle"<<endl;}
};


class Text : public TextView, public Shape {
public:
    Text(string s) : TextView(s) {}
    virtual void Draw(){ TextView::Show();}
};

int main()
{

    vector<Shape*> v;

    v.push_back(new Rect);
    v.push_back(new Circle);
    v.push_back(new Text("hello"));
    for (auto p : v) {
        p->Draw();
    }


    return 0;
}
