#include<stdio.h>
int circque[10];
int rear=-1,front=-1;
int i,val;
void insert()
{

    if(front==(rear+1)%10)
        printf("Queue overflow. Insertion not possible.\n");
    else
    {
        printf("Enter the value you wish to insert:\n");
        scanf("%d",&val);
        circque[++rear]=val;
        if(front==-1) front=0;
        if(rear==9) rear=-1;
        printf("Element inserted.\n");
    }
}
void del()
{
    if(rear==-1 && front==-1)
     printf("Queue underflow. Deletion not possible.\n");
     else if(front==rear)
     {
         front=rear=-1;

     }
     else
     {
         if(front==9){
            if(rear==-1) front=-1;
            else front=0;}
         else front++;
     }
}
 void display()
 {
    for(i=0;i<10;i++)
    {
        if(front<=rear)
        {
            if(i>=front && i<=rear)
                printf("%d ",circque[i]);
            else
                printf("_ ");
        }
        else if (front>rear)
        {
            if(i<=rear || i>=front)
                printf("%d ",circque[i]);
            else
                printf("_ ");
        }
    }
    printf("\n");
     printf("%d\n",front);
     printf("%d\n",rear);
 }

 void main()
 {
     int ch;
     do
     {
     printf("%%%%%%%%%%Circular Queue%%%%%%%%%%%\n");
     printf("1. Insertion\n");
     printf("2. Deletion\n");
     printf("3. Display\n");
     printf("Enter your choice:\n");
     scanf("%d",&ch);
     switch(ch)
     {
         case 1: insert();
                  break;
         case 2: del();
                 break;
         case 3: display();
                 break;
         default: exit(0);
     }
     } while(ch<4);
 }
