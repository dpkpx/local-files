#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(int argc, char const *argv[])
{   int x=7;
    for (int i = 1; i <=x; i++)
    {
        for (int j = 1; j <=i; j++)
        {
            printf(" * ");
        }
        for (int k = 1; k <= (x*2-1)-(2*i); k++)
        {
            printf("   ");
        }
        for (int l = 1; l <=i; l++)
        {  if (l==x)
                break;
            printf(" * ");
        }
        printf("\n");

    }
    
    
    return 0;
}
