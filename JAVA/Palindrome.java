import java.util.Scanner;
class Palindrome{
    static boolean isPalindrome(int n){
        int r=0,s=0,dup=n;
        while(dup!=0){
            r=n%10;
            s=s*10+r;
            n=n/10;
        }
        if(n==s)
        return true;
        else
        return false;
    }
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter Number");
        int num=sc.nextInt();
        if(isPalindrome(num))
        {
            System.out.println("Palindrome Number");
        }
        else{
            System.out.println("Not Palindrome Number");
        }
        
    }
}