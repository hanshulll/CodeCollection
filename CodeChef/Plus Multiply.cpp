#include<bits/stdc++.h>
using namespace std;
                 //Welcome To Hridoy's Code
#define   ll                  long long
#define   ull                 unsigned long long
#define   pb                  push_back
#define   em                  emplace_back
#define   ff                  first
#define   ss                  second
#define   endl                "\n"
#define   all(v)              (v.begin(), v.end())
#define   rall(v)             (v.rbegin(), v.rend())
#define   pi                  acos(-1.0)
#define   LCM(LCM_X,LCM_Y)    (LCM_X/__gcd(LCM_X,LCM_Y))*LCM_Y
#define   FastRead   ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int MOD = (int)1e9+7;
const int MAX = 1e6;
int main()
{
    FastRead
    int t;
    cin>>t;
    while(t--)
    {
    	ll n,cnet=0,cnet1=0,ans=0;
    	cin>>n;
    	int arr[n+1];
    	for(int i=0;i<n;i++)cin>>arr[i];
    	for(int i=0;i<n;i++)
    	{
    		if(arr[i]==2)cnet++;
    		else if(arr[i]==0)cnet1++;
    	}
    	ans+=(cnet1*(cnet1-1)/2);
    	ans+=(cnet*(cnet-1)/2);

    	cout<<ans<<endl;
    }

	return 0;
}
