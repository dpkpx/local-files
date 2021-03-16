//Demo of 1-D Array's Dynamic Declearation
#include <iostream>
#include <conio.h>
using std::cin;
using std::cout;
using std::endl;
void clrscr(){
    system("cls");
}

int main(void)
{
    int i, n;
    int *ptr;
    cout << "How Many Elements : ";
    cin >> n;
    ptr = new int[n];
    for(i=0;i<n;i++){
        cout<< "x["<<i+1<<"]?";
        cin>> ptr[i];
    }
    clrscr();
    for(i=0;i<n;i++)
    cout << ptr[i]<<"\t";
    cout << "\n Press any key to Exit..";

    return 0;
}
