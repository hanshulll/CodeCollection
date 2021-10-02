import java.util.*;
public class FindFirstandLastPositionofElementinSortedArray {
  public int[] searchRange(int[] nums, int target) {
    int ind1=-1,ind2=-1,flag=0;
    int[] res=new int[2];
    for(int i=0;i<nums.length;i++){
        if(nums[i]==target && flag==0){
            ind1=i;
            ind2=i;
            flag=1;
        }
        else if(nums[i]==target &&(i==nums.length-1||nums[i+1]!=target) && flag==1){
            ind2=i;
            break;
        }
    }
    res[0]=ind1;res[1]=ind2;
    return res;
}
}
