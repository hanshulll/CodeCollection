import java.util.*;
public class SpiralTraversalOf2DArray {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter number of rows");
        int row = scanner.nextInt();
        System.out.println("Enter number of column");
        int column = scanner.nextInt();
        int[][] matrix = new int[row][column];
        System.out.println("Enter the elements of 2X2 matrix");
        for (int i = 0; i < row; i++) {
            System.out.println("Enter "+ column +" elements for " + i +" row");
            for (int j = 0; j < column; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
        List<Integer> traversalList = spiralTraversal(matrix);
        printTraversal(traversalList);
    }
    public static List<Integer> spiralTraversal(int matrix[][]){
        List<Integer> ans = new ArrayList<Integer>();
        if(matrix.length == 0){
            return ans;
        }
        int row = matrix.length, column = matrix[0].length;
        boolean[][] seen = new boolean[row][column];
        int[] dr = {0, 1, 0, -1};
        int[] dc = {1, 0, -1, 0};
        int r=0, c=0, di=0, cr=0, cc=0;
        for (int i = 0; i < row * column; i++) {
            ans.add(matrix[r][c]);
            seen[r][c] = true;
            cr = r + dr[di];
            cc = c + dc[di];
            if(0<=cr && cr<row && 0<=cc && cc<column && !seen[cr][cc]){
                r = cr;
                c = cc;
            }
            else{
                di = (di+1)%4;
                r += dr[di];
                c += dc[di];
            }
        }
        return ans;
    }
    public static void printTraversal(List<Integer> list){
        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i)+ ((i<list.size()-1)?", ":"."));
        }
    }
}

