import java.util.Scanner;
import java.util.Random;
public class rock_paper_scissors {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Random rand  =  new Random();
        int you_score=0;
        int comp_score=0;
        System.out.println("O stands for rock");
        System.out.println("1 stands for scissors");
        System.out.println("2 stands for paper");
        for(int i=1;i<=5;i++)
        {
            int comp = rand.nextInt(3);
            System.out.println("Select one number among 0,1 or 2");
            int you = sc.nextInt();
            System.out.println("Computer selected"+comp);
            System.out.println("You selected"+you);
            if(comp==0&&you==1)
            {
                System.out.println("You lose");
                comp_score++;
            }
            else if(comp==0&&you==2)
            {
                System.out.println("You Win");
                you_score++;
            }
            else if(comp==1&&you==0)
            {
                System.out.println("You lose");
                comp_score++;
            }
            else if(comp==1&&you==2)
            {
                System.out.println("You Win");
                you_score++;
            }
            else if(comp==2&&you==0)
            {
                System.out.println("You lose");
                comp_score++;
            }
            else if(comp==2&&you==1)
            {
                System.out.println("You Win");
                you_score++;
            }
            else
            {
                System.out.println("It's a tie, both computer and you selected the same...");
            }
        }
        System.out.println("Score of computer is :"+comp_score);
        System.out.println("Score of you is :"+you_score);
        if(comp_score>you_score)
        {
            System.out.println("Computer wins the game and you lose the game");
        }
        else
        {
            System.out.println("You won the game and computes loses the game");
        }

        System.out.println("----!!!!GAME OVER!!!!----");
    }
}
