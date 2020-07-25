#include <stdio.h>
int add;
struct node
{
    int x;
    int y;
    int z;
    int coeff;
    struct node *next;
};
struct node* head1;
struct node* head2;
struct node* head3;
void makepolynomial1(int a,int b,int c ,int d);
void makepolynomial2(int a,int b,int c ,int d);
void display1();
void display2();
void display3();
void copying();
void addpolynomial();
int main()
{
    head1 = (struct node*)malloc(sizeof(struct node));
    head1->next = NULL;
     head2 = (struct node*)malloc(sizeof(struct node));
    head2->next = NULL;
    head3= (struct node*)malloc(sizeof(struct node));
    head3->next = NULL;
    int no;
    printf("ENTER THE NO TERMS IN POLY1");
    scanf("%d",&no);
    int i =0;
    int x1,y1,z1,coeff1;
    int flag = 0;

    for(i=0; i<no; i++)
    {

        printf("\nENTER THE COEFFIECIENT");
        scanf("%d",&coeff1);
        printf("\nENTER THE VALUE OF X");
        scanf("%d",&x1);
        printf("\nENTER THE VALUE OF Y");
        scanf("%d",&y1);
        printf("\nENTER THE VALUE OF Z");
        scanf("%d",&z1);
        if(!(flag==0))
        {
        makepolynomial1(coeff1,x1,y1,z1);
        }
        else{
            head1->coeff = coeff1;
            head1->x = x1;
            head1->y = y1;
            head1->z= z1;
            flag=1;
        }
    }
    printf("ENTER THE NO TERMS IN POLY2");
    scanf("%d",&no);
    flag =0;
    i =0;
    int x2,y2,z2,coeff2;
    for(i=0; i<no; i++)
    {
        printf("\nENTER THE COEFFIECIENT");
        scanf("%d",&coeff2);
        printf("\nENTER THE VALUE OF X");
        scanf("%d",&x2);
        printf("\nENTER THE VALUE OF Y");
        scanf("%d",&y2);
        printf("\nENTER THE VALUE OF Z");
        scanf("%d",&z2);
        if(!(flag==0))
        {
        makepolynomial2(coeff1,x1,y1,z1);
        }
        else{
            head2->coeff = coeff1;
            head2->x = x1;
            head2->y = y1;
            head2->z= z1;
            flag=1;
        }

    }
    printf("\n DISPLAYING 1");
    display1();
    printf("\n DISPLAYING 2");
    display2();
    copying();
    addpolynomial();
    printf("\n DISPLAYIGN 3");
    display3();


}
void makepolynomial1(int a,int b ,int c,int d)
{
    struct node* new = NULL;
    new = (struct node*)malloc(sizeof(struct node));
    struct node* temp = NULL;
    temp = head1;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    new->coeff = a;
    new->x = b;
    new->y=c;
    new->z=d;
    new->next=NULL;
    temp->next=new;
}
void makepolynomial2(int a,int b ,int c,int d)
{
    struct node* new = NULL;
    new = (struct node*)malloc(sizeof(struct node));
    struct node* temp = NULL;
    temp = head2;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    new->coeff = a;
    new->x = b;
    new->y=c;
    new->z=d;
    new->next=NULL;
    temp->next=new;
}
void display1()
{

    struct node* temp1 = NULL;
    temp1=head1;
    while(temp1->next!=NULL)
    {
        printf("coeff->%d x->%d y->%d z->%d add->%d",head1->coeff,head1->x,head1->y,head1->z);
        temp1=temp1->next;
    }
    printf("coeff->%d x->%d y->%d z->%d add->%d",temp1->coeff,temp1->x,temp1->y,temp1->z);
}
void display2()
{

    struct node* temp1 = NULL;
    temp1=head2;
    while(temp1->next!=NULL)
    {
        printf("coeff->%d x->%d y->%d z->%d add->%d",head2->coeff,head2->x,head2->y,head2->z);
        temp1=temp1->next;
    }
    printf("coeff->%d x->%d y->%d z->%d add->%d",temp1->coeff,temp1->x,temp1->y,temp1->z);
}
void display3()
{

    struct node* temp1 = NULL;
    temp1=head3;
    while(temp1->next!=NULL)
    {
        printf("coeff->%d x->%d y->%d z->%d add->%d",head3->coeff,head2->x,head2->y,head2->z);
        temp1=temp1->next;
    }
    printf("coeff->%d x->%d y->%d z->%d add->%d",temp1->coeff,temp1->x,temp1->y,temp1->z);
}
void addpolynomial()
{
    int k;
     struct node* temp = NULL;
    temp=head1;
     struct node* temp1 = NULL;
    temp1=head2;
     struct node* temp3 = NULL;
    temp1=head3;


}
void insertatend(int a,int b,int c,int d)
{
    struct node* new = NULL;
new = (struct node*)malloc(sizeof(struct node));
struct node* temp = NULL;
temp = head3;
while(temp->next!=NULL)
{
    temp = temp->next;
}
new->coeff = a;
new->x=b;
new->y=c;
new->z=d;
new->next=NULL;
temp->next=new;
}
void copying(){
    printf("\n \n");
    int tempa,tempb,tempc,tempd;
head3 = head2;
struct node* temp = NULL;
temp = head3;//i
struct node* temp1 = NULL;
temp1 = head3;//j
while(temp->next!=NULL)
{
    temp1 = head3;
    while(temp1->next!=NULL)
    {
        if(temp->x>temp1->x)
        {
             tempa= temp->x;
            tempb = temp->y;
            tempc = temp->z;
            tempd = temp->coeff;
            temp->x  = temp1->x;
            temp->y  = temp1->y;
            temp->z  = temp1->z;
            temp->coeff = temp1->coeff;
            temp1->x=tempa;
            temp1->y=tempb;
            temp1->z=tempc;
            temp1->coeff=tempd;
        }
        else if(temp->y > temp1->y)
        {
              tempa= temp->x;
            tempb = temp->y;
            tempc = temp->z;
            tempd = temp->coeff;
            temp->x  = temp1->x;
            temp->y  = temp1->y;
            temp->z  = temp1->z;
            temp->coeff = temp1->coeff;
            temp1->x=tempa;
            temp1->y=tempb;
            temp1->z=tempc;
            temp1->coeff=tempd;
        }
        else if (temp->z > temp1->z)
        {
             tempa= temp->x;
            tempb = temp->y;
            tempc = temp->z;
            tempd = temp->coeff;
            temp->x  = temp1->x;
            temp->y  = temp1->y;
            temp->z  = temp1->z;
            temp->coeff = temp1->coeff;
            temp1->x=tempa;
            temp1->y=tempb;
            temp1->z=tempc;
            temp1->coeff=tempd;
        }
        else{
         //   printf("DONT ENTER EQUAL TERMS");
        }
        temp1= temp1->next;
    }
   temp = temp->next;
}
}
