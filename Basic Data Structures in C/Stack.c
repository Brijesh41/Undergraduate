#include <stdio.h>
int stack[100],tos;
void push(int x);
void pop();
void peep(int z);
void display();
int main() {
    while(1)
    {
    	int m,a;
    	printf("\nENTER OPERATION ON STACK\n1)push\n2)pop\n3)peep\n4)display\n5)exit\n");
    	scanf("%d",&a);
    	switch(a)
    	{
    		case 1 : printf("\nENTER ELEMENT TO PUSH\n");
    		scanf("%d",&m);
			push(m);
			break;
			case 2: pop();
			break;
			case 3: scanf("%d",&m);
			peep(m);
			break;
			case 4 : display();
			break;
			case 5 : return 0;
		}
	}
}
void push(int k)
{
    if(tos>=100)
    {
        printf("\nSTACK OVERFLOW");
    }
   else{
    //   printf("DD");
    ++tos;
   stack[tos]=k; 
  
   }
}
void display()
{
	printf("DISPLAYING STACK");
    int i;
    for(i=tos;i>0;--i)
    {
        printf("\n%d",stack[i]);
    }
    
}
void pop()
{
  if(tos>0)
  {
  	
  	stack[--tos];
  }
  else{
  	printf("STACK UNDERFLOW");
  }
  
  
}
void peep(int k)
{
	int i;
	int flag = 0;
	for(i=tos;i>0;--i)
	{
		if(k==stack[i])
		{
			printf("found element at index %d",i);
			flag = 1;
		}
		
		
	}
	if(flag!=1)
	{
		printf("ELEMENT NOT FOUND");
	}
}
