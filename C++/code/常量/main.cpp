// 在c++中，有两种简单定义常量的方式：
// 1, 使用#define预处理器
// 2, 使用const关键字

// define预处理器

#include <iostream>

using namespace std;

#define LENGTH 10
#define WIDTH 5
#define NEWLINE '\n'

int main()
{
    int area;

    area = LENGTH * WIDTH;
    cout << area;
    cout << NEWLINE;
    return 0;
}