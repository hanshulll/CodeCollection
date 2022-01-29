//link to the problem:https://leetcode.com/problems/xor-operation-in-an-array/
class Solution {
public:
    int xorOperation(int n, int start) {
        int x=0,i=0;
        while(n>0){
            x=x^(start+2*i);
            i++;
            n--;
        }
        return x;
    }
};
