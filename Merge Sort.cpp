#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int l,int r,int mid)
{
	int n1=mid+1-l;
	int n2=r-mid;
	
	int a[n1],b[n2];
	for(int i=0;i<n1;i++)
	{
		a[i]=arr[l+i];
	}
	for(int i=0;i<n1;i++)
	{
		b[i]=arr[mid+1+i];
	}
	
	int i=0,j=0,k=l;
	while(i<n1&&j<n2)
	{
		if(a[i]>b[j])
		{
			arr[k]=b[j];
			j++;
			k++;
		}
		else
		{
			arr[k]=a[i];
			i++;
			k++;
		}
	}
	while(i<n1)
	{
		arr[k]=a[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=b[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[],int l,int r)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		
		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,r);
		
		merge(arr,l,r,mid);
	}
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	mergeSort(arr,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
