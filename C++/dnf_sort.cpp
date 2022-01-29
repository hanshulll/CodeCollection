#include <bits/stdc++.h>
using namespace std;

//this sorting algorithm is for sorting 0s,1s and 2s
//we have to traverse the whole array or vector
//so the time complexity becomes O(n) 
void dnfsort(vector<int>&v){
   
    int n = v.size();
    //here we will be having three pointers
    //forb iterating through the vector
    int low =0;
    int mid = 0;
    int high = n-1;
    while(mid<=high){
        if(v[mid]==0){
            swap(v[mid],v[low]);
            low++;
            mid++;

        }
        else if(v[mid]==1){
            mid++;
        }
        else{
            swap(v[mid],v[high]);
            high--;
        }
    }
}
int main(){
    cout<<"Enter the size of the vector :";
    int n; cin>>n;
    vector<int> v;
    cout<<"\n";
    cout<<"Enter the vector elemnts :"<<"\n";
    while(n--){
        int x; cin>>x;
        v.push_back(x);
    }

    dnfsort(v);
    cout<<"\n";
    cout<<"Now the sorted vector is : "<<"\n";
    for(int i : v ){
        cout<<i<<" ";
    }

    
    
    return 0;
}