//insert at head
#include<iostream>
using namespace std;

class Node
{
    int data;
    Node * next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void Insert_At_head(Node *head ,int val)
{
    Node *newnode = new Node(val);
    newnode->next = head;
    head = newnode;
}
void Insert_At_Tail(Node *head ,int val)
{
    Node *newnode = new Node(val);
    if(head==NULL)
    {
        head = newnode;
        return;
    }

    Node * temp = head;
    while(temp->next!=NULL){
    temp = temp->next;
    }
    temp->next = newnode;
}

void display(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main()
{
    Node *head = NULL;
    Insert_At_Tail(head,1);
    Insert_At_Tail(head,2);
    Insert_At_Tail(head,3);
    display(head);
    Insert_At_head(head,4);
}
