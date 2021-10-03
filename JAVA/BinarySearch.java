/*
* 'Binary search' is an efficient algorithm for searching an element in a sorted array (either ascending or descending).
* In each iteration, array is broken down in half till when the target element is found.
* More efficient than 'Linear search' for large data.
* Time complexity :
        Best case : O(1)
        Worst case : O(log n)
 */
import java.util.Scanner;
public class BinarySearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int[] sortedArray = {1,5,7,8,34,56,67,78,89,97,124,1267,6666,7777};
        System.out.println("Enter an integer to search it in the array :");
        int target = input.nextInt();
        int indexnumber = binarySearch(sortedArray, target);
        printMessage(target, indexnumber);
    }

    static int binarySearch(int[] sortedArray, int target){ // This method returns the index of the target element
        int start = 0;
        int end = sortedArray.length - 1;
        while(start <= end){
            int mid = (start + end) / 2;
            if (target == sortedArray[mid]){
                return mid;
            }
            else if (target < sortedArray[mid]) {
                end = mid - 1 ;
            }
            else if (target > sortedArray[mid]){
                start = mid + 1;
            }
        }
        return -1;  // If the target element is not found in the array, -1 is returned
    }

    static void printMessage(int target, int indexnumber){ // This method prints the index of target when called.
       if(indexnumber == -1){
           System.out.println(target + " is not found in the array.");
       }
       else{
           System.out.println(target + " is found in the array at index " + indexnumber);
       }
    }
}