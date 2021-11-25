#include<iostream>
using namespace std;
int main(){
    int n,key,i;
cout<<"size of array: =>";
cin>>n;
int arr[n];
cout<<"enter elements in array";
for (i=0;i<n;i++){
    cin>>arr[i];
}
cout<<"enter position";
cin>>key;
key--;
 

n--;
for(i=key;i<n;i++){
    arr[i]=arr[i+1];

}
 for (i=0;i<n;i++){
    cout<<arr[i]<< "  ";
}
return 0;
}
