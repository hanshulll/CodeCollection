package LeetCode;

public class Base7 {
    public static void main(String[] args) {
        System.out.println(convertToBase7(-7));
    }
    public static  String convertToBase7(int num) {

        if(num > 0){
            int ans = DecimalToAnyBase(num , 7);
            return Integer.toString(ans);
        }else{
            num *= -1;
            int ans = DecimalToAnyBase(num , 7);
            ans *=-1;
            return Integer.toString(ans);

        }

    }

    public static int DecimalToAnyBase(int n, int b)
    {
        int ans = 0;
        int pow = 1;

        while (n > 0)
        {
            int r = n % b;
            n /= b;
            ans += r * pow;

            pow *= 10;
        }
        return ans;


    }
}
