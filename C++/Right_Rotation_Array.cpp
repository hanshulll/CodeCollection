//SAKSHAM JAIN   ############################
#include<bits/stdc++.h>
using namespace std;
void reverse(vector<int> &v,int start,int end)
{
	int temp=0;
	while(start<end)
	{
		swap(v[start],v[end]);
		start++;
		end--;
	}
}
void rightRotaion(vector<int> &v,int n,int k)
{
    if(k==0)
        return;
    k=k%n;
    reverse(v,0,n-1);
	reverse(v,0,k-1);
    reverse(v,k,n-1);
}
int main()
{
    int n;
    cout<<"Enter no. of elements:"<<endl;
    cin>>n;
    vector<int> v(n);
    cout<<"Enter elements:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int k;
    cout<<"Enter no. of rotations to perform:"<<endl;
    cin>>k;
    rightRotaion(v,n,k);
    cout<<"Output after right rotation:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
