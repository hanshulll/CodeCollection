#include <bits/stdc++.h>
using namespace std;

int majorityElement(int a[], int size)
    {
        
      int index=0,count=1;
      for(int i=1;i<size;i++){
          if(a[index]==a[i])
          count++;
          else
          count--;
          if(count==0){
              index=i;
              count=1;
          }
      }
      count=0;
      for(int i=0;i<size;i++){
          if(a[i]==a[index])
          count++;
      }
      if(count>size/2)
      return a[index];
      else
      return -1;
    }

int main(){
int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
  cin>>a[i];
  }
  
  int ans=majorityElement(a,n);
  cout<<ans;
}
