import javax.swing.*;
import java.io.*;
import java.util.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;


class Data
{
    
    public JButton[] keys;
    public int m;
    Data(JButton[] arr, int n)
    {
        keys=arr;
        m=n;
    }
}

class GameToFile
{
    public static void save(String fln,Data d1)
    {
        String nm1=fln.trim()+".AdiTicTacToe";
        
        JButton butt[]=d1.keys;
        int k=d1.m;
       
        try
        {
            ObjectOutputStream oos=new ObjectOutputStream(new FileOutputStream(nm1));
           
            oos.writeObject(butt);
            oos.writeInt(k);
            oos.close();
          
        }
        catch(Exception exce)
        {
        }
    }

}

class gui extends JFrame implements ActionListener
{
    JFrame fr=new JFrame("Tic Tac Toe");
    public JButton butt[]=new JButton[9];
    JPanel p=new JPanel();
    JTextField ar=new JTextField(15);
    int move;
    Font font = new Font("Calibri", Font.BOLD, 20);
    JButton save=new JButton("Save and Exit");
    JButton ext=new JButton("EXIT");
    gui()
    {
        setDesign();
        fr.setResizable(false);
        for(int i=0;i<9;i++)
        {
            butt[i]=new JButton();
            butt[i].setPreferredSize(new Dimension(50,50));
            butt[i].setText(" ");
            butt[i].setBackground(Color.cyan);
            butt[i].setFont(font);
            butt[i].addActionListener(this);
            p.add(butt[i]);
        }
        fr.setBackground(Color.pink);
        save.setBackground(Color.yellow);
        save.addActionListener(this);

        ext.setBackground(Color.red);
        ext.addActionListener(this);
        ar.setEditable(false);
        p.add(new JScrollPane(ar));
        ext.setEnabled(false);
        p.add(save);
        p.add(ext);
        fr.setSize(220,280);
        fr.add(p);

        fr.setVisible(true);
        move=1;
        ar.setText("Player "+move+"\'s Move");
    }
    
    
    public void setKeys(JButton[] keys)
    {
        butt=keys;
    }
    public void actionPerformed(ActionEvent e)
    {
        if(e.getSource() !=save)
        {
            for(int i=0;i<9;i++)
            {
                if(e.getSource()==butt[i])
                {

                    butt[i].setEnabled(false);
                    if(move==1)
                    {
                        butt[i].setText("X");
                    }
                    else
                    {
                        butt[i].setText("O");
                    }
                }
            }
            move+=1;
            if(move==3)
            {
                move=1;
            }
            ar.setText("Player "+move+"\'s Move");
            if(playGame.isOver(butt))
            {

                for(int i=0;i<9;i++)
                {
                    butt[i].setEnabled(false);

                }
                ext.setEnabled(true);
                save.setEnabled(false);
                int w=playGame.Winner(butt);
                if(w!=0)
                {
                    ar.setText("Player "+w+" wins");
                }
                else
                {
                    ar.setText("Draw Match");
                }
            }
        }
        if(e.getSource()==ext)
        {
            fr.setVisible(false);
        }
        if(e.getSource()==save)
        {
            fr.setVisible(false);
            new SaveGame(new Data(butt,move));
        }
    }

    public final static void setDesign() {
        try {
            UIManager.setLookAndFeel(
                "com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel");
        } catch(Exception e) {  
        }
    }

}

class LoadGame implements ActionListener
{
    JFrame fr=new JFrame("Load Game");
    JTextField fln=new JTextField(30);
    JButton sv=new JButton("Load");
    JPanel pan=new JPanel();
    gui obj;
    static JButton[] ks=new JButton[9];
    static int m=0;
    LoadGame(gui ob)
    {
        obj=ob;
        pan.add(new JLabel("Enter File Name"));
        pan.add(fln);
        pan.add(sv);
        fr.setSize(400,200);
        fr.setResizable(false);
        fr.add(pan);
        fr.setVisible(true);
        sv.addActionListener(this);

    }

    public void actionPerformed(ActionEvent e)
    {
        int m=load(fln.getText());
        for(int i=0;i<9;i++)
        {
            obj.butt[i].setText(ks[i].getText());
            obj.butt[i].setEnabled(ks[i].isEnabled());

        }
        obj.move=m;
        //System.out.println("Changed Move to "+obj.move);
        obj.ar.setText("Player "+m+"\'s Move");
        obj.fr.setVisible(true);
        fr.setVisible(false);
    }

    public static int load(String fln)
    {

        String nm1=fln.trim()+".AdiTicTacToe";
     
        int m=0;

        try
        {
            ObjectInputStream ois=new ObjectInputStream(new FileInputStream(nm1));
       
            ks=(JButton[]) ois.readObject();
            m=ois.readInt();
            //System.out.println("Reading move "+m);
           
            ois.close();
        }
        catch(Exception exce)
        {
        }
        return m;
    }
}

class newGame implements ActionListener
{
    JFrame fr=new JFrame("Tic Tac Toe");
    JPanel pan=new JPanel();
    JButton nn=new JButton("New Game");
    JButton ll=new JButton("Load Game");
    newGame()
    {
        fr.setSize(100,200);
        fr.setResizable(false);
        pan.add(new JLabel("Choose Game"));
        nn.addActionListener(this);
        ll.addActionListener(this);
        pan.add(nn);
        pan.add(ll);
        fr.add(pan);
        fr.setVisible(true);
    }
    public void actionPerformed(ActionEvent e)
    {
        fr.setVisible(false);
        if(e.getSource()==nn)
        {
            new gui();
        }
        else
        {
            gui obj=new gui();
            obj.fr.setVisible(false);
            new LoadGame(obj);
        }
    }
}

class playGame
{
    static boolean isOver(JButton butt[])
    {
        if (Winner(butt)!=0)
        {
            return true;
        }
        for(int i=0;i<9;i++)
        {
            if(butt[i].getText().charAt(0)==' ')
            {
                return false;
            }

        }
        return true;
    }

    static int Winner(JButton butt[])
    {
        char c=' ';
        char moves[]=new char[9];
        for(int i=0;i<9;i++)
        {
            moves[i]=butt[i].getText().charAt(0);
        }
        if(moves[0]==moves[1]&&moves[1]==moves[2]&&moves[0]!=' ')
        {
            c=moves[0];
        }
        if(moves[3]==moves[4]&&moves[4]==moves[5]&&moves[3]!=' ')
        {
            c=moves[3];
        }
        if(moves[6]==moves[7]&&moves[7]==moves[8]&&moves[6]!=' ')
        {
            c=moves[6];
        }
        if(moves[0]==moves[3]&&moves[3]==moves[6]&&moves[0]!=' ')
        {
            c=moves[0];
        }
        if(moves[1]==moves[4]&&moves[4]==moves[7]&&moves[1]!=' ')
        {
            c=moves[7];
        }
        if(moves[2]==moves[5]&&moves[5]==moves[8]&&moves[2]!=' ')
        {
            c=moves[2];
        }
        if(moves[0]==moves[4]&&moves[4]==moves[8]&&moves[0]!=' ')
        {
            c=moves[0];
        }
        if(moves[2]==moves[4]&&moves[4]==moves[6]&&moves[2]!=' ')
        {
            c=moves[2];
        }
        if(c=='X')
        {
            return 1;
        }
        if(c=='O')
        {
            return 2;
        }
        return 0;
    }
}

class SaveGame implements ActionListener
{
    JFrame fr=new JFrame("Save Game");
    JTextField fln=new JTextField(30);
    JButton sv=new JButton("Save");
    JPanel pan=new JPanel();
    Data d;
    SaveGame(Data k)
    {
        d=k;
        pan.add(new JLabel("Enter File Name"));
        pan.add(fln);
        pan.add(sv);
        fr.setSize(400,200);
        fr.setResizable(false);
        fr.add(pan);
        fr.setVisible(true);
        sv.addActionListener(this);

    }

    public void actionPerformed(ActionEvent e)
    {
        GameToFile.save(fln.getText(),d);
        fr.setVisible(false);
    }
}

public class TicTacToe
{
    public static void main(String args[])
    {
        gui.setDesign();
        new newGame();
    }
}
