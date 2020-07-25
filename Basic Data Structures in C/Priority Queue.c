#include <stdio.h>
#include <conio.h>
int x,p,i,b,r,e;
int arr[10];
int index[10];
int temp,temp1;
int priority[10][10];
int front,rear;
int ct1,ct2,ct3,ct4;
int l;
void insert();
void delete();
void display();
void insert()
{
    int a;
    int b;
    int m;
    printf("\nENTER THE ELEMENT\n");
   scanf("%d",&a);
    printf("\n ENTER THE PRIORITY");
    scanf("%d",&b);
    temp = arr[b];
    printf("Index %d",arr[b]);
     m = arr[b];
    priority[b][m] = a;
    printf(" ELEMENT ADDED -->%d --> at index %d  %d",priority[b][m],b,m);
    arr[b]= ++temp;
     printf("\nIndex after operation %d",arr[b]);
}
void delete()
{
	int f = e;
	printf("REACHED HERE");
     i =0;
    while(priority[f][index[f]]==0)
    {
    	printf("REACHED HERE1");
        printf("THERE ARE ZERO ELEMENTS AT PRIORITY %d\n",l);
        --f;
        if(f<0)
           {
           	printf("REACHED HERE1");

            break;
           }
    }

r=index[f];
    if(priority[f][r]!=0)
    {
        printf("\nDELETED ELEMENT IS %d\n",priority[f][r]);
        temp1 = r;
        index[f]=++temp1;
        printf("index after deletion is %d \n",index[f]);
    }

}
void display()
{
    int i =0;
    int j =0;
    for(i=0;i<3;i++)
    {
        printf("\nPRIORITY --> %d",i);
        //j = index[i];
        for(j=index[i];j<x;j++)
        {
        	if(priority[i][j]!=0)
        	{
        		printf(" %d",priority[i][j]);
			}
        }     
}
}



int main()
{

printf("ENTER THE TOTAL NUMBER OF ELEMENTS");
scanf("%d",&x);
printf("\n THE priority available are 0-2 ");
p = 2;
int k = p;
int i = 0;
int j=0;
e=p;
l = p;
for(j = 0;j<10;j++)
{
    arr[j] = 0;
}
j=0;
for(j = 0;j<10;j++)
{
    index[j] = 0;
}

i =0;
char  m;
	int f;
	printf("\nENTER CHOICE  \n  1)INSERT\n  2)DELETE\n  3) DISPLAY\n  4) EXIT");
	while(1){
		printf("\n  ENTER CHOICE\n");
		scanf("%c",&m);
		switch(m)
		{
		    case '1' : insert();
		    break;
		    case '2' : delete();
		    break;
		    case '3' : display();
		    break;
		    case '4': return 0;
		}

}
}
