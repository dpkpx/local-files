#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int x, y, z;
    printf("enter first no :");
    scanf("%d", &x);
    printf("enter second no :");
    scanf("%d", &y);
    printf("enter second no :");
    scanf("%d", &z);

    /*int d = (x>y)? (x>z)? x:z : (y>z)? y:z ;
     printf("largest no is %d",d);*/

    /*if (x>y)
        if (x>z)
        printf("largest no is : %d",x);
        else
        printf("largest no is : %d",z);
    else 
        if (y>z)
        printf("largest no is : %d",y);
        else
        printf("largest no is : %d",z);*/

    if (x > y && x > z)
    {
        printf("largest no is : %d", x);
    }
    else if (z > y && z > x)
    {
        printf("largest no is : %d", z);
    }
    else if (y > z && y > x)
    {
        printf("largest no is : %d", y);
    }
    else
    {
        printf("all are equal no");
    }

    getch();

    system("cls");

    return 0;
}
