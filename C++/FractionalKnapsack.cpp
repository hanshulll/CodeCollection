#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
//maximum total weight using value in the knapsack with fractional items

using namespace std;

bool sortinrev(const pair<int,int> &a,const pair<int,int> &b) 
{ 
       return (a.second > b.second); //sort in value comparisons
} 
int main(){
vector< pair <int,int> > a;
int x,y,n,w,v;
int cw = 0;
double finval = 0.0;
	cout<<"\nenter the number of items:";//take list of items
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"enter item weight "<<i+1<<" :\n";
		cin>>x;
		cout<<"enter item value "<<i+1<<" :\n";
		cin>>y;
		a.push_back(make_pair(x,y));
		
	}
	cout<<endl;
	sort(a.begin(), a.end(),sortinrev);
	cout<<"Item weight Item value"<<endl;
	for (int i=0; i<n; i++)
    {
        // 1st and 2nd element of pair respectively
        cout << a[i].first <<"\t\t"<< a[i].second << endl;
    }
	cout<<"\nenter the size of the knapsack: ";
	cin>>w;
	int j=0;	
	for (int i = 0; i < n; i++) {
        // If adding Item won't overflow, add it completely
        if (cw + a[i].first <= w) 
        {
            cw += a[i].first;
            j+=a[i].first;
            finval += a[i].second;
            cout<<"item number with weight "<<a[i].first<<" entered"<<endl;
        }
 
        // If we can't add current Item, add fractional part of it
        else {
            int r = w - cw;
            double z;
            z=a[i].first * ((double)r/(double)a[i].first);
            j+=z;//max weight
            finval += a[i].second * ((double)r/(double)a[i].second);//max val/profit
            cout<<"item number with  "<<z<<" of weight "<<a[i].first<<" entered"<<endl;
            break;
        }
    }
    cout << "\n profit is - " << finval;
    cout << "\n max weight is - " << j;
    
}

	
	
	
	
	
	
	