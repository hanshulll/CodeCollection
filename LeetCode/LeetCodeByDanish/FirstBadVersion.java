package LeetCode;
/*
 The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version);
You are a product manager and currently leading a team to develop a new product
. Unfortunately, the latest version of your product fails the quality check.
 Since each version is developed based on the previous version,
  all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one,
 which causes all the following ones to be bad.
You are given an API bool isBadVersion(version) which returns whether version is bad.
 Implement a function to find the first bad version. You should minimize the number of calls to the API.



Example 1:

Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.
Example 2:

Input: n = 1, bad = 1
Output: 1
 */
public class FirstBadVersion {
    public static void main(String[] args) {
        int n = 5;
        int bad = 4;
        int ans = firstBadVersion(n , bad);
        System.out.println(ans);

    }
    public static int firstBadVersion(int n , int bad) {
        int i = 1 ;
        int l = n;

        while( i <= n){
            int mid = i+(l-i)/2;
            if(isBadVersion(mid , bad)){
                if(!isBadVersion(mid-1 , bad)) return mid;

                l = mid-1;
            }else{
                i = mid+1;
            }
        }
        return -1;
    }

    // I m inplementing myself.
     static boolean isBadVersion(int n , int bad){
        return (n== bad) ;
    }
}
