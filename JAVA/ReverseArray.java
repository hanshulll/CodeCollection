import java.util.Scanner;
public class ReverseArray
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter length of the array");
        int len = sc.nextInt();
        int arr[] = new int[len];
        for(int i = 0; i < len; i++)
        {
            System.out.println("Enter 1st Element");
            arr[i] = sc.nextInt();
        }
        System.out.println("Original array is :");
        for(int i = 0; i < len; i++)
        {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
        reverse(arr);
        System.out.println("Reversed array is :");
        for(int i = 0; i < len; i++)
        {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void reverse(int arr[])
    {
        int i = 0, j = arr.length-1;
        while(i < j)
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
}