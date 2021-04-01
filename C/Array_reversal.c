#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int ArrayRev(int arr[],int size)
{
    int s = size;
    
    int c = s / 2;
    for (int j = 0; j < s; j++)
    {
        printf("%d, ", arr[j]);
    }
    int i = 0;
    printf("\nArray In Revrse %d\n",s);

    for (int i = 0; i < c; i++)
    {
        int x = arr[i];
        arr[i] = arr[s - 1 - i];
        arr[s - 1 - i] = x;
    }

    for (int j = 0; j < s; j++)
    {
        printf("%d, ", arr[j]);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {23, 2, 5, 7, 22};

    ArrayRev(arr,5);

    return 0;
}
