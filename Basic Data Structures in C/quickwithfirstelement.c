#include <stdio.h>
void quicksort(int arr[],int left,int right);
void swap(int i,int j,int arr[])
{
    int temp  = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int main()
{
	  int i,j,k;
  int n;
  printf("\nENTER THE NUMBERS IN ARRAY\n");
  scanf("%d",&n);
  int arr[n];
  for(i=0;i<n;i++)
  {
      scanf("%d",&arr[i]);
  }
  for(i=0;i<n;i++)
    printf(" %d",arr[i]);
  quicksort(arr,0,n-1);
  printf("\n");
  for(i=0;i<n;i++)
    printf(" %d",arr[i]);

}
void quicksort(int arr[],int left,int right)
{
	if(left<right)
	{
	int pivot = partition(arr,left,right);
    quicksort(arr,left,pivot-1);
    quicksort(arr,pivot+1,right);
    }
}
int partition(int arr[],int left,int right)
{
	int pivot = arr[left];
	int i = left+1;
	int j;
	for(j = left+1;j<=right;j++)
	{
		if(arr[j]<pivot)
		{
			swap(i,j,arr);
			++i;
		}
	}
	swap(left,i-1,arr);
	return i-1;
}
