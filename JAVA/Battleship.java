import java.util.Scanner;
class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.println("Welcome to battleship.");
    System.out.println("Make sure you have two players.");
    System.out.println("How many 2 person ships you would like?: ");
    int doubles = scanner.nextInt();
    System.out.println("How many 3 person ships you would like?: ");
    int trios = scanner.nextInt();
    System.out.println("How many 4 person ships you would like?: ");
    int quads = scanner.nextInt();
    int hitcounter = 0;
    int hitcounter2 = 0;
    boolean[][] player1grid = new boolean[10][10]; //Visual
    boolean[][] player2grid = new boolean[10][10]; //Visual
    boolean[][] player1ships = new boolean[10][10]; //Internal
    boolean[][] player2ships = new boolean[10][10]; //Interal
    System.out.println("Player 1 - Enter your 2-person ship coordinates here: ");
    for (int x = 0; 2 * doubles > x; x++){ //#1 double ship choice
      System.out.println("Enter the row: ");
      int row = scanner.nextInt();
      System.out.println("Enter the column: ");
      int column = scanner.nextInt();
      if (row >= 10 || row < 0){
        System.out.println("That's not an option. Try again.");
        x--;
      }
      else if (column >= 10 || column < 0){
        System.out.println("That's not an option. Try again.");
        x--;
      }
      else if (player1ships[row][column] == true){
        System.out.println("You've already selected that space. Choose another one.");
        x--;
      }
      else{
        player1ships[row][column] = true;
      }
    }
        System.out.println("Player 1 - Enter your 3-person ship coordinates here: ");
    for (int x = 0; 3 * trios > x; x++){ //#1 triple ship choice
      System.out.println("Enter the row: ");
      int row2 = scanner.nextInt();
      System.out.println("Enter the column: ");
      int column2 = scanner.nextInt();
      player1ships[row2][column2] = true;
    }
        System.out.println("Player 1 - Enter your 4-person ship coordinates here: ");
    for (int x = 0; 4 * quads > x; x++){ //#1 quadruple ship choice
      System.out.println("Enter the row: ");
      int row3 = scanner.nextInt();
      System.out.println("Enter the column: ");
      int column3 = scanner.nextInt();
      player1ships[row3][column3] = true;
    }
        System.out.println("Player 2 - Enter your 2-person ship coordinates here: ");
        for (int x = 0; 2 * doubles > x; x++){ //#2 double ship choice
      System.out.println("Enter the row: ");
      int row = scanner.nextInt();
      System.out.println("Enter the column: ");
      int column = scanner.nextInt();
      player2ships[row][column] = true;
    }
        System.out.println("Player 2 - Enter your 3-person ship coordinates here: ");
    for (int x = 0; 3 * trios > x; x++){ //#2 triple ship choice
      System.out.println("Enter the row: ");
      int row2 = scanner.nextInt();
      System.out.println("Enter the column: ");
      int column2 = scanner.nextInt();
      player2ships[row2][column2] = true;
    }
        System.out.println("Player 2 - Enter your 4-person ship coordinates here: ");
    for (int x = 0; 4 * quads > x; x++){ //#2 quadruple ship choice
      System.out.println("Enter the row: ");
      int row3 = scanner.nextInt();
      System.out.println("Enter the column: ");
      int column3 = scanner.nextInt();
      player2ships[row3][column3] = true;
    }
    System.out.println("Player 1, here are the locations of your ships");
    printgrid(player1ships);
    System.out.println("Player 2, here are the locations of your ships");
    printgrid(player2ships);
  while(true){
    System.out.println("Player one, make your move");
    printgrid(player1grid);
    System.out.println("Enter the row number: ");
    int length = scanner.nextInt();
    System.out.println("Enter the column number: ");
      int height = scanner.nextInt();
      if (hitcounter == doubles * 2 + trios * 3 + quads * 4){
        System.out.println("You sunk all of the enemy battleships! You Win!");
        break;
      }
      else if(player2ships[length][height] == true){
        System.out.println("Hit");
        hitcounter++;
        player1grid[length][height] = true;
      }
      else{
        System.out.println("Miss");
     }
    System.out.println("Player two, make your move");
    printgrid(player2grid);
    System.out.println("Enter the row number: ");
    int length2 = scanner.nextInt();
    System.out.println("Enter the column number: ");
    int height2 = scanner.nextInt();
    if (hitcounter2 == doubles * 2 + trios * 3 + quads * 4){
        System.out.println("You sunk all of the enemy battleships! You Win!");
        break;
      }
      else if(player1ships[length2][height2] == true){
        System.out.println("Hit");
        hitcounter2++;
        player2grid[length2][height2] = true;
      }
      else{
        System.out.println("Miss");
    }
  }
}
  public static void printgrid(boolean[][] grid){
    System.out.print("  0 1 2 3 4 5 6 7 8 9");
    System.out.println("");
    for (int x = 0; x < 10; x++){
      System.out.print(x + " ");
      for (int y = 0; y < 10; y++){
        if (grid[x][y] == true){
          System.out.print("x ");
        }
        else{
          System.out.print("- ");
        }
      }
      System.out.println("");
    }
  }
}