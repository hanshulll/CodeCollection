import java.io.*;
import java.util.*;
class Anagram{
	public static void main(String args[]){
		String str1,str2;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the String 1");
		str1=sc.nextLine();
		System.out.println("Enter the String 2");
		str2=sc.nextLine();
		if(str1.length()!=str2.length()){
			System.out.println("The Strings "+str1+" and"+str2+" is not a Anagram");
		}
		else{
			str1=str1.toLowerCase();
			str2=str2.toLowerCase();
			char[]arr1=str1.toCharArray();
			char []arr2=str2.toCharArray();
			Arrays.sort(arr1);
			Arrays.sort(arr2);
			if(Arrays.equals(arr1,arr2)==true){
			System.out.println("The Strings "+str1+" and"+str2+" is  a Anagram");
			}
			else{
			System.out.println("The Strings "+str1+" and"+str2+" is not a Anagram");
			}
		}
	}
}

			
			
