
数据封装是面向对象编程的一个重要特点，它防止函数直接访问类类型的内部成员。
类成员的访问限制是通过在类主体内部对各个区域标记public, private, protected来指定的。
关键字public, private, protected称为访问修饰符。

一个类可以有多个public, protected或者private标记的区域。
每个标记区域在下一个标记区域开始之前或者在遇到类主体结束右括号之前都是有效的。
成员和类的默认访问修饰符是private。

# 共有成员(Public)
公有成员在程序中类的外部是可以访问的。我们可以不使用任何成员函数来设置和获取共有变量的值
```
#include<iostream>
using namespace std;

class Line{
    public:
        double length;
        void setLength(double len);
        double getLength(void);
};

//成员函数定义
double Line::getLength(void){
    return length;
}

void Line:setLength(double len){
    length = len;
}
//程序的主函数
int main(){
    Line line;

    //设置长度
    line.setLength(6.0);
    cout << "Length of line is:" << line.getLength() << endl;

    //不使用成员函数设置长度
    line.length = 10.0; //ok, 因为length是公有的
    cout << "Length of line is:" << line.length << endl;
    return 0;

}

```

# 私有成员
私有成员变量或函数在类的外部是不可访问的，甚至是不可查看的。
只有类和友元函数可以访问私有成员。
默认情况下，类的私有成员都是私有的。**例如在下面的类中，width是一个私有成员，这意味着，如果我们没有使用任何访问修饰符，类的成员将被假定为私有成员。**



```
class Box{
    double width;
    public:
        double length;
        void setWidth(double wid);
        double getWidth(void);
};

```

但是在实际操作中，我们一般会在私有区域定义数据，在公有区域定义相关的函数，以便在类的外部也可以使用这些函数，如下所示：
```
#include<iostream>

using namespace std;

class Box{
    public:
        double length;
        void setWidth(double wid);
        double getWidth(void);

    private:
        double width;
};  

//成员函数定义
double Box::getWidth(void){
    return width;
}

void Box::setWidth(double wid){
    width = wid;
}

//程序的主函数
int main(){
    Box box;

    //不使用成员函数设置长度
    box.length = 10.0;//ok,因为length是共有的
    cout << "Length of box is:" << box.length << endl;

    //不使用成员函数设置宽度
    //box.width = 10.0; //Error: 因为width是私有的;
    box.setWidth(10.0); //使用成员函数设置宽度;
    cout << "Width of box:" << box.getWidth() << endl;
    return 0;
}

```

# protected成员
protected(受保护)成员变量或函数与私有成员十分相似，但有一点不同，protected成员在派生类（即子类）中是可以访问的。

我们可以看一下下面的实例，从父类Box派生了一个子类smallBox。
下面的实例与前面的实例类似，在这里width成员可被派生类smallBox的任何成员函数访问。

```
#include<iostream>
using namespace std;

class Box{
    protected:
        double width;
};

class SmallBox:Box{//SmallBox是派生类
    public:
        void setSmallWidth(double wid);
        double getSmallWidth(void);
};

//子类的成员函数
double SmallBox::getSmallWidth(void){
    return width;
}

void SmallBox::setSmallWidth(double wid){
    width = wid;
}

//程序的主函数
int main(){
    SmallBox box;

    //使用成员函数设置宽度
    box.setSmallWidth(5.0);
    cout << "Width of box:" << box.getSmallWidth() << endl;

    return 0;
}

```

# 继承中的特点
有public, protected, private三种继承方式，他们相应的改变了基类成员的访问属性：
- 1，public继承：基类public成员，protected成员，private成员的访问属性在派生类中分别变成了:public, protected, private
- 2, protected继承：基类public成员，protected成员，private成员的访问属性在派生类中分别变成了:protected, protected, private
- 3, private继承：基类public成员，protected成员，private成员的访问属性在派生类中分别变成了:private, private, private

但是无论哪种继承方式，下面的两点都没有改变：
- 1，private成员只能被本类成员（类内）和友元访问，不能被派生类访问；
- 2，protected成员可以被派生类访问


## public继承
```
#include<iostream>
#include<assert.h>

using namespace std;

class A{
    public:
    int a;
    A(){
        a1 = 1;
        a2 = 2;
        a3 = 3;
        a = 4;
    }
    void fun(){
        cout << a << endl; //正确
        cout << a1 << endl; //正确
        cout << a2 << endl; //正确
        cout << a3 << endl; //正确
    }
    public:
    int a1;
    protected:
    int a2;
    private:
    int a3;
};


class B: public A{
    public:
        int a;
        B(int i){
            A();
            a = i;
        }
        void fun(){
            cout << a << endl;  //正确， public成员
            cout << a1 << endl; //正确， 基类的public成员，在派生类中仍是public成员；
            cout << a2 << endl; //正确， 基类的protected成员，在派生类中是protected可以被派生类访问；
            cout << a3 << endl; //错误， 基类的private成员不能被派生类访问；
        }
};

int main(){
    B b(10);
    cout << b.a << endl;  // 正确
    cout << b.a1 << endl; //正确
    cout << b.a2 << endl; //错误，类外不能访问protected成员
    cout << b.a3 << endl; //错误，类外不能访问private成员
    return 0;
}

```

## protected继承
```
#include<iostream>

using namespace std;

class A{
    public:
    int a;
    A(){
        a1 = 1;
        a2 = 2;
        a3 = 3;
        a = 4;
    }
    void fun(){
        cout << a << endl;  //正确
        cout << a1 << endl; //正确
        cout << a2 << endl; //正确
        cout << a3 << endl; //正确
    }
    public:
        int a1;
    protected:
        int a2;
    private:
        int a3;
};

class B: protected A{
    public:
        int a;
        B(int i){
            A();
            a = i;
        }
        void fun(){
            cout << a << endl; //正确，public成员
            cout << a1 << endl; //正确，基类的public成员，在派生类中变成了protected，可以被派生类访问;
            cout << a2 << endl; //正确，基类的protected成员，在派生类中还是protected，可以被派生类访问；
            cout << a3 << endl; //错误， 基类的private成员不能被派生类访问；
        }
};

int main(){
    B b(10);
    cout << b.a << endl; //正确， public成员
    cout << b.a1 << endl; //错误，protected成员不能在类外访问
    cout << b.a2 << endl; //错误，protected成员不能在类外访问
    cout << b.a3 << endl; //错误，private成员不能在类外访问

    return 0;
}

```

## private 继承
```
#include<iostream>

using namespace std;

class A{
    public:
        int a;
        A(){
            a1 = 1;
            a2 = 2;
            a3 = 3;
            a = 4;
        }
        void fun(){
            cout << a << endl; //正确
            cout << a1 << endl; //正确
            cout << a2 << endl; //正确
            cout << a3 << endl; //正确
        }
        public:
            int a1;
        protected:
            int a2;
        private:
            int a3;
};

class B: private A{
    public:
        int a;
        B(int i){
            A();
            a = i;
        }
        void fun(){
            cout << a << endl; //正确， public成员
            cout << a1 << endl; //正确，基类public成员，在派生类中变成了private，可以被派生类访问
            cout << a2 << endl; //正确，基类的protected成员，在派生类中变成了private，可以被派生类访问；
            cout << a3 << endl; //错误，基类的private成员不能被派生类访问；
        }
};

int main(){
    B b(10);
    cout << b.a << endl; //正确， public成员
    cout << b.a1 << endl; //错误，private成员不能在类外访问
    cout << b.a2 << endl; //错误，private成员不能在类外访问
    cout << b.a3 << endl; //错误，private成员不能在类外访问
    return 0;
}

```
