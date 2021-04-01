#include <iostream>

using namespace std;

class Line
{
public:
    int getLength(void);
    Line(int len);         //简单构造函数
    Line(const Line &obj); //拷贝构造函数
    ~Line();               //析构函数

private:
    int *ptr;
};

//成员函数定义，包括构造函数
Line::Line(int len)
{
    cout << "Call constructor" << endl;
    // 为指针分配内存
    ptr = new int;
    *ptr = len;
}

Line::Line(const Line &obj)
{
    cout << "Call copy constructor" << endl;
    ptr = new int;
    *ptr = *obj.ptr; //拷贝值
}

Line::~Line(void)
{
    cout << "Release memory" << endl;
    delete ptr;
}

int Line::getLength(void)
{
    return *ptr;
}

void display(Line obj)
{
    cout << "line is:" << obj.getLength() << endl;
}

int main()
{
    Line line(10);
    display(line);
    return 0;
}
