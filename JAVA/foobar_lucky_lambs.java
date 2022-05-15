public static int solution(int total_lambs) {
       
        int total_lambs1=total_lambs;
        int i=0;
        int cnt1=0;
        int cnt=0;
        while(total_lambs1>=fib(i))
        {
            cnt1++;
            total_lambs1-=fib(i);
            i++;
        }
        int x=1;
        while(total_lambs>=x)
        {
            cnt++;
            total_lambs-=x;
            x*=2;
        }
        return cnt1-cnt;
    }
    static int fib(int n) 
        { 
            int a = 1, b = 1, c; 
            if (n == 0) 
                return a; 
            for (int i = 2; i <= n; i++) { 
                c = a + b; 
                a = b; 
                b = c; 
            } 
            return b; 
        } 
        

