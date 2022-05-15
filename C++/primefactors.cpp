#include<iostream>
using namespace std;
int top=-1;
void push(int a[],int n,int x)
{if(top==n-1)
   {cout<<"Stack overflow\n";

   }
   else
   {top++;
     a[top]=x;

   }

}
void pop(int a[],int n)
{if(top==-1)
   cout<<"Empty\n";
   else
   {top--;
     cout<<"Deleted\n";

   }

}
void disp(int a[])
{for(int i=0;i<=top;i++)
   cout<<a[i]<<" ";

}
void prime(int a[],int n,int x)
{for(int i=2;i<x;i++)
   {int f=1;
       for(int j=2;j<i;j++)
       {if(i%j==0 && i!=j)
           {f=-1;
                break;
           }

       }
       if(f==1 && x%i==0)
        push(a,n,i);

   }

}
int main()
{int a[50];
     int x;
  cout<<"Enter the number\n";
  cin>>x;

  prime(a,50,x);
  cout<<"All the prime factors are : ";
  disp(a);

}
