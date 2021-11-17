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
	int n,q;
	cin>>n>>q;
	int sum[n+1];
	int i;
	sum[0]=0;
	for(i=1;i<=n;i++){
	    int c1;
	    cin>>c1;
	    if(c1==3 || c1==4 || c1==6){
	        sum[i]=sum[i-1]+1;
	    }
	    else{
	        sum[i]=sum[i-1];
	    }
	}
	for(i=1;i<=q;i++){
	    int l,r;
	    cin>>l>>r;
	    cout<<sum[r]-sum[l-1]<<endl;
	}
	return 0;
}

