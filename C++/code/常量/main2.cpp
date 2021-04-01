/*
使用const关键字进行修饰
const修饰指针时，有三种情况：
--1, const修饰指针指向的内容，即内容不可变量; 如: const int *p=8;【此时const位于*号的左边】
--2, const修饰指针，即指针为不可变量，但是指针修饰的内容可以改变；如:
    int a=8;
    int* const p = &a;
    *p = 9;//正确
    int b=7;
    p = &b;//错误
    对于const修饰指针，即指针的内存地址不可以改变，但是它修饰的内容可以改变，此时const位于*号的右边；
--3, const修饰指针和指针指向的内容，也就是指针和指针指向的内容都为不可变量；此时为1，2两种情况的合并；
    int a=8;
    const int* const p = &a;
*/
#include <iostream>

using namespace std;
int main()
{
    const int LENGTH = 19;
    const int WIDTH = 5;
    const char NEWLINE = '\n';
    int area;

    area = LENGTH * WIDTH;
    cout << area;
    cout << NEWLINE;
    return 0;
}
