#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf(" %d ", i);
        }
        for (int k = 1; k <= 9 - i * 2; k++)
        {
            printf("   ");
        }
        for (int l = 1; l <= i; l++)
        {
            if (l == 5)
            {
              break;
            } 
             else
                    {
                        printf(" %d ", i);
                    }
        }
        printf("\n");
    }

    return 0;
}
