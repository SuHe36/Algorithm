/*
数组名是指向数组中第一个元素的常量指针，因此，在下面的声明中：
double nums[10];
其中nums是一个指向 &nums[0]的指针，也就是数组nums的第一个元素的地址。
因此，下面的程序片段把p赋值为nums的第一个元素的地址：
double *p;
double nums[10];
p = nums;

使用数组名作为常量指针是合法的，反之亦然。因此*(nums+4)是一种访问nums[4]数据的合法方式。
一旦把第一个元素的地址存储在p中，那么我们就可以使用*p, *(p+1), *(p+2)等来访问数组元素。
*/

#include <iostream>

using namespace std;

int main()
{
    double nums[5] = {100.0, 2.0, 3.4, 17.0, 50.0};
    double *p;

    p = nums;

    //输出数组中每个元素的值
    cout << "使用指针的数组值" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "*(p+" << i << "):" << *(p + i) << endl;
    }

    cout << "使用nums作为地址的数组值" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "*(nums +" << i << "):" << *(nums + i) << endl;
    }

    return 0;
}
