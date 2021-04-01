/*
定义一个类，本质上是定义一个数据类型的蓝图，
他定义了类的名称是什么，类的对象包括什么，以及可以在这些对象上执行哪些操作。

类定义是以关键字class 开头，后跟类的名称。
类的主体是包含在一对花括号中的，类定义的后面必须跟着一个分号或一个声明列表。

如下使用关键字class定义Box数据类型，如下所示：
class Box{
    public:
        double length; //盒子的长度
        double breadth; //盒子的宽度
        double height; //盒子的高度
};

关键字public确定了类成员的访问属性。
在类对象作用域内，公共成员在类的外部是可以访问的。我们也可以指定类的成员为private或者protected。
需要注意的是私有成员和受保护的成员是不能通过.来访问的。
*/

#include <iostream>

using namespace std;

class Box
{
public:
    double length;  //长度
    double breadth; //宽度
    double height;  //高度
    // 成员函数声明
    double get();
    void set(double len, double bre, double hei);
};

//成员函数定义
double Box::get(void)
{
    return length * breadth * height;
}

void Box::set(double len, double bre, double hei)
{
    length = len;
    breadth = bre;
    height = hei;
}

int main()
{
    Box box1; // 声明box1，类型为Box
    Box box2; //声明box2，类型为Box
    Box box3; //声明box3，类型为Box
    double vol = 0.0;

    // box1详述
    box1.length = 6.0;
    box1.height = 5.0;
    box1.breadth = 7.0;

    // box2详述
    box2.length = 12.0;
    box2.height = 10.0;
    box2.breadth = 13.0;

    // box1的体积
    vol = box1.height * box1.length * box1.breadth;
    cout << "The volume of box1 is:" << vol << endl;

    // box2的体积
    vol = box2.height * box2.length * box2.breadth;
    cout << "The volume of box2 is:" << vol << endl;

    // box3的详述
    box3.set(16.0, 8.0, 12.0);
    vol = box3.get();
    cout << "The volume of box3 is:" << vol << endl;
    return 0;
}
