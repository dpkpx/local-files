#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(int argc, char const *argv[])
{
    int x = 20;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf(" * ");
        }
        printf("\n");
    }
    for (int k = x; k <= 2 * x; k++)
    {
        for (int m = 1; m <= k; m++)
        {
            printf("   ");
        }

        for (int l = 1 ; l<=2*x-k; l++)
        {
            printf(" * ");
        }
        printf("\n");
    }

    return 0;
}
