
// This program uses simple searching to find 
// an element in the linked list 
// through iteration


#include<iostream>
using namespace std;
class node
{
  public:
  int data;
  node* next;

};
//Display function

void display(node *& head)
{
  node* temp=head;
  while(temp->next!=NULL)
  {
    cout<<temp->data<<"->";
    temp=temp->next;
  }
  if(temp->next==NULL)
  cout<<temp->data<<"->NULL";
}

//This function inserts nodes at the back of
// the linked list;

void pushinsert(node *&head ,int val)
{
  node* newnode=new node;
  node* temp=head;

  newnode->data=val;
  newnode->next=NULL;
  if(head==NULL)
  {
    head=newnode;
    return;
  }

  while(temp->next!=NULL)
  {
    temp=temp->next;
  }
    temp->next=newnode;
  return;
}

//this function returns true 
// if the elemnt is found

bool search(node *&head ,int val)
{
  node* temp=head;
  while(temp!=NULL)
  {
    if(temp->data==val)
      return true;
      temp=temp->next;
  }
  return false;
}

//DRIVER CODE
int main()
{
  int n;
  cout<<"Enter size:";
  cin>>n;
  node *llist=NULL;
  cout<<"Enter the elements: ";
  for(int i=0;i<n;i++)
  {
    int v;
    cin>>v;
    pushinsert(llist,v);
  }
  cout<<"Enter element to search for:";
  int k;cin>>k;
  if(search(llist,k))
  cout<<"ELEMENT FOUND";
  else
  cout<<"ELEMNT NOT FOUND";
}
