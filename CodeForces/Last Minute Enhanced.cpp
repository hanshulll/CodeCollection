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
    #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		map<int,int>mp;
		for(int i=0;i<n;i++)
		{
			if(arr[i]==arr[i+1])
			{
				arr[i+1]++;
			}
			mp[arr[i]]++;
		}
		for(int i=0;i<n;i++)cout<<arr[i]<<" ";
		int cnet=0;
		for(int i=0;i<n;i++)
		{
			if(mp[arr[i]])
			{
				cnet++;
			}
		}
		cout<<cnet<<endl;


	}

	return 0;
}
