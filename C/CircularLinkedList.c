# include <stdio.h>
# include <stdlib.h>
struct cslinklist
{
 int data;
struct cslinklist *next;
};
typedef struct cslinklist node;
node *start = NULL;
int nodectr;
node* getnode()
{
node * newnode;
newnode = (node *) malloc(sizeof(node));
printf("\n Enter data: ");
scanf("%d", &newnode -> data);
newnode -> next = NULL;
 return newnode;
} 
int menu()
{
 int ch;
 
printf("\n 1. Create a list ");
 printf("\n\n--------------------------");
printf("\n 2. Insert a node at beginning ");
printf("\n 3. Insert a node at end");
printf("\n 4. Insert a node at middle");
 printf("\n\n--------------------------");
printf("\n 5. Delete a node from beginning");
printf("\n 6. Delete a node from Last");
printf("\n 7. Delete a node from Middle");
 printf("\n\n--------------------------");
printf("\n 8. Display the list");
 printf("\n 9. Exit");
printf("\n\n--------------------------");
printf("\n Enter your choice: ");
 scanf("%d", &ch);
 return ch;
}
void createlist(int n)
{
 int i;
 node *newnode;
 node *temp;
nodectr = n;
for(i = 0; i < n ; i++)
 {
 newnode = getnode();
 if(start == NULL)
 {
 start = newnode;
 }
 else
 {
 temp = start;
while(temp -> next != NULL)
 temp = temp -> next;
temp -> next = newnode;
 }
 }
newnode ->next = start; /* last node is pointing to starting node */
}
void display()
{
 node *temp;
temp = start;
printf("\n The contents of List (Left to Right): ");
if(start == NULL )
 printf("\n Empty List");
 else
 {
do
 {
printf("%d      ", temp -> data);
temp = temp -> next;
} while(temp != start);
 printf(" X \n");
 }
} 
void cll_insert_beg()
{
node *newnode, *last;
newnode = getnode();
if(start == NULL)
 {
 start = newnode;
newnode -> next = start;
 }
 else
 {
 last = start;
while(last -> next != start)
 last = last -> next;
newnode -> next = start;
 start = newnode;
last -> next = start;
 }
printf("\n Node inserted at beginning..");
 nodectr++;
}
void cll_insert_end()
{
node *newnode, *temp;
newnode = getnode();
if(start == NULL )
 {
 start = newnode;
newnode -> next = start;
 }
 else
 {
 temp = start;
while(temp -> next != start)
temp = temp -> next;
temp -> next = newnode;
newnode -> next = start;
 }
printf("\n Node inserted at end..");
 nodectr++;
}
void cll_insert_mid()
{
node *newnode, *temp, *prev;
int i, pos ;
newnode = getnode();
printf("\n Enter the position: ");
 scanf("%d", &pos);
 temp = start;
 prev = temp;
 i = 1;
 while(i < pos)
 {
 prev = temp;
temp = temp -> next;
 i++;
 }
prev -> next = newnode;
newnode -> next = temp; 
nodectr++;
printf("\n Node inserted at middle..");
 
}
void cll_delete_beg()
{
node *temp, *last;
if(start == NULL)
 {
 printf("\n No nodes exist..");
 
 return ;
 }
 else
 {
last = temp = start;
while(last -> next != start)
 last = last -> next;
start = start -> next;
last -> next = start;
 free(temp);
 nodectr--;
 printf("\n Node deleted..");
 if(nodectr == 0)
 start = NULL;
 }
}
void cll_delete_last()
{
 node *temp,*prev;
if(start == NULL)
 {
 printf("\n No nodes exist..");
 
 return ;
 }
 else
 {
 temp = start;
 prev = start;
while(temp -> next != start)
 {
 prev = temp;
temp = temp -> next;
 }
prev -> next = start;
 free(temp);
 nodectr--;
 if(nodectr == 0)
 start = NULL;
 printf("\n Node deleted..");
 }
} 
void cll_delete_mid()
{
int i = 0, pos;
node *temp, *prev;
if(start == NULL)
 {
 printf("\n No nodes exist..");
  return ;
 }
 else
 {
printf("\n Which node to delete: ");
 scanf("%d", &pos);

 temp=start;
 prev = start;
 i = 0;
while(i < pos - 1)
 {
  prev = temp;
  temp = temp -> next ;
 i++;
 }
prev -> next = temp -> next;
 free(temp);
 nodectr--;
 printf("\n Node Deleted..");
 }
}

int main(void)
{
 int result;
int ch, n;
 
 while(1)
 {
 ch = menu();
 switch(ch)
 {
 case 1 :
 if(start == NULL)
 {
printf("\n Enter Number of nodes to create: ");
 scanf("%d", &n);
 createlist(n);
 printf("\nList created..");
 }
 else
 printf("\n List is already Exists..\n");
 break;
 case 2 :
 cll_insert_beg();
 break;
 case 3 :
 cll_insert_end();
 break;
 case 4 :
 cll_insert_mid();
 break;
 case 5 :
 cll_delete_beg();
 break;
 case 6 :
 cll_delete_last();
 break;
 case 7 :
 cll_delete_mid();
 break;
 case 8 :
 display();
 break;
 case 9 :
 exit(0);
 }
 
 }
} 
