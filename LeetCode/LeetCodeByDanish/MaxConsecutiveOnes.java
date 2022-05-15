package LeetCode;

import java.util.Arrays;

public class MaxConsecutiveOnes {
    public static void main(String[] args) {
        int[] arr = {0};
        System.out.println(count(arr));
    }
    public static int count(int[] arr){

        int max = 0;
        int count = 0;

        for(int i = 0 ; i< arr.length ; i++){
            if(arr[i] == 1){
                if(i == arr.length-1 && arr[i] == 1){
                    count++;
                    max = Math.max(max , count);

                }
                count++;
            }else{
                max = Math.max(max , count);
                count = 0;
            }
        }
        return max;
    }
}
