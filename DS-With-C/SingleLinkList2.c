#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct node
{ //data
    int data;
    //link
    struct node *link;
}*head=NULL;

//struct node *head = NULL;


void append()
{
 struct node* ptr=head;
    do
    {
        system("cls");
        int data;
        printf("Enter Data ");
        scanf("\n%d", &data);

        struct node *temp = malloc(sizeof(struct node));
        temp->data = data;
        temp->link = NULL;

        if (head == NULL)
        {
            head = temp;
            ptr=head;
        }
        else
        {
            while (ptr->link!=NULL)
            {
                ptr=ptr->link;
            }
            ptr->link=temp;
        }
       
        system("cls");
        printf("\nPress Enter to append Or ESC to Exit...");

    } while (27 != getch());
}



void addBegning()
{
    do
    {
        system("cls");
        int data;
        printf("Enter Data ");
        scanf("\n%d", &data);

        struct node *temp = malloc(sizeof(struct node));
        temp->data = data;
        temp->link = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            temp->link = head;
            head = temp;
        }

        system("cls");
        printf("\nPress Enter to add more Or ESC to Exit...");

    } while (27 != getch());
}



void display()
{
    system("cls");
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
    getch();
}



void insertPos()
{
    do
    {
        system("cls");
        int pos;
        printf("Enter pos ");
        scanf("\n%d", &pos);

        system("cls");
        int data;
        printf("Enter Data ");
        scanf("\n%d", &data);

        struct node *temp = malloc(sizeof(struct node));
        temp->data = data;
        temp->link = NULL;
        //
        struct node *ptr = head;
        while (pos != 2)
        {
            ptr = ptr->link;
            pos--;
        }
        temp->link = ptr->link;
        ptr->link = temp;
        system("cls");
        printf("\nPress Enter to insert more Or ESC to Exit...");

    } while (27 != getch());
}



void delFirst()
{
    struct node *temp = NULL;
    temp = head->link;
    free(head);
    head = temp;
    temp = NULL;
}



void delLast()
{
    struct node *temp = NULL;
    temp = head;
    while (temp->link->link != NULL)
    {
        temp = temp->link;
    }
    free(temp->link);
    temp->link = NULL;
    temp = NULL;
}



void delPos()
{
    int pos;
    system("cls");
    printf("Enter Position To be deleted \n");
    scanf("%d", &pos);
    struct node *ptr = head;
    while (pos != 2)
    {
        ptr = ptr->link;
        pos--;
    }
    struct node *temp2 = ptr->link;
    ptr->link = temp2->link;
    free(temp2);
    ptr = NULL;
    temp2 = NULL;
}



void delEntLst(){
    struct node* temp;
    while (head!=NULL)
    {   temp=head;
        head=head->link;
        free(temp);
    }
    
}



void reverse()
{
    struct node *prev;
    struct node *next;
    prev = NULL;
    while (head != NULL)
    {
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev;
}


int main()
{
    int ch;
    do
    {
        system("cls");
        printf("1. Append \n");
        printf("2. Insert at begning \n");
        printf("3. Display \n");
        printf("4. Insert At pos \n");
        printf("5. Delete First Node \n");
        printf("6. Delete Last Node \n");
        printf("7. Delete at Position \n");
        printf("8. Delete the entire list \n");
        printf("9. reverse the list \n");
        printf("#. ESC to exit \n");
        printf("please choose option..\n");
        ch = getch();
        switch (ch)
        {
        case 49:
            append();
            break;
        case 50:
            addBegning();
            break;
        case 51:
            display();
            break;
        case 52:
            insertPos();
            break;
        case 53:
            delFirst();
            break;
        case 54:
            delLast();
            break;
        case 55:
            delPos();
            break;
        case 56:
            delEntLst();
            break;
        case 57:
            reverse();
            break;
        case 27:

            break;

        default:
            printf("Please Enter a valid choice..");
            getch();
            break;
        }

    } while (ch != 27);
}