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
    int n,no,pno,score,sum=0,i,j;
    cin>>n;
    int arr[9]={0};
    
    for(i=1;i<=n;i++)
    {
        cin>>no;
        for(j=1;j<=no;j++)
        {
            cin>>pno;
            cin>>score;
            
            if(pno<=8&&score>arr[pno])
            {
                arr[pno]=score;
            }
        }
        for(j=1;j<=8;j++)
        {
        sum=sum+arr[j];
        arr[j]=0;
        }
        cout<<sum<<endl;
        sum=0;
    }
    return 0;
}


	

