#include <conio.h>
#include<stdio.h>
#include<stdlib.h>

struct node
{//data 
int num;
//link
struct node* link;
   
};

int main(){

struct node * head = malloc(sizeof(struct node)) ;
head->num=1;
head->link=NULL;

struct node* current=malloc(sizeof(struct node)) ;
current->num=2;
current->link=NULL;
head->link=current;



current=malloc(sizeof(struct node)) ;
current->num=3;
current->link=NULL;
head->link->link=current;


current=malloc(sizeof(struct node)) ;
current->num=4;
current->link=NULL;
head->link->link->link=current;


current=malloc(sizeof(struct node)) ;
current->num=5;
current->link=NULL;
head->link->link->link->link=current;

struct node* ptr=head;
while (ptr!=NULL)
{
    printf("%d",ptr->num);
    ptr=ptr->link;
}






}