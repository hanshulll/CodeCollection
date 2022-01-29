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
	
		int i,k=0,j,carry=0,arr[1000]={1},n;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<=k;j++)
             {
                arr[j]=arr[j]*i+carry;
                carry=arr[j]/10;
                arr[j]=arr[j]%10;
             }
             while(carry)
             {
                 k++;
                 arr[k]=carry%10;
                 carry/=10;
             }
         }
         for(int i=k;i>=0;i--)
         {
         	cout<<arr[i];
         }
         cout<<endl;

	return 0;
}
