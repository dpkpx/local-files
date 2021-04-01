#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(int argc, char const *argv[])
{
    int n=5;
    for ( n ; n > 0; n--)
    {
        for (int z = 5 ; z > 5-n ;z--)
        {
            printf("%d",z);
           

        }
         printf("\n");
        
    }
    for (int i = 3; i > -1; i--)
    {
        for (int y = 5 ; y > i; y--)
        {
           printf("%d",y);

        }
        printf("\n");

    }
    
    




    return 0;
}
