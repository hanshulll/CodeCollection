


import java.util.Arrays;
 
// Class to store the pairs
class Pair implements Comparable<Pair> {
    int ind, val;
 
    Pair(int ind, int val)
    {
        this.ind = ind;
        this.val = val;
    }
 
    @Override
    public int compareTo(Pair o)
    {
        if (this.val > o.val)
            return 1;
        return -1;
    }
}
 
class  Maximumwater {
 
    // Return the maximum water that can be stored
    static int maxWater(int height[], int n)
    {
 
        // Make pairs with indices
        Pair pairs[] = new Pair[n];
        for (int i = 0; i < n; i++)
            pairs[i] = new Pair(i, height[i]);
 
        // Sort array based on heights
        Arrays.sort(pairs);
 
        // To store the min and max index so far
        // from the right
        int minIndSoFar = pairs[n - 1].ind;
        int maxIndSoFar = pairs[n - 1].ind;
        int max = 0;
        for (int i = n - 2; i >= 0; i--) {
 
            // Current building paired with the building
            // greater in height and on the extreme left
            int left = 0;
            if (minIndSoFar < pairs[i].ind) {
                left = (pairs[i].val * (pairs[i].ind - minIndSoFar - 1));
            }
 
            // Current building paired with the building
            // greater in height and on the extreme right
            int right = 0;
            if (maxIndSoFar > pairs[i].ind) {
                right = (pairs[i].val * (maxIndSoFar - pairs[i].ind - 1));
            }
 
            // Maximum so far
            max = Math.max(left, Math.max(right, max));
 
            // Update the maximum and minimum so far
            minIndSoFar = Math.min(minIndSoFar,
                                   pairs[i].ind);
            maxIndSoFar = Math.max(maxIndSoFar,
                                   pairs[i].ind);
        }
 
        return max;
    }
 
    // Driver code
    public static void main(String[] args)
    {
        int height[] = { 2, 1, 3, 4, 6, 5 };
        int n = height.length;
 
        System.out.print(maxWater(height, n));
    }
}
