#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(int argc, char const *argv[])
{
    int y,s,x;
    

    printf("Enter a number to check :");
    scanf("%d",&x);

    
    while (x>0)
    {
      s= printf( "%d",x%10);
        x=x/10;
    }
    
    



    
    return 0;

    
}
