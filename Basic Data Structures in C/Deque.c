#include <stdio.h>
#include <conio.h>
int Queue[5];
int front = 0;
int rear = -1;
int flag = 0;
int i;
void enqueue(int a);
void dequeue();
void display();
int main()
{
	char  m;
	int f;
	printf("\nENTER CHOICE  \n  1)ENQUEUE\n  2)DEQUEUE\n  3) DISPLAY\n  4) EXIT");
	while(1){
		printf("\n  ENTER CHOICE\n");
		scanf("%c",&m);
	 
	switch(m){	
		case '1':printf("\n ENQUEUE : \n ENTER ELEMENT\n");
		scanf("%d",&f);
		enqueue(f);
		break;
		case '2' : 
		printf("\n DEQUEUE : \n");
		dequeue();
		break;
		case '3': display();
			break;
			case '4':
						return 0 ; 
			}	
         }
}
void enqueue(int a)
{
if((front==0&&rear==4)||(front>0&&rear==front-1))
   {     printf("Queue is overflow\n");
}
    else
    {
        if(rear==4&&front>0)
        {
            rear=0;
            Queue[rear]=a;
        }
        else
        {
            if((front==0&&rear==-1)||(rear!=front-1))
                Queue[++rear]=a;
        }
    }
    printf("REAR IS POINTING AT %d\n ",rear);
    printf("FRONT IS POINTING AT %d\n ",front);
}
void dequeue()
{
	int b;
	if((front==0)&&(rear==-1))
	{
		printf("UNDERFLOW");
		return 0;
	}
	 if(front==rear)
	{
	front = 0;
	rear = -1;	
	}
	else {
	if (front == 4)
	{
		b=Queue[front];
		front = 0;
		printf("Deleted element is:%d\n",b);
	}
	else{
		b=Queue[front++];
        printf("Deleted element is:%d\n",b);
	    }
    }
     printf("REAR IS POINTING AT %d\n ",rear);
    printf("FRONT IS POINTING AT %d\n ",front);
}

void display(){
	printf("\nDISPLATING QUEUE\n");

int i,j;
    if((front==0)&&(rear==-1))
    {
        printf("Queue is underflow\n");
        return 0;
    }
    if(front>rear)
    {
        for(i=0;i<=rear;i++)
            printf("\t%d",Queue[i]);
        for(j=front;j<=4;j++)
            printf("\t%d",Queue[j]);
        printf("\nrear is at %d\n",Queue[rear]);
        printf("\nfront is at %d\n",Queue[front]);
    }
    else
    {
        for(i=front;i<=rear;i++)
        {
            printf("\t%d",Queue[i]);
        }
        printf("\nrear is at %d\n",Queue[rear]);
        printf("\nfront is at %d\n",Queue[front]);

    }
}
