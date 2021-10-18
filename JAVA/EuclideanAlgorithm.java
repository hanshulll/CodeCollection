import java.io.*;
import java.util.*;
class EuclideanAlgorithm{
    public void euclid(int num1,int num2){
        int rem;
         while(num2>0){
            rem=num1%num2;
            num1=num2;
            num2=rem;
        }
        System.out.println("The Greatest Common Divisor is "+num1);
    }
    public static void main(String[] args){
        int num1,num2,temp;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number 1");
        num1=sc.nextInt();
        System.out.println("Enter the number 2");
        num2=sc.nextInt();
             if(num1>0&&num2>0){
                if(num1>num2){
                    EuclideanAlgorithm s=new EuclideanAlgorithm();
                    s.euclid(num1,num2);
          
                }
                else{
                    temp=num1;
                    num1=num2;
                    num2=temp;
                    Euclid s=new Euclid();
                    s.euclid(num1,num2);
                }
             }
             else{
               System.out.println("Both Numbers should be positive");
             }

        }
}
