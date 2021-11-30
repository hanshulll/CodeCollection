 #include <iostream>
using namespace std;
int main()
{  
    int t;
    cin>>t;
    while(t--)
    {  
    int n,k;
    cin>>n>>k; 
    int ans=(2*n-k-1)/2; 
    cout<<2*ans<<endl;
    }
    return 0;

}
