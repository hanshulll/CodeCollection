import java.util.Scanner;

class MultipleInputs {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in); 
		while (in.hasNext()) {
			if (in.hasNextInt())
				System.out.println(in.nextInt());
			else 
				in.next();
		}
	}
}