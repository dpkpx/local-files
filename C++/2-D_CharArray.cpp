//demo of 2-D char Array 
#include <iostream>
#include <conio.h>
#include <string.h>
// using namespace std;
using std::cout;
using std::cin;
using std::endl;

void clrscr()
{
    system("cls");
}

int main(void)
{
    int i, j, n;
    char name[99][99];
    clrscr();
    cout << "how many names : ";
    cin >> n;
    for (i = 0; i < n; ++i)
    {
        cout << "Enter Names : ";
        cin >> name[i];
    }
    clrscr();
    cout << "Given Names : " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < strlen(name[i]); j++)
        {

            cout << name[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}