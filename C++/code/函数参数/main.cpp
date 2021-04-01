// 传值调用的例子

#include <iostream>
using namespace std;

// void swap(int x, int y);

int main()
{
    //局部变量声明
    int a = 100, b = 200;
    cout << "Before the swap, the value of a is:" << a << endl;
    cout << "Before the swap, the value of b is:" << b << endl;

    //调用函数来交换值
    swap(a, b);

    cout << "After the swap, the value of a is:" << a << endl;
    cout << "After the swap, the value of b is:" << b << endl;

    return 0;
}

void swap(int x, int y)
{
    int temp;

    temp = x;
    x = y;
    y = temp;
    return;
}
