// Program to check whether Linked List is sorted or not.

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first=NULL;

void create (int A[], int n)
{
	int i; 
	struct Node *t, *last;
	first=(struct Node *)malloc(sizeof(struct Node));
	first->data=A[0];
	first->next=NULL;
	last=first;
	for(i=1; i<n; i++)
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}

int isSorted(struct Node *p)
{
	int x = -32768;
	while(p!=NULL)
	{
		if(p->data < x)
		return 0;
	  x = p->data;
	  p = p->next;	
	}
	return 1;
}

int main()
{
	int A[]={10, 2, 30, 40, 50};
	create(A, 5);
	if(isSorted(first))
	{
		printf("Linked List is Sorted\n");
	}
	else
	{
		printf("Linked List is Not Sorted\n");
	}
	return 0;
}


/*

Output :- 

Linked List is Not Sorted

*/
