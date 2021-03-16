#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main(int argc, char const *argv[])
{
    int x,c,f;

    f=0;


    printf("enter  no : ");
    scanf("%d",&x);
    
   
   if (x==2)
    {
    
        printf("%d is not a Prime Number",x);
    }
    else
    {
   
    
    
    
    for ( c = 2; c <= x; c++)
    {
    
    if (x%c==0)
    {
       f+=1;
        
    }

    }
    if (f==1)
    {
        printf("%d : is a Prime Number",x);
    }
    else 
    {
        printf("%d is not a prime Number",x);
    }
    
    }
    
    getch();
    system("cls");
    
    return 0;
}
