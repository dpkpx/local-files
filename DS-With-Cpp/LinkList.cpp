#include <conio.h>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void clrscr()
{
  system("cls");
}

class Node
{
  private:
       int data;
       Node *NEXT;
  public:
	Node(int);
       ~Node();
       void insAtBeg(Node* &);
       void insAtEnd(void);
       void insAtPos(Node* &);
       void delFirst(Node* &);
       void delLast(void);
       void delPos(Node* &);
       void traverse(void);
};


Node::Node(int data)
{
 this->data = data;
 NEXT = NULL;
}

Node::~Node()
{
 clrscr();
 cout<<"\nDeleting Node With Data : "<<this->data<<endl;
 getch();
}

void Node::insAtBeg(Node* &head)
{
 clrscr();
 int data;
 cout<<"\nEnter Data : ";cin>>data;
 head = new Node(data);
 head->NEXT = this;
}

void Node::insAtEnd(void)
{
 int data;

 clrscr();
 cout<<"\nEnter Data : ";cin>>data;

 Node *ptr = this;

   while(ptr->NEXT!=NULL)
   {
    ptr = ptr->NEXT;
   }

 ptr->NEXT = new Node(data);
}

void Node::insAtPos(Node* &head)
{
 int pos,data;

 start:
 clrscr();
 cout<<"\nEnter The Position :";cin>>pos;

 if(pos==1)
 {
  insAtBeg(head);
 }
 else
 {
   cout<<"\nEnter Data :";cin>>data;
   Node* ptr = this;

    while(pos!=2&&ptr->NEXT!=NULL)
     {
      ptr = ptr->NEXT;
      pos--;
     }

    if(pos==2)
    {
     Node* temp = new Node(data);
     temp->NEXT = ptr->NEXT;
     ptr->NEXT = temp;
    }
    else
    {
     cout<<"\nPlease Enter A Valid Position ";
     getch();
     goto start;
    }
  }
}

void Node::delFirst(Node* &head)
{
 head = head->NEXT;
 delete this;
}

void Node::delLast(void)
{
 Node* ptr = this;

  while(ptr->NEXT->NEXT!=NULL)
  {
   ptr = ptr->NEXT;
  }

 delete ptr->NEXT;
 ptr->NEXT = NULL;
}

void Node::delPos(Node* &head)
{
 int pos;

 start:
 clrscr();
 cout<<"\nEnter Node Position To Be Deleted..";cin>>pos;

 if(pos==1)
 {
  delFirst(head);
 }
 else
 {

   Node* ptr = this;

    while(pos!=2&&ptr->NEXT->NEXT!=NULL)
    {
     ptr = ptr->NEXT;
     pos--;
    }

    if(pos==2)
    {
       Node* ptr2 = ptr->NEXT;
       ptr->NEXT = ptr->NEXT->NEXT;
       delete ptr2;
    }
    else
    {
      clrscr();
      cout<<"\nPlease Choose A Valid Position ";
      getch();
      goto start;
     }
   }
}

void Node::traverse(void)
{
   clrscr();
   Node *ptr = this;
   int i = 1;

   while(ptr!=NULL)
   {
    cout<<"\n\t["<<i<<"] -> "<<ptr->data<<endl;
    ptr = ptr->NEXT;
    i++;
   }

   getch();
}


int main()
{
 int data;

 clrscr();
 cout<<"\nPlease Initilize The LinkList \n Enter Data : ";cin>>data;

 Node *linkList = new Node(data);
 int ch;

 do{
   clrscr();
   cout<<"\n1. Add Node At Begning "<<endl;
   cout<<"2. Add Node At End "<<endl;
   cout<<"3. Insert Node At Position"<<endl;
   cout<<"4. Delete First Node "<<endl;
   cout<<"5. Delete Last Node "<<endl;
   cout<<"6. Delete Node at Position "<<endl;
   cout<<"7. Display "<<endl;
   cout<<"ESC To Exit.."<<endl;

   ch = getch();

   switch(ch)
   {
     case 49:
      linkList->insAtBeg(linkList);
      break;

     case 50:
      linkList->insAtEnd();
      break;

     case 51:
      linkList->insAtPos(linkList);
      break;

     case 52:
      linkList->delFirst(linkList);
      break;

     case 53:
      linkList->delLast();
      break;

     case 54:
      linkList->delPos(linkList);
      break;

     case 55:
      linkList->traverse();
      break;

     case 27:
      break;

     default:
       cout<<"\nPlease Choose A Valid Option ";
       break;
   }

   }while(ch!=27);
}