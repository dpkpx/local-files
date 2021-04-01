#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(int argc, char const *argv[])
{   
    int x =15;

    for (int i = 1; i <= x; i++)
    {
       for (int j = 1; j <= i; j++)
       {
           printf(" * ");
       }
       for (int k = 1; k <=(2*x-1)-(2*i); k++)
       {
           printf("   ");
       }
       for (int l = 1; l <= i; l++)
       {    if (l==x)
            break;
           printf(" * ");
       }
       printf("\n");
       
        
    }

     for (int i = 1; i <= x; i++)
    {   if(i==1)
        continue;
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
            
            printf(" * ");
        }
        
        
        



        printf("\n");
    }


    return 0;
}
