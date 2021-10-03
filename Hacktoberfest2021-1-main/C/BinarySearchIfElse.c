#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

int recur(int arr[],int left,int right, int key)
{
     int mid=(left+right)/2;
     while(left<right){
          if(arr[mid]==key)
               return key;
          if(arr[mid]>key)
               right=mid-1;
          left=mid+1;
     }
     return -1;
}
void main()
{
     int arr[MAX],n,key;
     printf("Enter number of elements in the array (in ascending or decending order) : ");
     scanf("%d",&n);
     int left=0;
     int right=n-1;
     printf("Enter elements in the array : ");
     for(int i=0;i<n;i++)
          scanf("%d",&arr[i]);
     printf("Enter the element you want to search : ");
     scanf("%d",&key);
     printf("Element found at %d",recur(arr,left,right,key));
}