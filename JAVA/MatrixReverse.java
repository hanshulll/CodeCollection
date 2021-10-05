import java.util.Scanner;
public class MatrixReverse {
    int [][]arr;
    int m;
    int n;
    int r;
    int s;
    MatrixReverse(int mm, int nn){
        m=mm;
        n=nn;
        arr=new int[m][n];
    }
    Scanner sc=new Scanner(System.in);
    void fillArray(){
        System.out.println("Enter Elements");
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                arr[i][j]=sc.nextInt();
            }
        }
    }
    int reverse(int x){
        int i=x;
        s=0;
        while(i!=0){
            r=i%10;
            s=s*10+r;
            i=i/10;
        }
        return s;
    }
    void revMat(MatrixReverse P){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                this.arr[i][j]=reverse(P.arr[i][j]);
            }
        }
    }
    void show(){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                System.out.print(arr[i][j]+"\t");
            }
            System.out.println();
        }
    }
    public static void main(String []args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter size of an array");
        int m=sc.nextInt();
        int n=sc.nextInt();
        MatrixReverse obj=new MatrixReverse(m,n);
        MatrixReverse obj2=new MatrixReverse(m,n);
        obj.fillArray();
        obj2.revMat(obj);
        System.out.println("Original Matrix :");
        obj.show();
        System.out.println("Matrix with reversed elements");
        obj2.show();
    }
}
