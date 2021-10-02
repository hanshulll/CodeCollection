import java.util.*;
class binarysearch {
 static int bsearch(int a[],int n,int s,int e){
   if(e>=s){
     int mid=1+(e-s)/2;
     if(a[mid]==n)
       return mid;
     if(a[mid]>n)
       return bsearch(a,n,s,mid-1);
     return bsearch(a,n,mid+1,e);
   }
   return -1;
  }
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    binarysearch ob=new binarysearch();
    System.out.println("Enter the no. of elements:");
    int n=sc.nextInt();
    int a[]=new int[n];
    System.out.println("Enter the array elements in ascending order:");
    for(int i=0;i<n;i++){
      a[i]=sc.nextInt();
    }
    System.out.println("Enter the number to be searched:");
    int num=sc.nextInt();
    int x=ob.bsearch(a,num,0,n-1);
    if(x==-1)
      System.out.println("Element not found");
    else
      System.out.println("Element found at "+(x+1));
  }
}
