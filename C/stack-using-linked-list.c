//Author : Sanjana Sawnt

#include <stdio.h>
#include <stdlib.h>

struct stack_ll{
    int data;
    struct stack_ll *next;
};
typedef struct stack_ll node;
node *top =NULL;
node *head=NULL;

char menu();
void push();
void pop();
void display();
node *getnode();

node* getnode()
{
    node *temp;
    temp=(node *) malloc( sizeof(node)) ;
    printf("\nEnter data : ");
    scanf("%d", &temp -> data);
    temp -> next = NULL;
    return temp;
}

//Push an element to the top of the stack i.e. to the rear end of the list
void push(node *newnode)
{
    node *temp;
    if (newnode == NULL)
    {
        printf("\nStack underflow !!");
        return ;
    }
    else
    {
        if (head == NULL)
        {
            head = newnode;
            top = newnode;
        }
        else
        {
            temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next =newnode;
            top = newnode;
        }
        printf("\nData pushed onto stack");
    }
}

//Display all the elements of the stack
void display()
{
    node *temp;
    if (head == NULL)
        printf("\nEmpty Stack");
    else
    {
        temp = head ;
        printf("\nContents of the stack are : ");
        printf("\n%d", temp->data);
        while(temp->next != NULL)
        {
            temp = temp->next;
            printf("\n%d", temp->data);
        }
    }
}

//Pop the element at the top of the stack
void pop()
{
    node *temp;
    if(top == NULL)
    {
        printf("\nStack underflow");
        return;
    }
    temp = head;
    if (head->next == NULL)
    {
        printf("\nPopped element is %d ", top -> data);
        head = NULL;
        free(top);
        top = NULL;
    }
    else
    {
        while(temp -> next != top)
        {
            temp = temp -> next;
        }
        temp -> next = NULL;
        printf("\nPopped element is %d ", top -> data);
        free(top);
        top = temp;
    }
}

char menu()
{
    int ch;
    printf("\n\n-----------------------------------------------------------------");
    printf("\n1. Push an element");
    printf("\n2. Pop an element");
    printf("\n3. Display all elements");
    printf("\n4. Exit");
    printf("\n\nEnter your choice (1-4): ");
    scanf("%d",&ch);
    return ch;
}

int main()
{
    node *newnode;
    char ch;
    printf("\nProgram to implement stack using singly linked list \n\n");
    while (1)
    {
        ch = menu();
        switch (ch)
        {
            case 1: newnode = getnode();
                    push(newnode);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("\nInvalid choice !!!");
        }
    }
}
