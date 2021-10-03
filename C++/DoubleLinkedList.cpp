#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

void append(Node **head, int new_data)
{
    Node *new_node=new Node();
    Node *last=*head;

    new_node->data=new_data;

    new_node->next=NULL;

    if(*head==NULL)
    {
        new_node->prev=NULL;
        *head=new_node;
        return;
    }

    while(last->next!=NULL)
    {
        last=last->next;
    }
    
    last->next=new_node;

    new_node->prev=last;
}

void storeFront(Node **head, int new_data)
{
    Node *new_node= new Node();
    new_node->data=new_data;
    new_node->next=(*head);

    (*head)->prev=new_node;

    new_node->prev=NULL;
    *head=new_node;
}

void insertAfter(Node **prev_node,int new_data)
{
    Node *new_node=new Node();
    new_node->data=new_data;

    new_node->next=(*prev_node)->next;
    (*prev_node)->next->prev=new_node;

    (*prev_node)->next=new_node;
    new_node->prev=(*prev_node);
    
}


void printLL(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

void delNode(Node **head,Node *pt)
{
    Node *prevv=pt->prev;
    Node *nexxt=pt->next;

    pt->prev=NULL;
    pt->next=NULL;

    prevv->next=nexxt;
    nexxt->prev=prevv;
    free(pt);
}


int main()
{
    Node *head=NULL;

    append(&head,1);

    append(&head,2);

    storeFront(&head,100);

    insertAfter(&head->next,20);

    printLL(head);

    delNode(&head,head->next);

    printLL(head);

}
