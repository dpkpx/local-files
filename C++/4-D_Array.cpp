//Test template
#include <iostream>
#include <conio.h>
using std::cin;
using std::cout;
using std::endl;

int main(void)
{
    int f = 0;
    int ****ptr;
    ptr = new int ***[3];
    for (int i = 0; i < 3; i++)
    {
        ptr[i] = new int **[3];
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ptr[i][j] = new int *[3];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                ptr[i][j][k] = new int[3];
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    ptr[i][j][k][l] = i*27+j*9+k*3+l;
                    ++f;
                }
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    cout << ptr[i][j][k][l] << " ";
                }
                cout << endl;
            }
            cout << endl;
            cout << endl;
        }
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
    }
}
