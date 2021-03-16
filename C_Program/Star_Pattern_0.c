#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(int argc, char const *argv[])
{
    int n, h, ns;
    printf("Enter 0 To Print Triangular Star Pattern Or 1 To Print Revrse Triangular Star Pattern : ");
    scanf("%d", &n);
    printf("Upto What Number Of Stars ? : ");
    scanf("%d", &ns);
    if (n == 0)
    {

        for (int h = 0; h < ns; h++)
        {
            printf("\n");

            for (int i = 0; i <= h; i++)
            {
                printf("* ");
            }
        }
    }
    else
    {
        if (n == 1)
        {
            for (int h = 0; h < ns; h++)
            {
                printf("\n");

                for (int i = 1; i <= ns - h; i++)
                {
                    printf("* ");
                }
            }
        }
    }

    return 0;
}
