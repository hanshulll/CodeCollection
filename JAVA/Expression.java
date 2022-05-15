import java.util.Scanner;
//import java.io.BufferedReader;
//import java.io.InputStreamReader;
public class Expression{
	public static void main(String[] args) throws Exception{
		Scanner s = new Scanner(System.in);
		int a = s.nextInt();
		int b = s.nextInt();
		int c = s.nextInt();
		int max  = -1;
		int[] arr = new int[6];
		arr[0] = a+b+c;
		arr[1] = (a+b)*c;
		arr[5] = a*(b+c);
		arr[2] = a+(b* c);
		arr[3] = a*b*c;
		arr[4] = (a+b)*c;
		for(int i=0;i<6;i++){
			if(max < arr[i])
				max = arr[i];
		}
	System.out.println(max);
	}
}