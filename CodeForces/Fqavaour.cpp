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
		ll n,i;
		cin>>n;
        ll arr[n],brr[n]={},j=0;
		ll s=0;
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		for(i=0;i<n;i++)
		{
			brr[j++]+=arr[i];
			brr[j++]+=arr[n-i-1];
		}
		for(i=0;i<n;i++)
        {
            cout<<brr[i]<<" ";
        }
        cout<<endl;


	}

	return 0;
}

