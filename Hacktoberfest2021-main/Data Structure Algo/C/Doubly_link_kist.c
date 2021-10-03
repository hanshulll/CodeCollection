#include<stdio.h>
#include<stdlib.h>
struct node
{
  int a;
  struct node *prev,*next;
};
 struct node *header,*last;
 void show();
 void create();
 void insertf();
 void insertl();
 void insertafter();
 void delf();
 void dellast();
 void del();
 void printmid();
 void main(){
   create();
   show();
   printf("\n\n------after inserting value at first position------\n\n");
   insertf();
   show();
   printf("\n\n------after inserting value at last position------\n\n");
   insertl();
   show();
   printf("\n\n------inserting value after a particular value------\n\n");
   insertafter();
   show();
   delf();
   printf("\n\n------list after deletion of first node ------\n\n");
   show();
   dellast();
   printf("\n\n------list after deletion of last node ------\n\n");
   show();
   del();
   printf("\n\n------list after deletion of particular  node ------\n\n");
   show();
   printf("\n-----------------------------\n");
   printmid();



 }
 void create(){
   int ch;
   struct node *temp;
   temp =malloc(sizeof(struct node));
   printf("\nenter the value \n");
   scanf("%d",&temp->a);
   temp->prev=temp->next=NULL;
   header=last=temp;
   printf("\nwant to create more node\n");
   scanf("%d",&ch);
   while(ch)
   { temp =malloc(sizeof(struct node));
    printf("\nenter the value \n");
    scanf("%d",&temp->a);
    last->next=temp;
    temp->prev=last;
    temp->next=NULL;
    last=temp;
    printf("\nwant to create more node\n");
    scanf("%d",&ch);
   }
 }
 void show(/* arguments */) {
   /* code */
   struct node *temp=header;
   while(temp!=NULL){
     printf("-->%d",temp->a);
     temp=temp->next;

   }
   printf("\n now in backward direction\n");
   temp=last;
   while(temp!=NULL){
     printf("-->%d",temp->a);
     temp=temp->prev;

   }

 }
void insertf(){
  struct node *temp=malloc(sizeof(struct node));
  printf("\nenter the data you want to insert\n");
  scanf("%d",&temp->a);
  temp->prev=NULL;
  temp->next=header;
  if(header!=NULL){
    header->prev=temp;

  }
  header=temp;
}
void insertl(){
  struct node *temp=malloc(sizeof(struct node));
  printf("\nenter the data you want to insert\n");
  scanf("%d",&temp->a);
  if(header==NULL){
    header=last=temp;
    temp->prev=temp->next=NULL;
    return;
  }
  else{
    last->next=temp;
    temp->prev=last;
    last=temp;
    temp->next=NULL;
  }
}
void insertafter(/* arguments */) {
  /* code */
  int val;
  struct node *temp=malloc(sizeof(struct node)),*temp1=header;
  printf("\nenter the data you want to insert\n");
  scanf("%d",&temp->a);
  if(header==NULL){
    printf("insetion not possible\n");
  }
  printf("\nenter the value after which you want to insert\n");
  scanf("%d",&val);
  while(temp1!=NULL){
    if(temp1->a==val){
      temp->next=temp1->next;
      temp1->next=temp;
      temp->prev=temp1;
      if(temp1!=last){
        temp->next->prev=temp;
        return;
      }
      last=temp;
      return;
    }
    temp1=temp1->next;
  }
  printf("\nelemet not found\n");
}
void delf(){
  if(header==NULL){
    printf("\n underflow situation\n");
    return;
  }
  if(header->next==NULL){
    header=last=NULL;
    return;
  }
  header=header->next;
  header->prev=NULL;
}
void dellast(/* arguments */) {
  /* code */
  if(header==NULL){
    printf("\n underflow situation\n");
    return;
  }
  if(header->next==NULL){
    header=last=NULL;
    return;
  }
  last=last->prev;
  last->next=NULL;
}
void del(){
  int val;
  struct node*temp=header;
  if(header==NULL){
    printf("\n underflow situation\n");
    return;
  }
  printf("\nenter the value which you want to delete\n");
  scanf("%d",&val);
  if(val==header->a){
    delf();
    return;
  }
  while(temp->next!=NULL){
    if(val==temp->a){
      temp->prev->next=temp->next;
      temp->next->prev=temp->prev;
      return;
    }
    temp=temp->next;
  }
 if(val==last->a){
 dellast();
  return;
  }
  printf("\nelemet not found\n");

}
void printmid(){
  struct node *temp1,*temp;
  temp1=temp=header;
  while(temp1!=NULL && temp1->next!=NULL ){
    temp=temp->next;
    temp1=temp1->next->next;
  }
    printf("-->%d",temp->a);
}
