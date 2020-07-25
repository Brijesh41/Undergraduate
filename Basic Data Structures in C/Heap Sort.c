#include <stdio.h>
void createheaptree(int arr[],int i);
int n;
void swap(int i,int j,int arr[]);
void heapsort(int arr[],int i);
int main()
{
    printf("ENTER THE NO. OF ELEMENTS\n");
    scanf("%d",&n);
    int arr[n];
    int i =0;
    for(i=0;i<n;i++)
    {
        arr[i] = 1000;
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        createheaptree(arr,i);
    }
    printf("\nstarting heapsort");
    for(i=n;i>0;i--)
    {
        swap(0,i-1,arr);
      heapsort(arr,i-1);
    }
     int k;
     printf("\nSORTED ARRAY");
   for(k=0;k<n;k++)
   {
       printf(" %d",arr[k]);
   }

}
void createheaptree(int arr[],int i)
 {
     printf("\nTOTAL NO OF ELEMENTS %d",i);
      int j=0;
      if(i<3)
      {
      	if(arr[1]<arr[0])
      	{
      	swap(1,0,arr);
      }
      	if(arr[2]<arr[0])
      	{
      		swap(2,0,arr);
		 }
	  }
    int smallest;
    int flag =0;
    while(j<i&&(2*j+2)<i)
    {
        smallest = arr[j];
        printf("REACHED HERE\n");
        int left = arr[2*j+1];
         int right = arr[2*j + 2];
        printf("CURRENTLY LEFT %d RIGHT %d PARENT %d",left,right,arr[j]);

       if(left<smallest)
        {
            //printf("fdsd");
         swap(j,2*j+1,arr);
         flag = 1;
        }
         if(right<smallest)
        {
          //  printf("dfsd");
         swap(j,2*j+2,arr);
         flag =1;
        }
       // if(flag ==0)
       //     return;
        ++j;
    }
    printf("\n");
    int k;
   // printf("\n SORTED ARRAY");
   for(k=0;k<=i;k++)
   {
       printf(" %d",arr[k]);
   }
}
void swap(int i,int j,int arr[])
{
    //printf("das");
    int temp  = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void heapsort(int arr[],int i)
{
    createheaptree(arr,i);
}
/*
10
11
37
55
22
30
20
14
100
37
47
*/
