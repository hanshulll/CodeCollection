#include<bits/stdc++.h>
using namespace std;
                 //Welcome To Hridoy's Code
#define   ll                  long long int
#define   ull                 unsigned long long
#define   pb                  push_back
#define   p                   push
#define   em                  emplace_back
#define   ff                  first
#define   ss                  second
#define   endl                "\n"
#define   all(v)              (v.begin(),v.end())
#define   rall(v)             (v.rbegin(),v.rend())
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
	stack<ll>st;
	while(t--)
	{
		
		ll n;
		cin>>n;
		if(n==1)
		{
			ll m;
			cin>>m;
			st.p(m);
		}
		else if(n==2)
		{
			if(!st.empty())
			{
				st.pop();
			}
			
		}
		else if(n==3)
		{
			if(!st.empty())
			{
				cout<<st.top()<<endl;
			}
			else
			{
				cout<<"Empty!"<<endl;
			}
		}	

	}

	return 0;
}
