// Q) In a season, each player has three statistics: runs, wickets,
// and catches. Given the season stats of two players A and B, 
// denoted by R, W, and C respectively, the person who is better 
// than the other in the most statistics is regarded as the better 
// overall player. Tell who is better amongst A and B. It is known 
// that in each statistic, the players have different values.

// Input Format
// The first line contains an integer T, the number of test cases. 
// Then the test cases follow.
// Each test case contains two lines of input.
// The first line contains three integers R1, W1, C1, the stats for player A.
// The second line contains three integers R2, W2, C2, the stats for player B.
// Output Format
// For each test case, output in a single line "A" (without quotes)
// if player A is better than player B and "B" (without quotes) 
// otherwise.

// Constraints
// 1≤T≤1000
// 0≤R1,R2≤500
// 0≤W1,W2≤20
// 0≤C1,C2≤20
// R1≠R2
// W1≠W2
// C1≠C2
// Sample Input 1 
// 3
// 0 1 2
// 2 3 4
// 10 10 10
// 8 8 8
// 10 0 10
// 0 10 0
// Sample Output 1 
// B
// A
// A

// Solution ->
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, r1, w1, c1, r2, w2, c2;
    cin>>t;
    
    while(t--){
        int count=0, mount=0;
        // taking inputs
        cin>>r1>>w1>>c1;
        cin>>r2>>w2>>c2;
        
        // nested if-else conditions
        if(r1 != r2 && w1 != w2 && c1 != c2){
            if(r1>r2){
                ++count;
            }else{
                ++mount;
            }
            
            if(w1>w2){
                ++count;
            }else{
                ++mount;
            }
            
            if(c1>c2){
                ++count;
            }else{
                ++mount;
            }
            
            // using ternary operator to check the condition and assign the result to variable c.
            char c = (count > mount) ? 'A' : 'B';
            cout<<c<<endl;
        }else{
            cout<<-1;
        }
    }
    return 0;
}
