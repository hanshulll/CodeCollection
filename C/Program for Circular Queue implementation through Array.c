//Program for Circular Queue implementation through Array

#include <stdio.h>
#include<ctype.h>
# define maxsize 200

int cq[maxsize];
int front,rear;

void main()
{
void add(int,int [],int,int,int);
int del(int [],int ,int ,int );
int will=1,i,num;
front = 1;
rear = 1;

clrscr();
printf("
		Program for Circular Queue demonstration through array


");
while(will ==1)
{
printf("
		MAIN MENU: 
	1.Add element to Circular Queue
	2.Delete element from the Circular Queue
");
scanf("%d",&will);

switch(will)
{
case 1:
	printf("
Enter the data... ");
	scanf("%d",&num);
	add(num,cq,maxsize,front,rear);
	break;
case 2: i=del(cq,maxsize,front,rear);
	printf("
Value returned from delete function is  %d ",i);
	break;
default: printf("

Invalid Choice . ");
}

printf(" 

			Do you want to do more operations on Circular Queue ( 1 for yes, any other key to exit) ");
scanf("%d" , &will);
} //end of  outer while
}               //end of main

void add(int item,int q[],int MAX,int front,int rear)
{
rear++;
rear= (rear%MAX);
if(front ==rear)
	{
	printf("

		CIRCULAR QUEUE FULL

");
	return;
	}
else
	{
	cq[rear]=item;
	printf("
Rear = %d    Front = %d ",rear,front);
	}
}
int del(int q[],int MAX,int front,int rear)
{
int a;
if(front == rear)
	{
	printf("

		CIRCULAR STACK EMPTY

");
	return (0);
	}
else
	{
	front++;
	front = front%MAX;
	a=cq[front];
	return(a);
	printf("
Rear = %d    Front = %d ",rear,front);
	}
}