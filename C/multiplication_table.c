#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n, t;
    printf(" Enter Number : ");
    scanf("%d", &n);

    for ( size_t i = 1; i < 11; i++)
    {
        t = i * n;
        /*  printf("%d",n);
        printf(" x %d",i);
        printf(" = %d \n",t);
         */
       printf("%d * %d = %d \n", n, i, t);
    }

    getch();
    system("cls");
    return 0;

    
}
