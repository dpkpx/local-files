#include <iostream>
#include <conio.h>
using std::cin;
using std::cout;
using std::endl;
int main()
{

    int x = 9;
    int &y = x;
    cout << x << endl;
    cout << y;
}