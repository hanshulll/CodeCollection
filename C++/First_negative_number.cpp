#include<bits/stdc++.h>
using namespace std;

void fun(int a[],int n,int k)
{
    queue<int> q;
    vector <int> v;
    int i=0,j=0;
    while(j<n)
    {
        if(a[j]<0)
            q.push(a[j]);
        if(j-i+1<k)
            ++j;
        else if((j-i+1)==k)
        {
            if(q.empty()) 
		v.push_back(0);
            else{
                v.push_back(q.front());
                if(a[i]==q.front())
                     q.pop();  }
            ++j,++i;
        }
    }
    for(i=0;i<v.size();++i)
        cout<<v[i]<<" ";
}
int main()
{
    int n,k,i=0,j; cin>>n>>k;
    int a[n];
    for(i=0;i<n;++i) cin>>a[i];
    fun(a,n,k);
    return 0;
}
