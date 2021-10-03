//    C program for infix to postfix conversion(problem statement)
//    using implementation of stack
//    stack has been implemented using linked list(chain of nodes)

//	example input for infix: a+(b+c*d)-e/f+(g-h)/i
//	corresponding output: +-+a+b*cd/ef/-ghi
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	//include all required headers

typedef struct node{
	char data;
	struct node * next;	//define a structure node as a single entity to form the stack
}node;
node * head=NULL;		//initially head of the stack points nowhere(NULL)
char pop();
int isEmpty(node * head);		//Function declarations 
int inpriority(char a);			//Function defination below the main function
int outpriority(char a);
node * push(char a,node * head);
node * create(char a);
void display(node *head);
int main(){				//main function starts
	node* ans=NULL;
	char a[100];
	printf("Enter your infix expression\nNOTE: Please dont give any space in between characters\n");   
	//single input is taken for infix expression in array
	//Don't provide any space in infix expression
	//input a valid infix expression  eg:a+(b+c*d)-e/f+(g-h)/i
	scanf("%s",a);
	int n=strlen(a);
	for(int i=n-1;i>=0;i--){			//traverse the infix expression from end
		if(a[i]=='('){ 				//if character is opening bracket, pop out elements from stack and add popped one to answer until you get closing bracket 
			while(head->data!=')'){
				ans=push(pop(),ans);
			}
			pop();
		}
		else if(a[i]==')')head=push(a[i],head);		//push into stack in case of closing bracket
		else if(outpriority(a[i])==0) ans=push(a[i],ans);	//push in case of operands like a,b,c,A,B,C (single character only)
		else if(isEmpty(head)  || inpriority(head->data)<outpriority(a[i])){head=push(a[i],head);}	//push to stack in case of higher priority element than the stack top
		else{

			while( (!isEmpty(head)) && inpriority(head->data)>outpriority(a[i]) ){
				ans=push(pop(),ans);						//pop out in case of lower priority element till you get a lower priority at stack top
				}
				head=push(a[i],head);
			}
	}
	while(!isEmpty(head)){
				ans=push(pop(),ans);			//empty the remaining stack 
			}
	printf("ansr\n");
	display(ans);		//print answer (corresponding prefix expression)

	return 0;
}
node * create(char a){			//function to create a single node entity for stack(chain of nodes)
	node * newd=(node *)malloc(sizeof(node));
	if(newd==NULL){printf("Stack overflow\n");return newd;}	
	newd->data=a;
	return newd;
}
node * push(char a,node * head){	//push an element to the specified stack top
	node * newd=create(a);
	newd->next=head;
	return newd;
}
int inpriority(char a){			//priority function when character is present inside stack
	if(a=='^') return 6;
	else if(a=='*' || a=='/' || a=='%') return 3;
		else if(a=='+' || a=='-') return 1;
			else return 0;
}
int outpriority(char a){		//priority function when character is present outside stack
	if(a=='^') return 5;
	else if(a=='*' || a=='/' || a=='%') return 4;
		else if(a=='+' || a=='-') return 2;
			else return 0;
}					//for left to right associativity(+,-,*,/) of same element outpriority>inpriority
					//for right to left associativity(^) of same element outpriority<inpriority

int isEmpty(node * head){		//fuction to check stack is empty or not
	if(head==NULL) return 1;
	else return 0;
}
char pop(){				//pop an element out of the stack 
	if(head==NULL){printf("stack underflow\n");return -1;}
	char data=head->data;
	node * garbage=head;
	head=head->next;
	free(garbage);
	return data;
}
void display(node * head){		//print all the elements present inside the stack  
	if(head==NULL)return;
	printf("%c",head->data);
	display(head->next);

}