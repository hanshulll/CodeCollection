#include<stdio.h>
#include <stdlib.h>
struct node
{
  int a;
  struct node *p;
};
struct node *header,*last;
void create(int);
void show();
void deletion1();
void dellast();
void del();

void main() {
  /* code */
  create(10);
  create(20);
  create(30);
  create(40);
  create(50);
  create(100);
  printf("link list is:\n");
  show();
  deletion1();
  printf("\n\nlist after first node deletion\n\n");
  show();
  dellast();
  printf("\n\nlist after last deletion\n\n");
  show();
  del();
  printf("\n\nlist after deletion particular element\n\n");
  show();
}

void create(int e)
{
  struct node *temp;
  temp=malloc(sizeof(struct node));
  temp->a=e;
  temp->p=NULL;
  if(header==NULL){
    header=last=temp;
    return;
  }
  else
  {
    last->p=temp;
    last=temp;
  }
return ;
}
void show(){
  struct node *temp=header;
  while(temp!=NULL){
    printf("-->%d",temp->a);
    temp=temp->p;
  }
}
void deletion1(){
  if(header==NULL){
    printf("deletion is not possible\n");
  return;
  }
  header=header->p;
  return;
}
void dellast(){
  struct node *temp=header,*prev;
  while(temp->p!=NULL)
{
  prev=temp;
  temp=temp->p;
}
prev->p=NULL;
}
void del()
{
  int val;
  struct node *temp=header,*prev;
  printf("\nenter the value you want to delete\n");
  scanf("%d",&val);
  while(temp!=NULL){
    prev=temp;
    temp=temp->p;
    if(temp->a==val){
    if(temp==header){
      header=header->p;
      return;
    }
    else
    {
      prev->p=temp->p;
      return;
    }
  }
}
}
