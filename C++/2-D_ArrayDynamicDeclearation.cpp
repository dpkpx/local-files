//Demo of 2-D Array's Dynamic Declearation
#include <iostream>
#include <conio.h>
using std::cin;
using std::cout;
using std::endl;

int main(void)
{

    int r, c, row, col, **ptr;
    system("cls");
    cout << "How many Rows : ";
    cin >> row;
    ptr = new int*[row];
    cout << "How many Columns : ";
    cin >> col;
    for (r = 0; r < row; r++)
        ptr[r] = new int[col];
    system("cls");
    for (r = 0; r < row; r++)
        for (c = 0; c < col; c++)
        {
            cout << "Enter value of PTR[" << r << "][" << c << "] : ";
            cin >> ptr[r][c];
        }
    system("cls");
    cout << "Given Matrix : " << endl;
    for (r = 0; r < row; r++)
    {
        for (c = 0; c < col; c++)
        {
            cout << ptr[r][c] << "\t";
        }
        cout << endl;
    }
    return 0;
}