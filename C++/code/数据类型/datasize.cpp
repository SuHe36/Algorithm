#include <iostream>
#include <limits>

using namespace std;

int main()
{
    cout << "Type:"
         << "****size****" << endl;
    cout << "bool:"
         << "The number of byte is:" << sizeof(bool);
    cout << "The max value is:" << numeric_limits<bool>::max();
    cout << "The min value is:" << numeric_limits<bool>::min() << endl;

    cout << "char:The number of byte is:" << sizeof(char);
    cout << "The max value is:" << numeric_limits<char>::max();
    cout << "The min value is:" << numeric_limits<char>::min() << endl;

    cout << "short int: The number of byte is:" << sizeof(short);
    cout << "The max value is:" << numeric_limits<short>::max();
    cout << "The min value is:" << numeric_limits<short>::min() << endl;

    cout << "int:The number of byte is:" << sizeof(int);
    cout << "The max value is:" << numeric_limits<int>::max();
    cout << "The min value is:" << numeric_limits<int>::min() << endl;

    cout << "float:The number of byte is:" << sizeof(float);
    cout << "The max value is:" << numeric_limits<float>::max();
    cout << "The min value is:" << numeric_limits<float>::min() << endl;

    cout << "double:The number of byte is:" << sizeof(double);
    cout << "The max value is:" << numeric_limits<double>::max();
    cout << "The min value is:" << numeric_limits<double>::min() << endl;

    cout << "long:The number of byte is:" << sizeof(long);
    cout << "The max value is:" << numeric_limits<long>::max();
    cout << "The min value is:" << numeric_limits<long>::min() << endl;
}