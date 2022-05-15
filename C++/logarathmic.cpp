//code to calculate powers using recursion
#include <iostream>
using namespace std;
int power(int n,int x){
    if(x==0){
        return 1;
    }
    if(x==1){
        return n;
    }
    int c=power(n,x/2);
    return x%2==1?n*c*c:c*c;
}
int main() {
    int n,x=0;
    cin>>n>>x;
    cout<<power(n,x);
}

