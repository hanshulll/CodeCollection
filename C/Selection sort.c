#include<stdio.h>
#include<conio.h>
int smallest(int arr[],int k,int n);
void selection_sort(int arr[],int n);
void main()
{
  int arr[10],i,n;
  clrscr();
  printf("Enter number of elements in array\n");
  scanf("%d",&n);
  printf("Enter the elements of the array\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  selection_sort(arr,n);
  printf("The sorted array is\n");
  for(i=0;i<n;i++)
    printf("%d\t",arr[i]);
   getch();
}
int smallest(int arr[],int k, int n)
{
  int pos=k, small=arr[k],i;
  for(i=k+1;i<n;i++)
  {
    if(arr[i]<small)
    {
      small=arr[i];
      pos=i;
    } 
  }
  return pos;
}
void selection_sort(int arr[],int n)
{
  int k,pos,temp;
  for(k=0;k<n;k++)
  {
    pos= smallest(arr,k,n);
    temp=arr[k];
    arr[k]=arr[pos];
    arr[pos]=temp;
  }
} 
