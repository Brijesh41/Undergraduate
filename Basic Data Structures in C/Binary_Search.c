#include <stdio.h>
void binarysearch(int a[],int x,int n);

void swap(int *xp, int *yp);
int first = 0;
int n;
	int last = 100;
int main()
{
	int n;
	printf("\n ENTER THE TOTAL NO OF ELEMENTS");
	scanf("%d",&n);
	int a[n];
	int i =0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int x;
	printf("\n ENTER THE ELEMENT TO FIND");
	scanf("%d",&x);
	last = n-1;
	int j;
   for (i = 0; i < n-1; i++)      
{
 
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
          {
		    if (a[j] > a[j+1])
              swap(&a[j], &a[j+1]);
       }
}
for(i=0;i<n;i++)
{
	printf(" %d",a[i]);
}
	binarysearch(a,x,n);
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void binarysearch(int a[],int x,int n)
{
	
	
	if(first<last)
	{
	int middle = (last+first)/2;
	if(x==a[middle])
	{
		printf("\nELEMENT FOUND AT INDEX %d",middle);
	}
	if(x<a[middle])
	{
		last = middle;
		binarysearch(a,x,n);
	}
	if(x>a[middle])
	{
		first = middle;
		binarysearch(a,x,n);
	}
    }
    return;
}
