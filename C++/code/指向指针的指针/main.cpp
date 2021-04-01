/*
指向指针的指针是一种多级简介寻址方式，或者说是一个指针链
指针的指针就是将指针的地址存放在另一个指针里面。
通常，一个指针包含一个变量的地址。当我们定义了一个指向指针的指针时，第一个指针包含了第二个指针的地址，
第二个指针指向包含实际值的位置。

一个指向指针的指针变量必须如下声明，即在变量名前放两个星号。例如，下面声明了一个指向int类型指针的指针。
int **var;

当一个目标值被一个指针间接指向另一个指针时，访问这个值需要使用两个星号运算符，如下面实例所示：
*/

#include <iostream>

using namespace std;

int main()
{
    int var;
    int *ptr;
    int **pptr;

    var = 3000;
    ptr = &var;
    pptr = &ptr;

    cout << "var value is:" << var << endl;
    cout << "*ptr value is:" << *ptr << endl;
    cout << "**pptr value is:" << **pptr << endl;

    return 0;
}
