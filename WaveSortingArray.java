
public class WaveSortingArray {

	void swap(int arr[], int a ,int b)
	{
		int temp;
		temp=arr[a];
		arr[a]=arr[b];
		arr[b]=temp;
	}
	
	void waveSorting(int [] arr, int n)
	{
		for (int i=0;i<n ;i= i+2)
		{
			//if current element is smaller than prevoius
			if(i>0 && arr[i-1] > arr[i])
				swap(arr, i-1 ,i);
			
			//if current element is smaller than next
			if(i<n-1 && arr[i] <arr[i+1])
				swap(arr,i,i+1);
		}
	}
	void printArray(int []arr,int n) 
	{
		for(int i=0;i<n;i++) 
		{
			System.out.print(arr[i] + " ");
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		WaveSorting wss = new WaveSorting();
		int [] arr = {10,90,49,2,1,5,23};
		int n=arr.length;
		
		wss.waveSorting(arr, n);
		wss.printArray(arr, n);
	}

}
