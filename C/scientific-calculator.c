#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
void graphics();
void text();

	void main()
	{
	clrscr();
	graphics();
	text();
	}
		void graphics()
		{
		intgd=DETECT, gm;
		initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
		setbkcolor(BLUE);
		setcolor(8);
		rectangle(0,0,160,423);//choice list
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(2,2,8);
		outtextxy(10,20,"Choice");
		outtextxy(10,30,"1.  ADDITION");
		outtextxy(10,50,"2.  SUBSTRUCTION");
		outtextxy(10,70,"3.  MULTIPLICATION");
		outtextxy(10,90,"4.  DIVISION");
		outtextxy(10,110,"5.  SQUARE ROOT");
		outtextxy(10,130,"6.  POWER");
		outtextxy(10,150,"7.  SQUARE");
		outtextxy(10,170,"8.  CUBE");
		outtextxy(10,190,"9.  1/X");
		outtextxy(10,210,"10. EXPONENT");
	   /*	outtextxy(10,230,"11. X^1/Y");      */
	      /*	outtextxy(10,250,"12. ");  */
		outtextxy(10,230,"11. FACTORIAL");
		outtextxy(10,250,"12. PERCENTAGE");
		outtextxy(10,270,"13. LOG");
		outtextxy(10,290,"14. REMAINDER");
		outtextxy(10,310,"15. SIN(x)");
		outtextxy(10,330,"16. COS(x)");
		outtextxy(10,350,"17. TAN(x)");
		outtextxy(10,370,"18. COSEC(x)");
		outtextxy(10,390,"19. SEC(x)");
		outtextxy(10,410,"20. COT(x)");
	       // choice line
		line(0,43,160,43);
		line(0,63,160,63);
		line(0,83,160,83);
		line(0,103,160,103);
		line(0,123,160,123);
		line(0,143,160,143);
		line(0,163,160,163);
		line(0,183,160,183);
		line(0,103,160,103);
		line(0,123,160,123);
		line(0,143,160,143);
		line(0,143,160,143);
		line(0,163,160,163);
		line(0,183,160,183);
		line(0,203,160,203);
		line(0,223,160,223);
		line(0,243,160,243);
		line(0,263,160,263);
		line(0,283,160,283);
		line(0,303,160,303);
		line(0,323,160,323);
		line(0,343,160,343);
		line(0,363,160,363);
		line(0,383,160,383);
		line(0,403,160,403);
		line(0,423,160,423);
	    //	line(0,443,160,443);
	      //	line(0,463,160,463);
		setcolor(6);
		bar3d(230,120,620,200,2,2); //Display Screen
		//1 colums
		setcolor(3);
		setfillstyle(SOLID_FILL,YELLOW);
		bar3d(230,240,270,270,2,2);
		bar3d(230,290,270,320,2,2);
		bar3d(230,340,270,370,2,2);
		bar3d(230,390,270,420,2,2);

		//2 colums
		bar3d(280,240,320,270,2,2);
		bar3d(280,290,320,320,2,2);
		bar3d(280,340,320,370,2,2);
		bar3d(280,390,320,420,2,2);

		//3 colums
		bar3d(330,240,370,270,2,2);
		bar3d(330,290,370,320,2,2);
		bar3d(330,340,370,370,2,2);
		bar3d(330,390,370,420,2,2);

		//4 colums
		bar3d(380,240,420,270,2,2);
		bar3d(380,290,420,320,2,2);
		bar3d(380,340,420,370,2,2);
		bar3d(380,390,420,420,2,2);

		//5 colums
		bar3d(430,240,470,270,2,2);
		bar3d(430,290,470,320,2,2);
		bar3d(430,340,470,370,2,2);
		bar3d(430,390,470,420,2,2);
		//6 colums
		bar3d(480,240,520,270,2,2);
		bar3d(480,290,520,320,2,2);
		bar3d(480,340,520,370,2,2);
		bar3d(480,390,520,420,2,2);

		//7 colums
		bar3d(530,240,570,270,2,2);
		bar3d(530,290,570,320,2,2);
		bar3d(530,340,570,370,2,2);
		bar3d(530,390,570,420,2,2);

		//8 colums
		bar3d(580,240,620,270,2,2);
		bar3d(580,290,620,320,2,2);
		bar3d(580,340,620,370,2,2);
		bar3d(580,390,620,420,2,2);

		setcolor(0);
		outtextxy(248,252, "1");
		outtextxy(300,252, "2");
		outtextxy(348,252, "3");
		outtextxy(248,302, "4");
		outtextxy(300,302, "5");
		outtextxy(348,302, "6");
		outtextxy(248,352, "7");
		outtextxy(300,352, "8");
		outtextxy(348,352, "9");

		outtextxy(240,402, "EXP");
		outtextxy(300,402, "0");
		outtextxy(348,402, ".");

		outtextxy(400,252, "+");
		outtextxy(440,252, "sin");
		outtextxy(492,252, "cos");
		outtextxy(540,252, "tan");
		outtextxy(594,252, "AC");

		outtextxy(400,302, "-");
		outtextxy(440,302, "sec");
		outtextxy(482,302, "cosec");
		outtextxy(540,302, "cot");
		outtextxy(590,302, "LOG");

		outtextxy(390,352, "1/X");
		outtextxy(446,352, "X");
		outtextxy(490,352, "10");
		outtextxy(545,352, "X");
		line(595,348,614,348);
		line(590,360,595,348);
		line(590,360,590,353);

		outtextxy(400,400, "/");
		outtextxy(448,400, "X");
		outtextxy(497,400, "*");
		outtextxy(540,400, "rem");
		outtextxy(600,400, "X!");

		settextstyle(0,0,1);
		outtextxy(457,395,"3");
		outtextxy(455,347,"n");
		outtextxy(506,347,"n");
		outtextxy(553,347,"2");

		       }


		void text()
		{
	int choice, i, a, b,c;
	float x, y, result;
	gotoxy(10,2);
	scanf("%d", &choice);
      //	if(choice == 0) exit(0);
	switch(choice)
	 {
	case 1:
	gotoxy(30,9);
	printf("Enter X: ");
	scanf("%f", &x);
	gotoxy(30,10);
	printf("Enter Y: ");
	scanf("%f", &y);
	result = x + y;
	gotoxy(70,12);
	printf("%.1f",result);
	break;
	case 2:
	gotoxy(30,9);
	printf("Enter X: ");
	scanf("%f", &x);
	gotoxy(30,10);
	printf("Enter Y: ");
	scanf("%f", &y);
	result = x - y;
	gotoxy(70,12);
	printf("%.1f" ,result);
	break;
	case 3:
	gotoxy(30,9);
	printf("Enter X: ");
	scanf("%f", &x);
	gotoxy(30,10);
	printf("Enter Y: ");
	scanf("%f", &y);
	result = x * y;
	gotoxy(70,12);
	printf("%.1f",result);
	break;
	case 4:
	gotoxy(30,9);
	printf("Enter X: ");
	scanf("%f", &x);
	gotoxy(30,10);
	printf("Enter Y: ");
	scanf("%f", &y);
	result = x / y;
	gotoxy(70,12);
	printf("%.1f", result);
	break;
	case 5:
	gotoxy(30,9);
	printf("Enter X: ");
	scanf("%f", &x);
	result = sqrt(x);
	gotoxy(70,12);
	printf("%.1f", result);
	break;
	case 6:
	gotoxy(30,9);
	printf("Enter X: ");
	scanf("%f", &x);
	gotoxy(30,10);
	printf("Enter Y: ");
	scanf("%f", &y);
	result = pow(x,y);
	gotoxy(70,12);
	printf("%.1f" ,result);
	break;
	case 7:
	gotoxy(30,9);
	printf("Enter X: ");
	scanf("%f", &x);
	result = pow(x,2);
	gotoxy(70,10);
	printf("%.1f",result);
	break;
	case 8:
	gotoxy(30,9);
	printf("Enter X: ");
	scanf("%f", &x);
	result = pow(x,3);
	gotoxy(70,12);
	printf("%.1f",result);
	break;
	case 9:
	gotoxy(18,5);
	printf("Enter X: ");
	scanf("%f", &x);
	result = pow(x,-1);
	gotoxy(70,12);
	printf("%.2f",result);
	break;
	case 10:
	gotoxy(70,9);
	printf("Enter X: ");
	scanf("%f", &x);
	result = exp(x);
	gotoxy(70,12);
	printf("%.1f",result);
	break;
    /*	case 11:
	gotoxy(30,9);
	printf("Enter X: ");
	scanf("%f", &x);
	result = pow(x, (1/y));
	gotoxy(70,12);
	printf("%.1f",result);
	break;
	case 12:
	gotoxy(30,9);
	printf("Enter X: ");
	scanf("%f", &x);
	result = pow(10,x);
	gotoxy(70,12);
	printf("%.1f",result);
	break;     */
	case 11:
	gotoxy(30,9);
	printf("Enter X: ");
	scanf("%f", &x);
	result = 1;
	for(i = 1; i<= x; i++) {
	result = result * i;
	}
	gotoxy(70,12);
	printf("%.1f",result);
	break;
	case 12:
	gotoxy(30,9);
	printf("Enter X: ");
	scanf("%f", &x);
	gotoxy(30,10);
	printf("Enter Y: ");
	scanf("%f", &y);
	result = (x * y) / 100;
	gotoxy(70,12);
	printf("%.1f",result);
	break;
	case 13:
	gotoxy(30,9);
	printf("Enter X: ");
	scanf("%f", &x);
	gotoxy(70,12);
	result = log(x);
	printf("%.1f",result);
	break;
	case 14:
	gotoxy(30,9);
	printf("Enter X: ");
	scanf("%f", &x);
	gotoxy(30,10);
	printf("Enter Y: ");
	scanf("%f", &y);
	result = a%b;
	gotoxy(70,12);
	printf("%.2f",result);
	break;
	case 15:
	gotoxy(30,9);
	printf("Enter X: ");
	scanf("%f", &x);
	result = sin(x * 3.14159 / 180.00);
	gotoxy(70,12);
	printf("%.2f",result);
	break;
	case 16:
	gotoxy(30,9);
	printf("Enter X: ");
	scanf("%f", &x);
	result = cos(x * 3.14159 / 180);
	gotoxy(70,12);
	printf("%.2f",result);
	break;
	case 17:
	gotoxy(30,9);
	printf("Enter X: ");
	scanf("%f", &x);
	result = tan(x * 3.14159 / 180);
	gotoxy(70,12);
	printf("%.2f",result);
	break;
	case 18:
	gotoxy(30,9);
	printf("Enter X: ");
	scanf("%f", &x);
	result = 1/sin(x * 3.14159 / 180);
	gotoxy(70,12);
	printf("%.2f",result);
	break;
	case 19:
	gotoxy(30,9);
	printf("Enter X: ");
	scanf("%f", &x);
	result = 1/cos(x * 3.14159 / 180);
	gotoxy(70,12);
	printf("%.2f",result);
	break;
	case 20:
	gotoxy(30,9);
	printf("Enter X: ");
	scanf("%f", &x);
	result = 1/tan(x * 3.14159 / 180);
	gotoxy(70,12);
	printf("%.2f",result);
	break;
	}
	getch();
	}
