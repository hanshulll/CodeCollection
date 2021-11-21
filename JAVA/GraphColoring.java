import java.util.*;
public class GraphColoring {
 
  static int colorsCount;
  static int verticesCount;
  static int arr[][];
  static int solnCount=0;
  static int colorNumber[];
  static char[] colorNames = new char[] {'R','G','B','Y','O','I'};

	public static void main(String args[]) {
		
		System.out.println("\n******Graph Coloring Problem*****");
        Scanner sc = new Scanner(System.in);
        System.out.printf("Enter no of vertices: ");
        verticesCount=sc.nextInt();
        arr= new int[verticesCount][verticesCount];
        System.out.println("Enter adjacency matrix");
        for(int i=0;i<verticesCount;i++) {
          	for(int j=0;j<verticesCount;j++) {
          		arr[i][j]=sc.nextInt();
          	}
        }
        colorNumber=new int[verticesCount];
        System.out.printf("1) Provide the number of colors available.\n2) Color graph using minimum no. of colors\nEnter your choice: ");
		int choice = sc.nextInt();   	  
		if(choice==1){
			System.out.printf("Enter no of colors available: ");
        	colorsCount=sc.nextInt();
		}
		else if(choice==2)
        	colorsCount = findMinimumChromaticNumber();
        System.out.println("Minimum count of colors required are: "+colorsCount);
        graphColoringSolver(0);
        System.out.println("No. of solutions is "+solnCount);
	}
	
	public static int findMinimumChromaticNumber() {
		int assign [] = new int[verticesCount];
		Arrays.fill(assign, -1);
		for (int i = 0; i < verticesCount; i++) {
			assign[i] = 1;
			for(int j = 0;j<verticesCount; j++) {
				if (arr[i][j] == 1 && assign[i] == assign[j]) {
					assign[i]++;
				} 
			}
		}
		int max = Integer.MIN_VALUE;
		for(int i =0;i<assign.length;i++) {
			if(assign[i]>max)
				max = assign[i];
		}
		return max;
	}


	public static boolean canColorVertex(int v,int c) { 
		for (int i = 0; i < verticesCount; i++) 
			if (arr[v][i] == 1 && c == colorNumber[i]) 
				return false; 
		return true; 
	} 

	public static void graphColoringSolver(int v){
		if (v == verticesCount)
		{	
			for (v = 0; v < verticesCount; v++)
				System.out.printf(colorNames[colorNumber[v]-1]+" "); 

			System.out.println();
			solnCount++;
			return;
		}
		
		for (int c = 1; c <= colorsCount; c++)
		{
			if (canColorVertex( v, c))
			{
				colorNumber[v] = c;
				graphColoringSolver(v + 1);
				colorNumber[v] = 0;
			}
		}
	}
}