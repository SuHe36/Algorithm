/*
引用变量是一个别名，也就是说，他是某个因存在变量的另一个名字。
一旦把引用初始化为某个变量，就可以使用该引用名称或变量名称来指向变量。

引用 vs 指针的区别：
- 不存在空引用。引用必须连接到一块合法的内存
- 一旦引用被初始化为一个对象，就不能被指向另一个对象。指针可以在任何时候指向到另一个对象
- 引用必须在创建时被初始化。指针可以在任何时间被初始化。
*/

#include <iostream>
using namespace std;

int main()
{
    //声明简单的变量
    int i;
    double d;

    //声明引用变量
    int &r = i;
    double &s = d;

    i = 5;
    cout << "Value of i:" << i << endl;
    cout << "Value of i inference :" << r << endl;

    d = 11.7;
    cout << "Value of d:" << d << endl;
    cout << "Value of d reference:" << s << endl;

    return 0;
}
