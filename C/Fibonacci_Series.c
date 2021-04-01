#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{

   int a, b, c, j;
   a = 0;
   b = 1;
   printf("Up To How Many Numbers ? :");
   scanf("%d", &j);
   for (int i = 0; i < j; i++)
   {

      c = a + b;
     printf("%d, ", b);
      a = b;
      b = c;
   }
   printf("value is %d",a);

   return 0;
}
