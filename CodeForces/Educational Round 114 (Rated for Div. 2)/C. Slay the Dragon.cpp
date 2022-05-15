#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef SOLUTION
#define debug(x) cerr << #x <<" "; _print(x); cerr <<endl;
#else
#define debug(x)
#endif

const long long big = 1e18L + 5;
int cnt = 1;
void slay_the_dragon()
{
  ll n,x,y;
  cin>>n;
  vector<ll> vector_l(n);
  for(int i=0;i<n;i++)
  {
  cin>>vector_l[i];
  }
  sort(vector_l.begin(),vector_l.end());
  vector<ll> pre = vector_l;
  for(int i=1;i<n;i++)
  {
  pre[i]+=pre[i-1];
  }
  ll t_1;
  cin>>t_1;
  while(t_1--)
  {
    cin>>x>>y;
    ll position = std::lower_bound(vector_l.begin(),vector_l.end(),x) - vector_l.begin();
    ll answer = big;
    if(position==n)
      answer = x - vector_l[position-1]+max(ll(0),y -pre[n-1]+vector_l[position-1]);
    else if(position!=0)
      answer = min(max(ll(0), x -vector_l[position]) + max(ll(0),y- pre[n-1] + vector_l[position]), max(ll(0) , x - vector_l[position-1])+max(ll(0),y- pre[n-1]+vector_l[position-1]));
    else
      answer = max(ll(0),x- vector_l[position])+max(ll(0),y-pre[n-1]+vector_l[position]);
    cout<<answer<<endl;
  }

 
}
int main()
{
#ifdef SOLUTION
freopen("Error.txt","w",stderr);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--)
    {
        slay_the_dragon();
        cnt++;
    }
    return 0;
}