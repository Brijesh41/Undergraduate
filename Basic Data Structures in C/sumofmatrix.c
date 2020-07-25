#include <stdio.h>
#include <conio.h>
int main()
{
	int a1,a2,b1,b2,temp;
printf("ENTER THE DIMENSION OF  MATRIX 1");
scanf("%d", &a1);
scanf("%d",&a2);
printf("ENTER THE DIMENSION OF  MATRIX 2");
scanf("%d", &b1);
scanf("%d",&b2);
if(a2==b1)
{
	printf("Matrix multiplication possible");

}
else if(a1==b1)
{
    printf("ADJACENT MATRIX OF DIMENSION CONVERTED TO%dX%d", a2,b1);
    temp = a1;
    a1= a2;
    a2=temp;
}
else{
	printf("MATRIX MULTIPLICATION NOT POSSIBLE ");
	return 0;

}
int i,j;
int mat1[a1][a2];
int mat2[b1][b2];
int ans[a1][b2];
int *ptr1,*ptr2;
//ptr1=&mat1[0][0];
//ptr2 = &mat2[0][0];
printf("\nenter elements of first matrix");
for(i=0;i<a1;i++)
{
	for(j=0;j<a2;j++)
	{

		scanf("%d",&mat1[i][j]);

	}
}
for(i=0;i<a1;i++)
{
	printf("\n");
	for(j=0;j<a2;j++)
	{

		printf(" %d",mat1[i][j]);

	}
}
printf("\nenter elements of second matrix");
for(i=0;i<b1;i++)
{
	for(j=0;j<b2;j++)
	{

		scanf("%d",&mat2[i][j]);

	}
}
printf("SECOND MATRIX IS\n");
for(i=0;i<b1;i++)
{
	printf("\n");
	for(j=0;j<b2;j++)
	{

		printf(" %d",mat2[i][j]);

	}
}

int *ptr3,k,sum,flag;
int m,n;
sum =0;
//ptr3=&ans[0][0];
for(i=0;i<a1;i++)
{
	for(j=0;j<b2;j++)
	{

		k=0;
		for(n=0;n<a2;n++)
		{
		sum= sum+mat1[i][k]*mat2[k][j];
		//printf("\n values of sum at %d" ,sum);
		++k;
		}
			ans[i][j] = sum;
		sum= 0;
	}

}
printf("\nGOING TO ANSWER\n");
for(i=0;i<a1;i++)
{
	printf("\n");
	for(j=0;j<b2;j++)
	{
		printf(" %d",ans[i][j]);

}

}
}
