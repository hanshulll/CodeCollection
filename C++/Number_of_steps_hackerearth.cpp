//Number of steps
//Basic Programming> Input/Output> Basics of Input/Output

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;scanf("%d",&n);
    int a[n],b[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    int s=a[0];
    for(int i=0;i<n;i++) {
        scanf("%d",&b[i]);
    }
    for(int i=0;i<n;i++) {
        if(a[i]<s) {
            s=a[i];
        }
    }
    int count=0,f=0;
    for(int i=0;i<n;i++) {
        while(s<a[i] && b!=0) {
            a[i]-=b[i];
            count++;
        }
        if(a[i]<s) {
            s=a[i];i=-1;
        }
        if(a[i]<0){
            f=1;
            break;
        }
    }
    if(f==1)
    cout<<"-1";
    else
    cout<<count;
}