//  Contributor info : 
//  Name: Riya Bhandari
//   Github: https://github.com/RiyaBhandari-2811



/**
 *👉 Problem: String Input 
 *Description: Write a Program to take string input from user and display it in java 
 */

import java.util.Scanner;
public class StringInput {
	private static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) 
	{

        // Taking Input 
        System.out.println(" Enter the String : ");
        String s1 = sc.nextLine();


        // Displaying It
        System.out.print(" Your Entered String is : " + s1);


    }
}