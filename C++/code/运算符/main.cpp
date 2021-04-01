/*
位运算符作用于位，并逐位进行操作
&: 按位进行与操作
|:按位记性或操作
^:按位进行异或操作
~:按位进行取反操作
<<:二进制左移运算符，比如A=60，即0011 1100，A<<2执行的结果为1111 0000
>>:二进制右移运算符
*/

#include <iostream>

using namespace std;

int main()
{
    int a = 60, b = 13;
    int c = 0;
    cout << "Bingo ." << endl;

    c = a & b;
    cout << "The result of & is:" << c << endl;

    c = a | b;
    cout << "The result of | is:" << c << endl;

    c = a ^ b;
    cout << "The result of ^ is:" << c << endl;

    c = ~a;
    cout << "The result of ~ is:" << c << endl;

    c = a << 2;
    cout << "The result of << is:" << c << endl;

    c = a >> 2;
    cout << "The result of >> is:" << c << endl;

    return 0;
}