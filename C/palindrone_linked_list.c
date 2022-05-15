#include <stdio.h>
#include <stdlib.h>
int failed=0;
struct node
{
    struct node *next;
    struct node *prev;
    char data;
};
struct node *createnode(char data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}
struct node *insertnodeafter(struct node **head, char data)
{
    struct node *newnode = createnode(data);
    if (*head == NULL)
    {
        *head = newnode;
        return *head;
    }
    struct node *temp = *head;
    while (temp->next)
    {
        temp = temp->next;
    }
    newnode->prev = temp;
    temp->next = newnode;
    return *head;
}
struct node *insertnodeback(struct node **head, char data)
{
    struct node *newnode = createnode(data);
    if (*head == NULL)
    {
        *head = newnode;
        return *head;
    }
    struct node *temp = *head;
    temp->prev = newnode;
    newnode->next = temp;
    *head = newnode;
    return *head;
}
void printnodes(struct node **head1,struct node ** head2)
{
    struct node *pcrawl1 = *head1;
    struct node *pcrawl2 = *head2;
    while (pcrawl1 && pcrawl2)
    {
        if(pcrawl2->data!=pcrawl1->data)
        {
            failed=1;
        }
        pcrawl2 = pcrawl2->next;
        pcrawl1 = pcrawl1->next;
    }
}

int main()
{
    int count;
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        char c;
        scanf(" %c ", &c);

        head1 = insertnodeafter(&head1, c);
        head2 = insertnodeback(&head2, c);
    }
    printnodes(&head1,&head2);
    if(failed==1)
    {
        printf("NOT A PALINDROME");
    }
    else
    {
        printf("PALINDROME");
    }
    
}