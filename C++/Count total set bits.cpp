 int countSetBits(int n)
    {
        // Your logic here
        int ans = 0;
        
        while(n > 0)
        {
            int power = log2(n);
            int bits = pow(2, power - 1);
            
            bits = bits * power;
            bits = bits + 1;
            
            ans += bits;
            
            n = n - pow(2, power);
            
            ans += n;
        }
        
        return ans;
    }
