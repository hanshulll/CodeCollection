import java.util.Random;
import java.util.Scanner;

public class LinearSearch{

    // Search function (Linear search)
    
    public static boolean isPresent(int arr[], int n){

        for(int i=0; i<arr.length; i++){
            if(arr[i] ==n) return true;
        }

        return false;

    }

    // Function to generate array of random integers
    
    public static int[] genArray(int n){

        Random rand = new Random();
        int arr[] = new int[n];
        for(int i=0; i<n;i++){
            arr[i] = rand.nextInt(n);
        }

        return arr;

    }


    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n=sc.nextInt();// number of elements
        int[] array= genArray(n);

        int search= sc.nextInt();//Element to search
        
        for(int i=0; i<n;i++) System.out.print(array[i]+" ");//print array
        System.out.println();

        if(isPresent(array,search)) System.out.println("Element Present");
        
        else System.out.println("Element absent");

    }
}