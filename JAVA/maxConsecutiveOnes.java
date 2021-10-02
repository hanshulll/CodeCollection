import java.util.Scanner;

public class maxConsecutiveOnes {

    public static int findMaxConsecutiveOnes(int[] nums) {
        int n = nums.length, si = 0, ei = 0, len = 0, count = 0;
        while (ei < n) {
            if (nums[ei++] == 0)
                count++;

            while (count == 1) {
                if (nums[si++] == 0)
                    count--;
            }

            len = Math.max(len, ei - si);
        }
        return len;
    }

    public static void main(String[] args){
        Scanner scn=new Scanner(System.in); 
        int n=scn.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=scn.nextInt(); 
        }

        System.out.println(findMaxConsecutiveOnes(arr));
    }
    
}
