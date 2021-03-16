#include <stdio.h>
#include <stdlib.h>
/*
program to convert 
kms to miles
inches to foot
pounds to kgs
inches to meter
*/

int main(int argc, char const *argv[])
{

    char ch, mh = 'y';
    int n;
    float d, m;
start:
    system("cls");
    printf("Choose To Convert\n\n");
    printf("1. kms to miles\n");
    printf("2. inches to foot\n");
    printf("3. pounds to kgs\n");
    printf("4. inches to meter\n");
    printf("Please Enter Your Choice: ");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        printf("Please Enter Your Number: ");
        scanf("%f", &d);
        m = d / 1.609;
        printf("%f kms = %f miles\n", d, m);
        break;
    case 2:
        printf("Please Enter Your Number: ");
        scanf("%f", &d);
        m = d / 12;
        printf("%f inches = %f foot\n", d, m);
        break;
    case 3:
        printf("Please Enter Your Number: ");
        scanf("%f", &d);
        m = d / 2.205;
        printf("%f pound = %f kgs\n", d, m);
        break;
    case 4:
        printf("Please Enter Your Number: ");
        scanf("%f", &d);
        m = d / 39.37;
        printf("%f inches = %f m\n", d, m);
        break;
    default:
        printf("Please Enter A Valid Choice\n");
        break;
    }
    printf("Calculate more ?\nEnter Your Choice (y/n) :");
    scanf(" %c", &ch);


    if (ch == mh)
    {
        goto start;
    }

    return 0;
}
