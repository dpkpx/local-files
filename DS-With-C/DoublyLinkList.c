#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Append AS Add At End
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
// Display As Traverse
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

    if ((*head) == NULL)
    {
        *head = temp;
    }
    else
    {
        (*head)->prev = temp;
        temp->next = *head;
        *head = temp;
    }
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
    else if (pos >= 2)
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

void delFirst(struct Node **head)
{
    if ((*head) == NULL)
        return;

    struct Node *ptr = *head;
    (*head) = (*head)->next;

    if ((*head) != NULL)
        (*head)->prev = NULL;

    free(ptr);
}

void delLast(struct Node **head)
{
    if ((*head) == NULL)
        return;

    if ((*head)->next == NULL)
    {
        free((*head));
        (*head) = NULL;
    }
    else
    {

        struct Node *ptr = *head;
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }

        free(ptr->next);
        ptr->next = NULL;
    }
}

void delPos(struct Node **head)
{
    if ((*head) == NULL)
    {
        system("cls");
        printf("List Is Already Empty");
        getch();
        return;
    }

    int pos;
l1:

    system("cls");
    printf("Enter Pos TO Be Deleted.. ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        delFirst(head);
    }
    else
    {
        if (pos >= 2)
        {
            struct Node *ptr = *head;
            while (pos != 2 && ptr->next != NULL)
            {
                ptr = ptr->next;
                pos--;
            }
        }
        if (pos == 2)
        {

            struct Node *ptr2 = ptr->next;
            ptr->next->next->prev = ptr;
            ptr->next = ptr->next->next;
            free(ptr2);
        }
        else
        {
            printf("Please Enter A Valid Position .");
            getch();
            goto l1;
        }
    }
}

void delList(struct Node **head)
{
    while ((*head) != NULL)
    {
        struct Node *temp = *head;
        (*head) = (*head)->next;
        free(temp);
    }
}

void revList(struct Node **head)
{
    struct Node *next;
    struct Node *prev;
    prev = NULL;

    while ((*head) != NULL)
    {
        next = (*head)->next;
        (*head)->next = prev;
        (*head)->prev = next;
        prev = (*head);
        (*head) = next;
    }

    (*head) = prev;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head = NULL;

    int ch;
    do
    {
        system("cls");
        printf("1. Append \n");
        printf("2. Add at Begning \n");
        printf("3. Add at position \n");
        printf("4. Display \n");
        printf("5. Delete First Node \n");
        printf("6. Delete Last Node \n");
        printf("7. Delete At Position \n");
        printf("8. Delete Entire List \n");
        printf("9. Reverse The List \n");
        printf("#. ESC to exit.. \n");
        ch = getch();
        switch (ch)
        {
        case 49:
            append(&head);
            break;

        case 50:
            addAtBeg(&head);

            break;
        case 51:
            addAtPos(&head);
            break;
        case 52:
            display(&head);
            break;
        case 53:
            delFirst(&head);
            break;
        case 54:
            delLast(&head);
            break;
        case 55:
            delPos(&head);
            break;
        case 56:
            delList(&head);
            break;
        case 57:
            revList(&head);
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
