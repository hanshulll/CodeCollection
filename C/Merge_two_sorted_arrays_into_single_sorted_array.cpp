//https://github.com/suvarna-13
// This is a cpp program that inputs two sorted arrays of different lengths and merges it into a single array. The output is printed as a merged sorted array

#include <stdio.h>
int main() {
	int m,n,s,i,j,temp;
	printf("Enter the number of elements in first array");
	scanf("%d",&n);
	printf("Enter the number of elements in second  array");
	scanf("%d",&m);
	s=m+n;
    int A1[n] ,A2[m],A3[s];
    printf("Enter the elements of first array");
    for(i=0;i<n;i++)
    scanf("%d",&A1[i]);
    printf("Enter the elements of second array");
    for(i=0;i<m;i++)
    scanf("%d",&A2[i]);
    
   for(i=0;i<n;i++)
   {
      A3[i]=A1[i];
   }
   for(i=n;i<s;i++){
       A3[i]=A2[i-n];
   }
  
    for(i = 0; i<s; i++) {
        for(j = i + 1; j <s; j++) {
            if(A3[i] > A3[j]) {
                temp = A3[i];
                A3[i] = A3[j];
                A3[j] = temp;
            }
        }
    }
    printf("\nElements after merging and sorting the two arrays: ");
    for(i=0;i<s;i++){
        printf("%d  ",A3[i]);
    
 }
}


