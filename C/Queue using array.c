#include<stdio.h>
#include<stdbool.h>
#define max 50

int front= -1;
int rear = -1;
int Queue[max];

bool isfull(int size) {
 if(rear ==( size - 1))
    return true;
 else
    return false;
}

bool isempty() {
 if (rear < 0 || front >= rear)
    return true;
 else
    return false;
}

void enqueue(int queue[] ,int size){

    if(isfull(size)){
        printf("Queue is full");
    }
    else
    {
    int item;
    printf("Enter the value to be inserted :");
    scanf("%d",&item); 
    rear++;
	queue[rear] = item;
    printf("%d is added to Queue",item);
        
    }
}

void dequeue(int queue[]){
     if(!isempty()){
            ++front;
            int data=queue[front];
            printf("The dequeued value is %d\n",data);
            
            
        }else{
            printf("The Queue is empty\n");
        }
    
}
void display(int queue[]){
    int i;
    if(isempty()){
        printf(" Queue is empty");
        
    }
    else {
        printf("Elements in the queue:\n");
        for(i=front+1;i<rear+1;i++){
            printf("%d\t",queue[i]);
        }
    }
}

int main(){

   
    int choice,x,size;
    printf("Enter the size of the queue:");
    scanf("%d",&size);
    
    do{
        printf("\nEnter the choice of function you want to perform: 1:enqueue 2:dequeue 3:display 4:exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1 :enqueue(Queue,size);
                    break;
            case 2 :dequeue(Queue);
                    break;
            case 3: display(Queue);
                    break;
            case 4 :printf("existing from the queue operation");
                    break;
            
            default: printf("invalid choice");
            
                    
        }
    }
    while(choice!=4);
    return 0;
    
    
}