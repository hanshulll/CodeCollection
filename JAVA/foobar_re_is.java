import java.util.ArrayList;
public class Solution
{
	public static String Solution(int i) {
	    
    
     String all_primes=sieveOfEratosthenes(30000);
        String answer=all_primes.substring(i,i+5);
        return answer;
    }
    public static String sieveOfEratosthenes(int n) 
    { 
        StringBuilder sb=new StringBuilder();
        boolean prime[] = new boolean[n+1]; 
        for(int i=0;i<n;i++) 
            prime[i] = true; 
        for(int p = 2; p*p <=n; p++) 
        { 
            if(prime[p] == true) 
            {
                for(int i = p*p; i <= n; i += p) 
                    prime[i] = false; 
            } 
        } 
          
        for(int i = 2; i <= n; i++) 
        { 
            if(prime[i] == true) 
                sb.append(i); 
        } 
        return sb.toString();
    } 
    
}
