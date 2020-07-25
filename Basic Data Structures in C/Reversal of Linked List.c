#include <stdio.h>
int y;
int *add;
struct node{
int data;
struct node *next;
};
struct node* head;
void insertatend(int y);
void display();
void reverse();
int main()
{
    int x;
    printf("\nENTER THE VALUE OF HEAD");
    scanf("%d",&x);
    head = (struct node*)malloc(sizeof(struct node));
    head->next=NULL;
     head->data = x;//INTIALLY DATA OF HEAD IS 5
     int  b,c;
     int ch;
     do
     {
     printf("\nENTER YOUR CHOICE\n");
     printf("1)Insertatend");
     printf("\n2) replace");
     printf("\nEnter your choice:\n");
     scanf("%d",&ch);
     switch(ch)
     {
         case 1: printf("\nENTER NO TO INSERT");
             scanf("%d",&b);
             insertatend(b);
                  break;
          case 2:
              printf("BEFORE REVERSING \n");
               display();
               printf("\nAFTER REVERSING \n");
               reverse();
               display();
          break;
          exit(0);
         default: exit(0);
     }
     } while(ch<3);
}
void insertatend(int y)
{
struct node* new = NULL;
new = (struct node*)malloc(sizeof(struct node));
struct node* temp = NULL;
temp = head;
while(temp->next!=NULL)
{
    temp = temp->next;
}
new->data = y;
new->next=NULL;
temp->next=new;
}
void reverse()
{
    struct node* temp = NULL;
    struct node* temp1 = NULL;
    struct node* temp2 = NULL;
   temp1 = head;
    while(temp1!=NULL)
    {
        temp2  = temp1->next;
        temp1->next = temp;
        temp = temp1;
        temp1 = temp2;
    }
    head=temp;
}

void display()
{
    struct node* temp1 = NULL;
    temp1=head;
    while(temp1->next!=NULL)
    {
        printf(" %d",temp1->data);
        printf(" %d",&temp1);
        temp1=temp1->next;
    }
    printf(" %d",temp1->data);
     printf(" %d",&temp1);

}


