#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(int argc, char const *argv[])
{
    int x = 7;

    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= x+1-i; j++)
        {
            printf(" * ");
        }
        for (int k = 1; k < 2*i-2; k++)
        {
            printf("   ");
        }
        for (int l = 1; l <= x+1-i; l++)
        {   
            if(l==x)
            break;
            printf(" * ");
        }
        
        
        



        printf("\n");
    }





    return 0;
}