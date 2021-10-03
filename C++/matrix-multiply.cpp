#include <iostream>
using namespace std;
int main() {
    int i,j;
    int a,b,c,d;
    cout<<"Enter dimensions of matrix 1"<<endl;
    cin>>a>>b;
    cout<<"Enter dimensions of matrix 2"<<endl;
    cin>>c>>d;
    if(b==c)//column of matrix 1 should be equal to row of matrix 2
    {
        int x[a][b];
        int y[c][d];
        cout<<"Enter values of matrix 1"<<endl;
        for(i=0;i<a;i++){
            for(j=0;j<b;j++)
            {
            cout<<"Enter value for index "<<i<<j<<endl;
            cin>>x[i][j];
            }
        }
        cout<<"Enter values of matrix 2"<<endl;
         for(i=0;i<c;i++){
            for(j=0;j<d;j++)
             {
            cout<<"Enter value for index "<<i<<j<<endl;
            cin>>y[i][j];
             }
        }
        int z[a][d];
        
         for(i=0;i<a;i++){
            for(j=0;j<d;j++){
             z[i][j]=0;
             for(int k=0;k<d;k++){
             z[i][j]+=x[i][k]*y[k][j];
        }}}
         for(i=0;i<a;i++){
            for(j=0;j<d;j++)
            cout<<z[i][j]<<" ";
            cout<<endl;
        }
    }
    else
    cout<<"Matrix can not be multiplied";

    return 0;
}