#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
    static char a[30][50];
    static int head_y=38;
    static int head_x=18;
    static int x;
    static int y;
    static int score =0;
    static int tail_y[100];
     static int tail_x[100];
    static int direction =1;
    static int dir[100];
    static int l=1;
    static int k=0;
    void build()
    {
    memset(a,' ',sizeof a);

for(int i=0;i<30;i++)
    a[i][0]='|';
for(int i=0;i<50;i++)
    a[0][i]='-';
    for(int i=0;i<50;i++)
    a[29][i]='-';
    for(int i=0;i<30;i++)
    a[i][49]='|';
    }
void khana()
{
      y = (rand() % 48) + 1;
      x=(rand()%28)+1;
 ;

     //x=10;y=10;
     a[x][y]='@';
     //printf("%d",x);
}

void disp()
{
    for(int i=0;i<30;i++)
    {
    for(int j=0;j<50;j++)
    printf("%c",a[i][j]);
    printf("\n");
    }
}
void move()
{checkcollision();
foodcheck();
if(l>1)
    tailmove();
if(direction==1)
    left();
if(direction==2)
    right();
if(direction==3)
    up();
if(direction==4)
    down();

    disp();
    Sleep(20);


}
void tailmove()
{
    for(int i=l-2;i>=0;i--)
{

    if(i==0)
    {dir[0]=direction;
    if(direction==2)
{if(i==l-2)
a[tail_x[0]][tail_y[0]]=' ';
a[tail_x[0]][++tail_y[0]]='.';
}
if(direction==1)
{if(i==l-2)
a[tail_x[0]][tail_y[0]]=' ';
a[tail_x[0]][--tail_y[0]]='.';
}
if(direction==3)
{if(i==l-2)
a[tail_x[0]][tail_y[0]]=' ';
a[--tail_x[0]][tail_y[0]]='.';
}
if(direction==4)
{if(i==l-2)
a[tail_x[0]][tail_y[0]]=' ';
a[++tail_x[0]][tail_y[0]]='.';
}}
else
{int u=dir[--i];i++;  //printf("%d",i);Sleep(1000);
dir[i]=u;
    if(u==2)
{if(i==l-2)
a[tail_x[i]][tail_y[i]]=' ';
a[tail_x[i]][++tail_y[i]]='.';
}
if(u==1)
{if(i==l-2)
a[tail_x[i]][tail_y[i]]=' ';
a[tail_x[i]][--tail_y[i]]='.';
}
if(u==3)
{if(i==l-2)
a[tail_x[i]][tail_y[i]]=' ';
a[--tail_x[i]][tail_y[i]]='.';
}
if(u==4)
{if(i==l-2)
a[tail_x[i]][tail_y[i]]=' ';
a[++tail_x[i]][tail_y[i]]='.';
}
}}

}
void checkcollision()
{
for(int i=0;i<l-2;i++)
{
    if(head_x==tail_x[i]&&head_y==tail_y[i])
         {
        printf("GAME OVER");
        printf("\n");
        printf(" FINAL SCORE = ");

      printf("%d",score);
      Sleep(5000);
        exit(0);


    }
}


    if(head_y==0||head_x==0||head_x==29||head_y==49)
    {
        printf("GAME OVER");
        printf("\n");
        printf(" FINAL SCORE = ");

      printf("%d",score);
      Sleep(5000);
        exit(0);


    }
}
void snake()
{
            a[18][38]='.';

}
void left()
{direction=1;
if(l==1)
a[head_x][head_y]=' ';
head_y=--head_y;
 a[head_x][head_y]='.';
 //disp();
 Sleep(1);
}
void right()
{
     direction =2;
     if(l==1)
    a[head_x][head_y]=' ';
    head_y=++head_y;
    a[head_x][head_y]='.';
    //disp();
    Sleep(1);
}
void up()
{

    direction = 3;
    if(l==1)
    a[head_x][head_y]=' ';
    head_x=--head_x;
    a[head_x][head_y]='.';
   // disp();
   Sleep(1);
}
tailbuild()
{
    int q=k-1;
    if(l==1){
    tail_x[0]=head_x;
    tail_y[0]=head_y;
    if(direction==3)
        a[++tail_x[k]][tail_y[k]]='.';
        if(direction==2)
            a[tail_x[k]][--tail_y[k]]='.';
        if(direction==1)
            a[tail_x[k]][++tail_y[k]]='.';
        if(direction==4)
            a[--tail_x[k]][tail_y[k]]='.';
            l++;k++;}
    else
    {
        tail_x[k]=tail_x[q];
    tail_y[k]=tail_y[q];

     if(dir[q]==3)
        a[++tail_x[k]][tail_y[k]]='.';
        if(dir[q]==2)
            a[tail_x[k]][--tail_y[k]]='.';
        if(dir[q]==1)
            a[tail_x[k]][++tail_y[k]]='.';
        if(dir[q]==4)
            a[--tail_x[k]][tail_y[k]]='.';
            l++;k++;//printf("%d",k);
            //disp();

            //Sleep(1000);

    }
}
foodcheck()
{
    if(a[head_x][head_y]==a[x][y])
        {khana();
        tailbuild();

        //Sleep(1000);
        score+=10 ;}
}
void down()
{

    direction = 4;
    if(l==1)
    a[head_x][head_y]=' ';
    head_x=++head_x;
    a[head_x][head_y]='.';
    //disp();
   Sleep(1);

}
int main()
{char ch;
printf("1. please open full screen \n 2.capslock off use w,s,a,d for controlling");
printf("\n");
    printf("enter e and then press enter to start the game");
    scanf("%c",&ch);
    if(ch=='e')
    {
    build();
    snake();
    khana();
    char ch;
    while(1)
    {system("cls");
        if(!kbhit())
        {
         move();//Sleep(1000);
         //printf("score = ");
printf("%d",score);
        }
   else {system("cls");//Sleep(1000);
        checkcollision();
     ch= getch();foodcheck();
//printf("score = ");printf("%d",score);
switch(ch)
{
        case'w':
           if(direction!=4)
           {tailmove();up();disp();}
           else move();
           break;

        case's':

           if(direction!=3)
           {tailmove();down();disp();}
           else move();
           break;

        case'a':

           if(direction!=2)
          {
           tailmove();left();disp();}
           else move();
           break;
        case 'd':

           if(direction!=1)
           {tailmove();right();disp();}
           else move();
           break;
           default:
               move();
               break;
            //if(l>2)
                 // tailmove();
        //Sleep(1000);
        }
        }
    }}
 return 0;

}
