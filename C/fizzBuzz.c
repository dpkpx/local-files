#include <stdio.h>
#include <stdbool.h>
int main(int argc, char const *argv[])
{
    for (int i = 1; i <= 100; i++)
    {
       bool mod3 =false ;
       bool mod5 =false;
        if(i%3==0){
            mod3=true;
        }
        if(i%5==0){
            mod5=true;
        }

        if (mod3&&mod5)
        {
            printf("%d - FizzBuzz\n",i);
        }else if(mod3){
            printf("%d - Fizz\n",i);
        }else if(mod5){
            printf("%d - Buzz\n",i);
        }else
        {
            printf("%d\n",i);
        }
        

        
    }

    return 0;
}
