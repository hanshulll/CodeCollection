//Problem statement
//https://www.hackerrank.com/challenges/encryption/problem



#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    s.erase(remove(s.begin(),s.end(),' '),s.end()); //remove all the spaces.
    int l = s.size();
    int row = sqrt(l);  //typecasting to int will turn it to floor value.
    int column; 
    if(row == sqrt(l))  //if sqrt(l) is proper integer.
        column = row;
    else
        column = row+1;  
    if(row*column<l)
        row++;
    char vec[row][column];
    int it=0;
    for(int i=0;i<row;i++)   //store the string in 2-d vector
    {
        for(int j=0;j<column;j++)
        {
            if(it<l)      
                vec[i][j]=s[it++];
            else              //if we reach the end of string and still there is space in the vector
                vec[i][j]='0';     //add 0 to remove garbage value
        }
    }
    string res;
    for(int i=0;i<column;i++)
    {
        for(int j=0;j<row;j++)    // traverse the vector column-wise
        {
            if(vec[j][i]=='0')    //Ignore the '0' that were put to handle garbage values 
                continue;
            res.push_back(vec[j][i]);
        }
        res.push_back(' ');
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
