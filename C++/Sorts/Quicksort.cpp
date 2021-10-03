# include <iostream>
using namespace std;

void swap(int & A, int & B){ //swap 
int temp=A;
A=B;
B=temp;
}

void print(int arr[], int size){
for(int i=0;i<size;i++){
 cout<<arr[i]<<' ';
 }
}

int Partition(int arr[], int low, int high){
 int pivot = arr[high]; //pivot last element
 int pIndex = low; 
 
 for(int i = low ; i<high; i++){ //from the first to before the pivot
 	if(arr[i]<pivot){ //if pivot > an element
 	swap(arr[i],arr[pIndex]); //element to the left 
 	pIndex++;//index ++
 	}
 }
 swap(arr[high],arr[pIndex]); 

 return pIndex;
}
 
void QuickSort(int arr[], int low, int high) //recursive quick sort
{
 if(low<high)
 {
 int pivot = Partition(arr,low,high);
 QuickSort(arr, low, (pivot-1));  
 QuickSort(arr, (pivot+1), high);  
 }
}
 
int main()  //main for testing purpose only (the phrases are in italian cause i'm Italian)
{
 
 int size=0;
 int * myarray;
 cout<<"Inserisci dimensione array: "<<endl;  //insert dimension of the array
 cin>>size;
 myarray=new int[size];
 
 cout<<"Inserisci "<<size<<" interi in qualunque ordine: "<<endl;  //insert integer numbers
 
 for(int i=0;i<size;i++){
 cin>>myarray[i];
 }

 cout<<"Prima del Quicksort"<<endl;  //before quicksort
 print(myarray,size);
 cout<<endl;
 
 QuickSort(myarray,0,(size-1)); //quicksort
 
 cout<<"Dopo il Quicksort"<<endl; //after quicksort
 for(int i=0;i<size;i++)
 {
 cout<<myarray[i]<<' ';
 }
 cout<<endl;
 system("PAUSE");
 return 0;
}
