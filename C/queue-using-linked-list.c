//Author: Sanjana Sawant

#include <stdio.h>
#include <stdlib.h>

struct queue{
    int data;
    struct queue *next;
};

//define a data type for the structure
typedef struct queue node;
node *front=NULL ;
node *rear=NULL ;

node *getnode();
void insert();
void pop();
void display();
int menu();

//Getting a new node every time an element is inserted
node *getnode()
{
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    printf("\nEnter data : ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}

//Insert an element at the rear end
void insert()
{
    node *newnode;
    newnode = getnode();

    if(newnode == NULL)
    {
        printf("\nQueue is FULL !!");
        return;
    }

    if(front == NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->next =newnode;
        rear = newnode;
    }
    printf("\nData inserted in the queue");
}

//Pops the first element in the queue
void pop()
{
    node *temp;
    if (front == NULL)
    {
        printf("\nEmpty Queue !!");
        return;
    }
    else
    {
        printf("\nPopped element %d",front->data);
        temp = front;
        front = front->next;
        free(temp);
    }
}

//Display complete list
void display()
{
   node *temp;
   if (front == NULL)
   {
       printf("\nEmpty Queue !!");
       return;
   }
   else
   {
       temp = front;
       printf("\nElements of the queue are : \n");
       while(temp != NULL)
       {
           printf("%d \n",temp->data);
           temp = temp->next;
       }
   }
}

//Menu for the functions
int menu()
{
    int ch;
    printf("\n\n-----------**********-------------\n");
    printf("\n 1. Insert ");
    printf("\n 2. Pop ");
    printf("\n 3. Display");
    printf("\n 4. Exit ");
    printf("\n Enter your choice: ");
    scanf("%d", &ch);
    return ch;
}

int main()
{
    int ch;
    printf("Program to implement Queue using linked list \n\n\n");
    do
    {
        ch = menu();
        switch(ch)
        {
            case 1: insert();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default : printf("\nInvalid Choice !!");
        }
   } while(1);
}

