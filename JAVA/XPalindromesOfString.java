

A string is given as a input and You have to  check if there exist  x + 1 strings (s1 + s2 + s3 + ..... + sx+ 1 ) and  after x + 1 strings the  reverse of x strings is concatinated 
you need to display the non-empty strings upto x if they are equal and if theyr'e not print Doesn't exist.
  
  Example:
  I/p : abcdefbz  and x = 1
  O/p : Doesn't exist
    
  I/P : sharxyzrahs and X= 4
  O/P : shar

Explaination : Like if we take s1 = a  , sx + 1 = cdef   and 
rev of s1 = a so theyr'e not equal

import java.io.*;

class XPaliindrome {
    public static void xPalindrome(int n, int k, String s)
    {
        // length of the string should be atleast twice of
        // size
        // x
        if (2 * k >= n) {

            System.out.println(
                "n should be greater 2x \n!");
            return;
        }
        // initializing the both strings
        String front = "", end = "";

        for (int i = 0; i < k; i++) {
            // Adding the characters upto x
            front += s.charAt(i);
        }
        for (int i = n - 1; i >= n - k; i--) {
            // Adding the characters from end upto n-k
            end += s.charAt(i);
        }
        if (front.equals(end)) {
            // If equal then print the string
            System.out.println(front);
        }
        else {
            System.out.println("Doesn't exist !");
        }
    }

    // Driver code
    public static void main(String[] args)
    {
        int n = 9;
        int k = 3;
        String s = "sharxyzrahs";
        xPalindrome(n, k, s);
    }
  // OUTPUT = sha
}
