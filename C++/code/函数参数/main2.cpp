/*
指针调用的例子。
向函数传递参数的指针调用方法，把参数的地址复制给形式参数。
在函数内，改地址用于访问调用中要用到的实际参数。这意味着，修改形式参数会影响实际参数。

按指针传递值，参数指针被传递给函数，就向传递其他值给函数一样。
因此相应的，在下面的函数swap中，需要声明函数参数为指针类型，该函数用于交换参数所指向的两个整数变量的值。


*/
#include <iostream>

using namespace std;

void swap(int *x, int *y);

int main()
{
    //局部变量声明
    int a = 100, b = 200;
    cout << "Before the swap, the value of a is:" << a << endl;
    cout << "Before the swap, the value of b is:" << b << endl;

    swap(&a, &b);

    cout << "After the swap, the value of a is:" << a << endl;
    cout << "After the swap, the value of b is:" << b << endl;
    return 0;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    return;
}
