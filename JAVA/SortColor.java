/*Contributor Name: Kavs-123(Kavya Agrawal)
  Github Link: https://github.com/Kavs-123
*/

public class Sort{

    public int [] sortColors(int[] nums) 
    {
        int count_0= 0;
        int count_1= 0;
        int count_2= 0;
        for (int i = 0; i < nums.length; i++) 
        {
            if (nums[i] == 0) 
            {
                count_0 ++;
            }
            if (nums[i] == 1)
            {
                count_1 ++;
            }
            if (nums[i] == 2)
            {
                 count_2 ++;
            }
        }
        for(int i = 0; i < nums.length; i++) 
        {
            if (i < count_0)
            { 
                nums[i] = 0;
            }
            else if (i < count_0 + count_1) 
            {
                nums[i] = 1;
            }
            else 
            {
                nums[i] = 2;
            }
        }
        return nums;
    }  

}


