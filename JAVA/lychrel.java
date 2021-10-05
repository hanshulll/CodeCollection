/* ABHAY LAL
* WAP to check if a number is lychrel or not
*/
import java.io.*;
class lychrel
{
    long reverse(long n)
    {
        long r;
        long rev=0;
        while(n>0)
        {
            r=n%10;
            rev=(rev*10)+r;
            n=n/10;

        }
        return rev;
    }

    boolean ispalindrome(long y)
    {
        long rev=reverse(y);
        if(y==rev)
            return true;
        else
            return false;

    }

    public static void main() throws IOException
    {
        InputStreamReader isr=new  InputStreamReader(System.in);
        BufferedReader br=new  BufferedReader(isr);
        System.out.println("Enter a number");
        long x=Integer.parseInt(br.readLine());
        lychrel obj=new lychrel();
        long i;
        long s=0;
        long c=0;
        long t=x;
        for(i=1;i<=20;i++)
        {
            s=obj.reverse(x)+x;
            if(obj.ispalindrome(s)==true)
            {
                c++;
                break;
            }
            else
            {
                System.out.println(s);
                x=s;
                s=0;
                continue;
            }
        }
        if(c==0)
            System.out.println(t+"is a lychrel number");
        else 
            System.out.println(t+"is not a lychrel number");
    }
}
