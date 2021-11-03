/*
Solution for Happy Number problem (Leetcode): https://leetcode.com/problems/happy-number/
*/
class Solution {
public:
    int sqOfDigits(int n) {
        int prod = 0;
        while (n) {
            int r = n % 10;
            prod += r * r;
            n /= 10;
        }
        return prod;
    }
    
    bool isHappy(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        unordered_set<int> cycle;
        while (n != 1) {
            int sum = sqOfDigits(n);
            if (cycle.find(sum) != cycle.end()) return false;
            cycle.insert(sum);
            n = sum;
        }
        
        return true;
    }
};
