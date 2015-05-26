 //inclusion of header files
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <dos.h>
int chosen[12][2],bet; //global variable declaration for chosen cards and bet
char name[4][50]; //global variable declaration for player name
 //function prototypes
void menu();
void rule();
void comment();
void bet_name();
void disp_numsuit();
void loading();
void rand_numsuit();
void display_cards(int,int);
void border();
void quit();

void main()  //main program
{
	int gdriver=0,gmode;
	initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
	 //initialization of graphic driver
	border();  //function call to display border
	menu();   //function call to display menu
	getch();
}
void menu()
{
	char in;
	start:
	cleardevice();
	border();
	outtextxy(70,50,"Select an option");
	outtextxy(50,70,"1.Play Game");
	outtextxy(50,80,"2.How to Play?");
	outtextxy(50,90,"3.Feedback");
	outtextxy(50,100,"4.Exit");
	 //outtextxy is used to display required text at any coordinate of the screen.alternative of gotoxy
	in=getch();  //option input
	switch(in)
	{
		case '1':
			cleardevice();  //clear screen
			bet_name();  //function call bet_name()
			break;  //exits the switch case condition
		case '2':
			rule();  //function call for rule()
			break;
		case '3':
			comment();  // function call for comment()
			break;
		case '4':
			quit();  //function call quit()
			break;
		default:
			outtextxy(80,120,"Invalid Input");  //default option in switch..case
			getch();
			goto start;
	}
}

void rule()
{
    FILE *rule;  //declaration of file pointer
    char rul;  //character declaration
    cleardevice();
    rule=fopen("rule.txt","r");  //opening of file rule.txt for reading
    if(rule==NULL)
    {
	printf("Error opening rule.txt");  //checking error & displaying error messsage
	    exit(1);
    }
    gotoxy(1,3);
    while(rul!=EOF)  //reads file until end of file rule.txt
    {
	rul=fgetc(rule);  //taking character input from file rule.txt
	putchar(rul);  //displays the character into screen
    }
    fclose(rule);
     //closing of file rule.txt
    outtextxy(50,400,"Press any key to return to main menu....");
    getch();
    cleardevice();
    menu();
     //returning back to main menu
}

void comment()
{   FILE *cmnt;  //declaration of file pointer
    char cmt[60];  //character array declaration
    cleardevice();
	border();
    cmnt=fopen("comment.txt","a"); //opening of file comment.txt for appending
    if(rule==NULL)
	{
	    printf("Error opening comment.txt");  //checking error & displaying error messsage
	    exit(1);
	}
    outtextxy(50,50,"Enter comments about game:");
    gotoxy(5,5);  //sets cursor position to 5,5
    gets(cmt);  //taking input from user
    fprintf(cmnt,"%s\n",cmt); //printing the input from user to a file comment.txt
    fclose(cmnt);
     //closing file comment.txt
    outtextxy(50,100,"Press any key to return to main menu....");
    getch();
    cleardevice();
    menu();
     //retuning to main menu
}

void bet_name()
{
	int i; //variable initialization
	border(); //function call to display border
	outtextxy(50,50,"Enter the name of players");
	 //taking input of four player and stores in  two dimensional array
	for(i=0;i<4;i++)
	{
		gotoxy(3,6+i);
		printf("Player %d: ",i+1);
		scanf("%s",&name[i]);
	}
	outtextxy(50,200,"Enter the bet amount");
	gotoxy(3,15);
	scanf("%d",&bet); // asking bet amount
	cleardevice();
	loading(); //function call loading()
	cleardevice();
	disp_numsuit(); //function call disp_numsuit()
}

void disp_numsuit()
{
	int i,j,x,y;
	int total[4],player[4],highscore=0,hn=0, highscorers[4],temp_total,scorer;
     //declaring variable for looping, displaying number and suits, calculating total of each player and displaying high score and checking multiple high score
	border(); //function call to display border
	display_cards(20,100); //function call to display cards
	rand_numsuit(); //function call to rand_numsuit that generates random cards for four player
	x=5,y=8;  //initializing value
	 //looping to display number and suits in cards
	for (i=0; i<3; i++,x+=1,y=8) //displaying cards with number and suits for player 1
	{
	    sleep(1); //holds execution for 1 second & displays number in cards after 1 second
		gotoxy(x+2,y+2);
		printf("%c",chosen[i][0]);
		for(j=1;j<=2;j++,x+=5,y+=4)
		{
			gotoxy(x,y);
			if (chosen[i][1]==1)    printf("A");
			else if (chosen[i][1]==11)printf("J");
			else if (chosen[i][1]==12) printf("Q");
			else if (chosen[i][1]==13) printf("K");
			else  printf("%d\n", chosen[i][1]);
		}
		 //displaying number and suit in each card
	}
	x=5,y=20;
	for (i=3; i<6; i++,x+=1,y=20) //displaying cards with number and suits for player 2
	{
	    sleep(1); //holds execution for 1 second & displays number in cards after 1 second
		gotoxy(x+2,y+2);
		printf("%c",chosen[i][0]);
		for(j=1;j<=2;j++,x+=5,y+=4)
		{
			gotoxy(x,y);
			if (chosen[i][1]==1)    printf("A");
			else if (chosen[i][1]==11)printf("J");
			else if (chosen[i][1]==12) printf("Q");
			else if (chosen[i][1]==13) printf("K");
			else  printf("%d\n", chosen[i][1]);
		}
		 //displaying number and suit in each card
	}
	x=46,y=8;
	for (i=6; i<9; i++,x+=1,y=8) //displaying cards with number and suits for player 3
	{
	    sleep(1); //holds execution for 1 second & displays number in cards after 1 second
		gotoxy(x+2,y+2);
		printf("%c",chosen[i][0]);
		for(j=1;j<=2;j++,x+=5,y+=4)
		{
			gotoxy(x,y);
			if (chosen[i][1]==1)    printf("A");
			else if (chosen[i][1]==11)printf("J");
			else if (chosen[i][1]==12) printf("Q");
			else if (chosen[i][1]==13) printf("K");
			else  printf("%d\n", chosen[i][1]);
		} //displaying number and suit in each card
	}
	x=46,y=20;
	for (i=9; i<12; i++,x+=1,y=20) //displaying cards with number and suits for player 4
	{
	    sleep(1); //holds execution for 1 second & displays number in cards after 1 second
		gotoxy(x+2,y+2);
		printf("%c",chosen[i][0]);
		for(j=1;j<=2;j++,x+=5,y+=4)
		{
			gotoxy(x,y);
			if (chosen[i][1]==1)    printf("A");
			else if (chosen[i][1]==11)printf("J");
			else if (chosen[i][1]==12) printf("Q");
			else if (chosen[i][1]==13) printf("K");
			else  printf("%d\n", chosen[i][1]);
		}
		 //displaying number and suit in each card
	}
	for(i=0;i<12;i++)
	{
		if(chosen[i][1]>10)
		chosen[i][1]=10;
	}
	 //setting the value 10 to the cards with value more than 10
	total[0]=chosen[0][1]+chosen[1][1]+chosen[2][1];
	total[1]=chosen[3][1]+chosen[4][1]+chosen[5][1];
	total[2]=chosen[6][1]+chosen[7][1]+chosen[8][1];
	total[3]=chosen[9][1]+chosen[10][1]+chosen[11][1];
     //calculating total of 4 player
	for (i=0; i<4; i++) //taking the value of unit place from total of each player
	{
		temp_total=total[i];
		player[i]=temp_total%10;
	}

	for (i=0; i<4; i++) //checking the highest score
	{
		if (player[i] > highscore) highscore = player[i];
	}
	for (i=0; i<4; i++) //checking for multiple high score
	{
		if (player[i] == highscore)
		{
			highscorers[hn] = i;
			hn += 1;
		}
	}
	getch();
	cleardevice();
	border(); //function call to display border
	cleardevice();
	border(); //function call to display border
	gotoxy(5,5);
	printf("Highest Score = %i \n\n", highscore); //set cursor position to 5,5 and displays the information
	gotoxy(5,6);
	if (hn>1)
	{
		printf("And there is draw between...");
		bet=2*bet; //doubling the bet
	}
	else
		printf("And the winner is...");
		 //displaying the winner or the player having draw result
	for (i=0; i<hn; i++)
	{
	    scorer=highscorers[i]+1;
		gotoxy(5,7+i);
		printf("PLAYER  %d: %s",scorer,name[scorer-1]);
	}
	if (hn==1)
	{
		gotoxy(5,11);
		printf("The total prize won is Rs. %d" ,4*bet); //displaying total win amount
		sleep(2);
		quit(); //function call quit()
	}
	else
	{
	     //redistributing cards
		outtextxy(50,200,"The cards will load again after you press a key");
		getch();
		cleardevice();
		loading(); //function call loading()
		cleardevice();
		disp_numsuit(); //self function call
	}
}

void loading()
{
	int i; //variable initialization
	for(i=1;i<=100;i++)  //looping statement
	{
		outtextxy(160,200,"Shuffling the deck... Please wait");  //displays Shuffling the deck... Please wait
		gotoxy(43,16); //sets cursor position to 43,16
		printf("%d%",i); //displays i
		line(225+i,242,225+i,250); //draws a line
		rectangle(225,241,326,251); //draws a rectangle
		delay(50); //holds execution for 50 millisecond
    }
}

void rand_numsuit()
{
    int x,y,i;
    int cnt=0,rn,symbol,value,ischosen;
    int allcards[52][2];
     //declaring variable for looping, choosing random cards
     //loop to create an 2D array as a deck of cards
    for (i=0;i<52;i++)
    {
		value = (i%13)+1;
		if (i<13)               symbol = 3;
		else if (i>=13 && i<26) symbol = 4;
		else if (i>=26 && i<39) symbol = 5;
		else                    symbol = 6;
		allcards[i][0] = symbol;
		allcards[i][1] = value;
	}
	srand(time(NULL));
	 //loop to take 12 random cards
	while (cnt < 12)
	{
		rn = rand() % 52;
		symbol = allcards[rn][0];
		value  = allcards[rn][1];
		ischosen=0;
		 //condition to check for two same cards
		for (i=0; i<cnt; i++)
			if (symbol==chosen[i][0] && value==chosen[i][1]) ischosen=1;
		if (ischosen==0)
		{
			chosen[cnt][0] = symbol;
			chosen[cnt][1] = value;
			cnt++;
		}
	}
}

void display_cards(x,y)
{
	int i,j,p1=14,p2=4,k,l,p3=55,p4=4; //declaring variable for looping and displaying player name corresponding to their cards
	 //loop for displaying outline of player 1 and player 2 cards
	for(i=1;i<=2;i++)
	{
		for(j=1;j<=3;j++)
		{
			gotoxy(p1,p2);  //set cursor position to p1,p2
			printf("PLAYER %d: %s",i,name[i-1]);  //displaying player name and number
			rectangle(x,y,x+70,y+100);  //draw rectangle of cards
			x+=90; //increasing value of x coordinate to display next card
		}
		x-=270;
		y+=190,p2+=12;
		 //value increment to display cards for player two
	}
	x=350,y=100; //initialization of value to print cards for player 3 and player 4
	 //loop for displaying outline of player 3 and player 4 cards
	for(k=3;k<=4;k++)
	{
		for(l=1;l<=3;l++)
		{
			gotoxy(p3,p4);  //set cursor position to p3,p4
			printf("PLAYER %d: %s",k,name[k-1]); //displaying player name and number
			rectangle(x,y,x+70,y+100);  //draw rectangle of cards
			x+=90; //increasing value of x coordinate to display next card
		}
		x-=270;
		y+=190,p4+=12;
		 //value increment to display cards for player two
	}
}

void border()
{
	rectangle(5,10,625,460);
	rectangle(10,15,620,455);
	 //draws rectangle
}

void quit()
{
	int h,k,r; //variable declaration
	srand((unsigned) time(NULL));
	outtextxy(400,400,"Press any key to exit");
	while(!kbhit()) //looping structure that terminates after keyboard hit
	{
		h=rand()%550;
		k=rand()%400;
		r=rand()%20;
		 //taking random value in h,k,r
		setcolor(r); //setting color for circle to be displayed
		r+=10;
		h+=30,k+=30;
		circle(h,k,r); //displays circle of center h,k and radius r
		delay(300); //holds execution for 300 millisecond
	}
}