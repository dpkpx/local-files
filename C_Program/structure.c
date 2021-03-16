#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct employ
{
    int id_no;
    int Kms;
    char name[20];
    char route[20];
};

int main(int argc, char const *argv[])
{
    struct employ e1;
    e1.id_no = 1;
    e1.Kms = 146;
    //e1.name = "rahul";
    //fgets(e1.name, sizeof(e1.name), stdin);
    //  fgets(e1.route, sizeof(e1.route), stdin);




    printf("Employ ID No : %d", e1.id_no);
    printf("\nEmploy Route  : %s", e1.route);
    printf("\nEmploy Name  : %s", e1.name);
    printf("\nEmploy Kms : %d", e1.Kms);

    return 0; 
}
