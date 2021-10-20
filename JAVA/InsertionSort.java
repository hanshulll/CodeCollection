import java.util.Scanner;
import java.util.*;
// Java program for implementation of Insertion Sort
class InsertionSort
{
	/*Function to sort array using insertion sort*/
    static int comp;
	void sort(int arr[])
	{
		int n = arr.length;
		for (int i=1; i<n; ++i)
		{
			int key = arr[i];
			int j = i-1;

			/* Move elements of arr[0..i-1], that are
			greater than key, to one position ahead
			of their current position */
			while (j>=0 && arr[j] > key)
			{
				arr[j+1] = arr[j];
				j = j-1;
                comp++;
			}
			arr[j+1] = key;
            comp++;
		}   
	}

	/* A utility function to print array of size n*/
	static void printArray(int arr[])
	{
		int n = arr.length;
		for (int i=0; i<n; ++i)
			System.out.print(arr[i] + " ");

		System.out.println();
	}

	// Driver method
	public static void main(String args[])
	{	
        Scanner sc=new Scanner(System.in);
        int n;
        int arr[n];

        System.out.println("Enter elements: ");
        for(int i=0; i<n; i++){

            arr[i]=sc.nextInt();
        }

        InsertionSort ob = new InsertionSort();		
		ob.sort(arr);   
        System.out.println("Comparisions= "+comp);
		printArray(arr);
	}
