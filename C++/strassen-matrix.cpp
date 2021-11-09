#include<iostream>
using namespace std;
int main(){
  int a[2][2],b[2][2],c[2][2];
  int p,q,r,s,t,u,v;
  int c1,c2,c3,c4;
cout<<"enter the matrix of a";
for(int i=1;i<=2;i++){
  for(int j=1;j<=2;j++){
    cin>>a[i][j];
  }
}

cout<<"enter the matrix of b\n";
for(int i=1;i<=2;i++){
  for(int j=1;j<=2;j++){
    cin>>b[i][j];
  }
}

p=(a[1][1]+a[2][2])*(b[1][1]+b[2][2]);
q=(a[2][1]+a[2][2])*b[1][1];
r=a[1][1]*(b[1][2]-b[2][2]);
s=a[2][2]*(b[2][1]-b[1][1]);
t=(a[1][1]+a[1][2])*b[2][2];
u=(a[2][1]-a[1][1])*(b[1][1]+b[1][2]);
v=(a[1][2]-a[2][2])*(b[2][1]+b[2][2]);

c[1][1]=p+s-t+v;
c[1][2]=r+t;
c[2][1]=q+s;
c[2][2]=p+r-q+u;
cout<<"the multiplication of matrix\n";
for(int i=1;i<=2;i++){
  for(int j=1;j<=2;j++){
    cout<<c[i][j]<<" ";
  }
  cout<<"\n";
}

return 0;
}
