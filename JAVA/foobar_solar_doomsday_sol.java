import java.util.ArrayList;
public class Solution {
    public static int[] solution(int area) {
        // Your code here

        ArrayList<Integer> arrli = new ArrayList<Integer>();
        int x=100;
        do
        {
            x=(int)squareRoot(area);
            area=area-x*x;
            if(x>0)
                arrli.add(x*x);

        }while(area>0 && x<=1000);
        
        int solution[]=new int[arrli.size()];
        
        for (int i =0; i < arrli.size(); i++) 
            solution[i] = arrli.get(i); 
            
        return solution;
        
        
    }
    static float squareRoot(float n) 
    { 
        float x = n; 
        float y = 1; 
        double e = 0.1; 
        while (x - y > e) { 
            x = (x + y) / 2; 
            y = n / x; 
        } 
        return x; 
    }
}