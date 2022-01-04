#include<bits/stdc++.h>
using namespace std;
class node{
public:
     int data;
     node* next;
     
     node(int d){
          data = d;
          next = NULL;
     }
};
void insertAtHead(node * &head,int data){
     node * n = new node(data);
     n->next = head;
     head = n;
}
void insertAtTail(node*&head, int data){
     node * n = new node(data);
     node* temp = head;
     if(head==NULL)
     {
          insertAtHead(head,data);
          return ;
     }
     while(temp->next!= NULL){
          temp = temp->next;
     }    
     temp->next = n;
}
void insertInBet(node*&head,int p, int data){
     node * n= new node(data);
     if(head==NULL || p==0)
     {
          insertAtHead(head,data);
          return;
     }
     p-=2;
     while(p>0){
         head = head->next; 
          p--;
     }
     n->next = head->next;
     head->next = n;
}

node* merge(node* head1, node* head2){
     node * a = head1;
     node * b = head2;
     node * c = NULL;
     if(b==NULL)
     {
          return a;
     }
     else if(a==NULL){
          return b;
     }
     
     if(a->data < b->data){
          c = a;
          c->next = merge(a->next,b);
     }
     else{
                    c = b;
          c->next = merge(a,b->next);
     }
     
     return c;
}


void print(node * head){
     while(head !=NULL){
          cout<<head->data<<" ";
          head = head->next;
     }
     cout<<endl;
}

int main(){
     
     int t;
     cin>>t;
     while(t>0){
     int n1,n2,x;
     cin>>n1;
     node * head1 = NULL;
     for(int i=0;i<n1;i++)
     {
          cin>>x;
          insertAtTail(head1,x);
     }
     cin>>n2;
     node * head2 = NULL;
     for(int i=0;i<n2;i++){
          cin>>x;
          insertAtTail(head2,x);
     }
    node* head =  merge(head1,head2);
     print(head);
     t--;
     }
}
