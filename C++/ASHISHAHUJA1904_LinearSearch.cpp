#include <iostream>
using namespace std;
 
int linearsearch(int array[],int size,int element){
    int f=0;
    for(int i=0;i<size;i++){
        if(array[i]==element){
            f++;
        }
    }
    if(f==0){
        cout<<"Not Found!!!";
    }
    else{
        cout<<"Found!!!";
    }
    return 0;
} 
int main()
{
    int element,array[]={1,34,56,78,89,23,83,28,90,37};
    cout<<"Enter the element you want to search:";
    cin>>element;
    int size=sizeof(array)/sizeof(array[0]);
    linearsearch(array,size,element);
    return 0;
}