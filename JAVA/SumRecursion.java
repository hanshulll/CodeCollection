import java.util.Scanner;

public class SumRecursion {

    public static int Sum(int input[]){
        if(input.length<=0){
            return 0;
        }

        int smallInput[] = new int[input.length-1];
        for(int i=1;i<input.length; i++){
            smallInput[i-1] = input[i];
        }

        return (Sum(smallInput)+input[input.length-1]);
    }

    public static void main(String[] args){
        Scanner sc =new Scanner(System.in);
        int N = sc.nextInt();
        int[] array = new int[N];
        for(int i =0; i<N; i++){
            array[i]=sc.nextInt();
        }

    }
}
