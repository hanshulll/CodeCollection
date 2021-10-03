
import java.util.Arrays;
import java.util.Scanner;

public class Ranking{

    public static void main(String args[]){
    
    int arr[]= new int[10];
    int count=0;
    
    Scanner sc = new Scanner(System.in);

        System.out.println("Enter marks");
        

        for(int i=0; i<10; i++){

            arr[i]= sc.nextInt();
        }
            
    for(int j=0; j<10; j++){  
      
            if(arr[j]>=85){
                count++;
            }
        }

    System.out.println("count="+count);
}

}
