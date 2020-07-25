#include <stdio.h>
void quicksort(int arr[],int i,int j);
void swap(int i,int j,int arr[]);

int main()
{
  int i,j,k;
  int n;
  printf("\nENTER THE NUMBER OF ELEMENTS IN ARRAY\n");
  scanf("%d",&n);
  int arr[n];
  for(i=0;i<n;i++)
  {
      scanf("%d",&arr[i]);
  }
  quicksort(arr,0,n-1);
  for(i=0;i<n;i++)
    printf(" %d",arr[i]);

}
void swap(int i,int j,int arr[])
{
    int temp  = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void quicksort(int arr[],int i,int j)
{
    int n =j;
    if(i>=j)
        return;
  if(arr[i]>arr[j])
        swap(i,j,arr);
    int pivot = (i+j)/2;
    while(i<pivot)
    {
        if(arr[i]<arr[pivot])
        {
            ++i;
        }
        else{
            swap(i,pivot,arr);
        }

    }
    while(pivot<j)
    {
        if(arr[pivot]<arr[j])
           {
               --j;
           }
           else{
            swap(j,pivot,arr);
           }
    }
    quicksort(arr,0,pivot);
    quicksort(arr,pivot,n-1);

}
//8 91 22 46 65 21 2 106 25
