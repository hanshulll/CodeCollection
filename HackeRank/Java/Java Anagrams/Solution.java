import java.util.Scanner;

public class Solution {

    static boolean isAnagram(String a, String b) {
        // Complete the function
        int len1=a.length();
        int len2=b.length();
        if(len1!=len2){
            //System.out.println("inequal length");
            return false;
        }
        a=a.toLowerCase();
        b=b.toLowerCase();
        char []arr1=a.toCharArray();
        char []arr2=b.toCharArray();
        
        char[]arr11=sortArr(arr1,len1);
        char[]arr22=sortArr(arr2,len1);
        //System.out.println("sorted");
        for(int i=0;i<len1;i++){
           if(arr11[i]!=arr22[i]){
               return false;
           } 
        }
        return true;
    }
    static char[] sortArr(char[] arr1,int len1){
        int g=0,h=0;
        char temp;
        while(g<len1){
            h=g+1;
            while(h<len1){
                if(arr1[h]<arr1[g]){
                    temp=arr1[g];
                    arr1[g]=arr1[h];
                    arr1[h]=temp;
                }
                h++;
            }
            g++;
        }
        return arr1;
    }

  public static void main(String[] args) {
    
        Scanner scan = new Scanner(System.in);
        String a = scan.next();
        String b = scan.next();
        scan.close();
        boolean ret = isAnagram(a, b);
        System.out.println( (ret) ? "Anagrams" : "Not Anagrams" );
    }
}
