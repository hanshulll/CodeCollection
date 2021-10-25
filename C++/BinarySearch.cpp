#include<bits/stdc++.h>
using namespace std;
void binarySearch(long int arr[],long int n,int num)
{
	sort(arr,arr+n);
	long int start,end,mid,count=0;
	start=0;
	end=n;
	
	while(start<end)
	{
		mid=start+(end-start)/2;
		if(num==arr[mid])
		{
			cout<<"Found";
			count++;
			break;
		}
		else if(num<arr[mid])
		{
			end=mid;
		}
		else if(num>arr[mid])
		{
			start=mid+1;
		}
	}
	if(count==0)
	{
		cout<<"Not Found";
	}
}
int main()
{
	
		cout<<"Enter no. of elements:";
		long int n;
		cin>>n;
		cout<<"Enter elements:";
		long int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		cout<<"Enter no. to be searched:";
		int num;
		cin>>num;
		binarySearch(arr,n,num);
	
	return 0;
}
