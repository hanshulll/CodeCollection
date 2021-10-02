import java.util.Scanner;

public class Tower_of_hanoi {
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the no of blocks:");
        int n=in.nextInt();
        int a=1, b=2, c=3;
        toh(n,a,b,c);

    }
    public static void toh(int n,int a,int b,int c){
        if(n==0)
            return;
        toh(n-1,a,c,b);
        System.out.println(n+ "["+a +"->" + b+"]");
        toh(n-1,c, b, a);

    }
}
