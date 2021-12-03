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

int memoized[2005][2005];

int lcs(int *l1,int *l2, int i,int j){

	if(i==-1)
		return 0;
	if(j==-1)
		return 0;
	if(memoized[i][j]!=-1)
		return memoized[i][j];
	memoized[i][j]=max((1+ lcs(l1,l2,i-1,j-1))*(l1[i]==l2[j]),max(lcs(l1,l2,i,j-1),lcs(l1,l2,i-1,j)));
	return memoized[i][j];
}

int main(){
	FastRead
	int datasets;
	cin>>datasets;  

	while(datasets--){
		int max1=-1;
		int list1[2005],list2[2005];
		int len1,len2;
		int temp;
		int i=0;
		while(cin>>temp && temp!=0){
			list1[i++]=temp;
		}
		len1=i;
		while(1){
			int i=0;
			while(cin>>temp && temp!=0)
			{
				list2[i++]=temp;
			}
			len2=i;
			if(i==0)
				break;

			for(int i=0;i<len1;i++)
				for(int j=0;j<len2;j++)
					memoized[i][j]=-1;

			int result=lcs(list1,list2,len1-1,len2-1);
			max1=max(max1,result);
		}
		cout<<max1<<"\n";
	}
	return 0;
}
