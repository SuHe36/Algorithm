/*
引用调用
向函数传递参数的引用调用方法，把引用的地址复制给形式参数。
在函数内，该引用用于访问调用中要用到的实际参数。这意味着，修改形式参数会影响到实际参数。
按引用传递值，参数引用被传递给函数，就像传递其他值给函数一样。
因此相应的，在下面的函数swap()中，您需要声明函数参数为引用类型。

*/

#include <iostream>

using namespace std;

void swap(int &x, int &y);

int main()
{
    int a = 100, b = 200;

    cout << "Before the swap, the value of a is:" << a << endl;
    cout << "Before the swap, the value of b is:" << b << endl;
    cout << "&a is:" << &a << endl;
    swap(a, b);

    cout << "After the swap, the value of a is:" << a << endl;
    cout << "After the swap, the value of b is:" << b << endl;
    return 0;
}

void swap(int &x, int &y)
{
    cout << "x is:" << x << endl;
    int temp;

    temp = x;
    x = y;
    y = temp;

    return;
}
