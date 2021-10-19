#include<bits/stdc++.h>
using namespace std;
int top;

void push(int *stack,int n)
{
   int num;
   if (top < n-1)
   {
    cout<<"Enter the value you want to push : ";
    cin>>num;   
    stack[++top] = num;
   }
   
   else 
   cout<<"Overflow!! Can't push any more value.";
    
}

void pop(int *stack)
{
    if (top==-1)
     cout<<"Underflow!! Can't pop value.";
     
    else
    {
        top--;
        cout<<"Popped !\n";
    }
}

void traverse(int *stack)
{
    if (top==-1)
    cout<<"Stack is Empty.";

    else 
    {
        for (int i=0;i<=top;i++)
            cout<<stack[i];
    }
    cout<<"\n";
}

void main()
{
    int n,ch,k;
    cout<<"\nManav Naharwal 05316401519\n\n";
    cout<<"Enter the Size of your Stack -- : ";
    cin>>n;
    int stack[n];    
    top=-1;

    while(1)
    {
       cout<<"\n\nWhat do you want to do :";
       cout<<"\n1.Traverse\n2.Push\n3.Pop\n4.Exit\n";
       cin>>k;

       switch (k)
      {
        case 1:
            traverse(stack);
            break;
    
        case 2:
            push(stack,n);
            break;
    
        case 3:
            pop(stack);
            break;

        case 4:
            exit(0);

        default:
           cout<<"You entered wrong input ! Try Again..";
           break;       
      }
    } 
}
