// N Queens
#include <iostream>
using namespace std;

int n;
int ans = 0, DONE;

int getPosition(int n){
    int ans=0;
    while(n>0){
        ans++;
        n = n >>1;
    }
    return ans-1;
}

int board[100][100] = {0};

void solve(int rowMask,int ld,int rd,int row){
    
    if(rowMask==DONE){ 
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
        ans++; 
        return; 
    }
    
    int safe = DONE & (~(rowMask|ld|rd));
    
    while(safe){
        int p = safe & (-safe);
        //p will give you the column
        int col = getPosition(p);
        board[row][col] = 1;
        
        safe = safe - p;
        solve(rowMask|p, (ld|p)<<1,(rd|p)>>1,row+1);
        board[row][col] = 0;
    }
}

int main() {
   cout<<"Enter value of N: "; 
   cin>>n;
   DONE = ((1<<n)) - 1;
   
   solve(0,0,0,0);
   cout<<ans<<" ways"<< endl;
}
