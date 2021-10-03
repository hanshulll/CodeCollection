//using bubble sort..sorting an array in ascending order.....
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,*p,temp=0;

    int i,j,k;

  printf("enter the size of an array:\n");
  scanf("%d",&n);

  p=(int*)calloc(n,4);

  if(p==NULL)
   {
       printf("error!!");
       exit(1);
   }

  printf("enter the elements of the array:\n");
  for(j=0;j<n;j++)
  {
      scanf("%d",(p+j));
  }

  printf(" after sorting  the array in ascending order using bubble sort...\n");

  for(j=0;j<n-1;j++)
  {

      for(i=0;i<n-j-1;i++)
      {
          if(*(p+i)> *(p+(i+1)))
      {
          temp=*(p+i);
        *(p+i)=*(p+(i+1));
        *(p+(i+1))=temp;


      }

      }
      printf("modified array:");

      for(k=0;k<n;k++)
    {
      printf(" %d",*(p+k));

      }

      printf("\n");



  }





}
