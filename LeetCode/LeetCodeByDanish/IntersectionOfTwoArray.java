package LeetCode;

import java.util.ArrayList;
import java.util.Arrays;

public class IntersectionOfTwoArray {
    public static void main(String[] args) {
        int[] num1 = {1,2,2,1 };
        int[] num2 = {2,2 ,1 };
       // System.out.println(Arrays.toString(intersection(num1, num2)));
        ArrayList<Integer> ans = intersection(num1 , num2);
        for(int i : ans){
            System.out.print(i+" ");
        }
    }

    public  static  ArrayList<Integer> intersection(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int s1 = nums1.length;
        int s2 = nums2.length;
        int sz = Math.min(s1, s2);
       // int[] ans = new  int[sz];
        ArrayList<Integer> ans = new ArrayList<>();
      int i = 0;
      int j = 0;

      while( i != s1-1 && j!=s2-1){
          if(nums1[i] == nums2[j]){

              ans.add(nums1[i]) ;
              i++;
              j++;

          }
          if(nums1[i] < nums2[j]){
              i++;
          }else{
              j++;
          }

      }

     return ans;

    }
}
