#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
void append(struct Node **head)
{
    do
    {
        system("cls");
        int data;
        printf("Enter Data ");
        scanf("%d", &data);

        struct Node *temp = malloc(sizeof(struct Node));
        temp->data = data;
        temp->next = NULL;
        temp->prev = NULL;
        if (*head == NULL)
        {
            *head = temp;
        }
        else
        {
            struct Node *ptr = *head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->prev = ptr;
        }
        printf("Press Enter to Add more Or ESC to Exit..");
    } while (getch() != 27);
}
void display(struct Node **head)
{
    system("cls");

    struct Node *ptr = *head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    getch();
}
void displayBack(struct Node **head)
{
    system("cls");

    struct Node *ptr = *head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->prev;
    }
    getch();
}
void addAtBeg(struct Node **head)
{
    int data;
    system("cls");
    printf("Enter Data ");
    scanf("%d", &data);

    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    (*head)->prev = temp;
    temp->next = *head;
    *head = temp;
}
void addAtEnd(struct Node **head)
{
    int data;
    system("cls");
    printf("Enter Data ");
    scanf("%d", &data);

    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    struct Node *ptr = *head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
}
void addAtPos(struct Node **head)
{
    int pos;
    system("cls");
    printf(" Enter position ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        addAtBeg(head);
    }
    else
    {
        int data;
        system("cls");
        printf(" Enter data ");
        scanf("%d", &data);
        struct Node *temp = malloc(sizeof(struct Node));
        temp->data = data;
        temp->next = NULL;
        temp->prev = NULL;

        struct Node *ptr = *head;
        while (pos != 2)
        {
            ptr = ptr->next;
            pos--;
        }
        temp->next = ptr->next;
        temp->next->prev = temp;
        ptr->next = temp;
        temp->prev = ptr;
    }
}
void delFirst(struct Node &head)
{
    

}

int main()
{
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    head = NULL;

    int ch;
    do
    {
        system("cls");
        printf("1. Append \n");
        printf("2. Display \n");
        printf("3. Display Backward \n");
        printf("4. Add at Begning \n");
        printf("5. Add at End \n");
        printf("6. Add at position \n");
        printf("7. Delete First Node \n");
        printf("#. ESC to exit.. \n");
        ch = getch();
        switch (ch)
        {
        case 49:
            append(&head);
            break;

        case 50:
            display(&head);
            break;
        case 51:
            displayBack(&head);
            break;
        case 52:
            addAtBeg(&head);
            break;
        case 53:
            addAtEnd(&head);
            break;
        case 54:
            addAtPos(&head);
            break;
        case 55:
            delFirst((*head));
            break;    
        case 27:

            break;

        default:
            printf("Please choose a valid choice");
            break;
        }
    } while (ch != 27);

    return 0;
}
