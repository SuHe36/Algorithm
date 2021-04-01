/*
一个指向c++类的指针与指向结构的指针类似，访问指向类的指针的成员，
需要使用成员访问运算符->,就像访问指向结构的指针一样。
与所有的指针一样，您必须在使用指针之前，对指针进行初始化。
*/

#include <iostream>
using namespace std;

class Box
{
private:
    double length;
    double breadth;
    double height;

public:
    //构造函数定义
    Box(double l = 2.0, double b = 2.0, double h = 2.0)
    {
        cout << "Construct called." << endl;
        length = l;
        breadth = b;
        height = h;
    }
    double Volume()
    {
        return length * breadth * height;
    }
};

int main()
{
    Box box1(3.3, 1.2, 1.5);
    Box box2(8.5, 6.0, 2.0);

    Box *ptrBox;
    //保存第一个对象的地址
    ptrBox = &box1;

    //现在尝试使用成员访问运算符来访问成员
    cout << "Volume of Box1:" << ptrBox->Volume() << endl;

    //保存第二个对象的地址
    ptrBox = &box2;

    //现在尝试使用成员访问运算符来访问成员
    cout << "Volume of Box2:" << ptrBox->Volume() << endl;

    return 0;
}
