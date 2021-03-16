#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main(void)
{
    int p,q,r;
    printf("enter first no : ");
    scanf("%d",&p);
    printf("enter second no : ");
    scanf("%d",&q);
    r = (p>q)? p:q;
    printf("\nlargest no is : %d",r);
    getch();
    system("cls");
    
}