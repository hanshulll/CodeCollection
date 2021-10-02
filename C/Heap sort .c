#include<stdio.h>
int heap_size,length;
void HEAP_SORT(int *);
void BUILD_MAX_HEAP(int *);
void MAX_HEAPIFY(int *,int);
int LEFT(int);
int RIGHT(int);
void swap(int *,int *);
int main()
{
    int i,A[30];
    printf("Enter the number of elements: ");
    scanf("%d",&length);
    printf("Enter %d number of elements: ",length);
    for(i=0;i<length;i++)
        scanf("%d",&A[i]);
    printf("\nBefore sorting the elements are: ");
    for(i=0;i<length;i++)
        printf("%d ",A[i]);
    HEAP_SORT(A);
    printf("\nAfter sorting the elements are: ");
    for(i=0;i<length;i++)
        printf("%d ",A[i]);
    return 0;
}
void HEAP_SORT(int *p)
{
	int i;
	BUILD_MAX_HEAP(p);
	for(i=length-1;i>=1;i--)
	{
        swap((p),(p+i));
        heap_size--;
        MAX_HEAPIFY(p,0);
	}
}
void BUILD_MAX_HEAP(int *p)
{
	int i;
	heap_size=length-1;
	for(i=(length-1)/2;i>=0;i--)
        MAX_HEAPIFY(p,i);
}
void MAX_HEAPIFY(int *p,int i)
{
	int l,r,largest;
	l=LEFT(i);
	r=RIGHT(i);
	if(l<=heap_size && (*(p+l)>*(p+i)))
        largest=l;
    else largest=i;
    if(r<=heap_size && (*(p+r)>*(p+largest)))
        largest=r;
    if(largest!=i)
       {
            swap((p+i),(p+largest));
            MAX_HEAPIFY(p,largest);
       }
}
int LEFT(int i)
{
	return(2*i+1);
}
int RIGHT(int i)
{
	return(2*i+2);
}
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}



//sample o/p
//Enter the number of elements: 4
//Enter 4 number of elements: 5
//4
//6
//8
//
//Before sorting the elements are: 5 4 6 8
//After sorting the elements are: 4 5 6 8
