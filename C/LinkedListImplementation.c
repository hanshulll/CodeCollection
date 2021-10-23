#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE *head=NULL;
NODE *end=NULL;

void create( int data){
    NODE *temp;
    temp =(NODE*)malloc(sizeof(NODE));
    temp->data=data;
    if(head==NULL){
        head=temp;
        end=temp;
    }
    else{
        end->next=temp;
        end=temp; 
        temp->next=NULL;
        
    }
}
void display(){
    NODE *temp;
    temp = head;
    while(temp!=NULL){
        printf("%d", temp->data);
          printf(" \n");
        temp=temp->next;
    }
}

int main(){
    int n;
    printf(" Enter the number of nodes in list:");
     scanf(" %d", &n);
     for(int i=0; i<n; i++){
         int data;
         scanf("%d", &data);
         create(data);
     
}
 
         display();
   

return 0; 
}
