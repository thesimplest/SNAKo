#include<stdio.h>
#include<string.h>
#include <termios.h>
#include<sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "kbhit.h"
#define WIDTH 60
#define HEIGHT 25
char ch1,ch2,name[50]="Khushi",name1[50]="Saurabh",Pyar[3][50]={"TIME","Khushi","Saurabh"};
int gameover,x,y,i,fruitx,fruity,tailx[100]={0},taily[100]={0},ntail=0,score=0,score1=0,ntail1=0,tailx1[100]={0},taily1[100]={0},x1,y1,count=2000,mara=0,count2=0,bonx=0,bony=0,count3=0;
int kbhit();
void Setup();
void Draw ();
void Input();
void Logic();
int main(void)
{
	int i;
	//Game
	Setup();
	while(!gameover)
	{
		Draw();
		Input();
		Logic();
		count--;
		if(count==0)
			gameover=1;
	}
	for(i=0;i<40;i++)
		{
			Draw();
			count3++;
		}
	int j,flag,k,jh;
	while(ntail>=0||ntail1>=0){
	if(ntail<0)
		ntail=0;
	if(ntail1<0)
		ntail1=0;
	system("clear");
	printf("\n\n\n\n                      \t     TIME : %d sec\n\n\n                    ",count/10);
	for(i=0;i<=WIDTH+1;i++)
		printf("#");
	printf("\n");
	for(i=1;i<=HEIGHT;i++)
	{
	printf("                    ");
		for(j=0;j<=WIDTH+1;j++)
		{
			if(i==x && j==y)
				{ printf("%c",name[0]); continue; }
			if(i==x1 && j==y1)
				{printf("%c",name1[0]);continue;}
			flag=0;
			for(k=0;k<=ntail-1;k++)
			{
				if(i==tailx[k] && j==taily[k])
				{
					printf("o");
					flag=1;
				}
			}
			for(k=0;flag==0&&k<=ntail1-1;k++)
			{
				if(i==tailx1[k] && j==taily1[k])
				{
					printf("o");
					flag=1;
				}
			}
			if(flag==1)
				continue;	
			
			else if(i==fruitx && j==fruity)
				printf("@");
			else if(j==0 || j== WIDTH+1)
				printf("#");
			else
				printf(" ");
		}
		
		if(i==4)
				printf("\t\t\t\t%s",name);
		if(i==5)
				printf("\t\t\t\t  %d", score);
		if(i==7)
				printf("\t\t\t\t%s",name1);
		if(i==8)
				printf("\t\t\t\t  %d", score1);
		printf("\n");
	}
	printf("                    ");
	for(i=0;i<=WIDTH+1;i++)
		printf("#");
	printf("\n\n\n\n\n\t\t\t\t\t\t\t\033[1mCopyright : Room 280, Tilak Hostel\n\033[0m");
	usleep(100000);
	ntail--;
	ntail1--;
	}
	if(mara==0)
		{
		if(score>score1)
			mara=1;
		else if(score1>score)
			mara=2;
		}


	//Printing Result
	system("clear");
	printf("\n\n\n\n\n\n\n                    ");
	for(i=0;i<=WIDTH+1;i++)
		printf("#");
	printf("\n");
	for(i=1;i<=HEIGHT;i++)
	{
		printf("                    ");
		for(j=0;j<=WIDTH+1;j++)
		{
			if(i==13 && j==23) { printf("\033[3mWINNER : \033[1m%-8s\033[0m",Pyar[mara]); j=39; }
			else if(j==0 || j== WIDTH+1)
				printf("#");
			else
				printf(" ");
			} 
			printf("\n");
		}
		printf("                    ");
		for(i=0;i<=WIDTH+1;i++)
			printf("#");
			printf("\n");



		sleep(5);
	execlp("./main","./main",NULL);
}
void Setup()
{
	x=HEIGHT/2-6;
	y=WIDTH/2-6;
	x1=HEIGHT/2+6;
	y1=WIDTH/2+6;
	fruitx=rand()%HEIGHT+1;
	fruity=rand()%WIDTH+1;
}
void Draw()
{
	count2++;
	if(count2==30)
	{
		bonx=0;
		bony=0;
	}

	//For Generating Bonus
	if((score+score1)%40==0 && score!=0 && score1!=0)
	{
		bonx=rand()%HEIGHT+1;
		bony=rand()%WIDTH+1;
		score+=10; score1+=10;
		count2=0;
	}
	int j,flag,k,i;
	system("clear");
printf("\n\n\n\n                           \t            TIME : %d sec\n\n\n                    ",count/10);
	for(i=0;i<=WIDTH+1;i++)
		printf("#");
	printf("\n");
	for(i=1;i<=HEIGHT;i++)
	{
	printf("                    ");
		for(j=0;j<=WIDTH+1;j++)
		{
			flag=0;
			if(i==bonx && j==bony) {printf("+"); flag=1;}
			if(i==x && j==y)
				{ printf("%c",'P'); continue; }
			if(i==x1 && j==y1)
				{printf("%c",'S');continue;}
			if(!(mara==2&&(count3)%2==0))
			for(k=0;k<=ntail-1;k++)
			{
				if(i==tailx[k] && j==taily[k])
				{
					printf("o");
					flag=1;
				}
			}
			if(!(mara==1&&(count3)%2==0))
			for(k=0;flag==0&&k<=ntail1-1;k++)
			{
				if(i==tailx1[k] && j==taily1[k])
				{
					printf("o");
					flag=1;
				}
			}
			if(flag==1)
				continue;	
			
			else if(i==fruitx && j==fruity)
				printf("@");
			else if(j==0 || j== WIDTH+1)
				printf("#");
			else
				printf(" ");
		}
		
		if(i==4)
				printf("\t\t\t%s","Khushi");
		if(i==5)
				printf("\t\t\t  %d", score);
		if(i==7)
				printf("\t\t\t%s","Saurabh");
		if(i==8)
				printf("\t\t\t  %d", score1);
		printf("\n");
	}
	printf("                    ");
	for(i=0;i<=WIDTH+1;i++)
		printf("#");
	printf("\n\n\n\n\n\t\t\t\t\t\t\t\033[1mCopyright : Room 280, Tilak Hostel\n\033[0m");
	usleep(100000);

	
}
void Input()
{
	static char ch,ch3=0;

	int t1,t2,t3,t4,i;
		t1=tailx[0]; t2=taily[0];
		tailx[0]=x; taily[0]=y;
		for(i=1;i<=ntail-1;i++)
		{
			t3=tailx[i];
			t4=taily[i];
			tailx[i]=t1;
			taily[i]=t2;
			t1=t3;
			t2=t4;
		}
	t1=tailx1[0]; t2=taily1[0];
		tailx1[0]=x1; taily1[0]=y1;
		for(i=1;i<=ntail1-1;i++)
		{
			t3=tailx1[i];
			t4=taily1[i];
			tailx1[i]=t1;
			taily1[i]=t2;
			t1=t3;
			t2=t4;
		}
	if(kbhit())
	{
		
		ch=getchar();
		if(ch==' ')
		{
			int tmp2=fork();
			if(tmp2==0) execlp("./pause","./pause",NULL);
			if(tmp2!=0) wait(&tmp2);
			if(WEXITSTATUS(tmp2)==2) execlp("./main","./main",NULL);
		}
		if(!((ch=='a' && ch1=='d') || (ch=='d' && ch1=='a') || (ch=='s' && ch1=='w') || (ch=='w' && ch1=='s')||(ch=='1' && ch2=='3') || (ch=='3' && ch2=='1') || (ch=='2' && ch2=='5') || (ch=='5' && ch2=='2'))) 
		{
		if(ch=='a'||ch=='s'||ch=='d'||ch=='w')
			ch1=ch;
		if(ch=='1'||ch=='2'||ch=='3'||ch=='5')
			ch2=ch;
		}
		switch(ch1)
		{
			case 'x':
			case 'X':
				gameover=1;
				break;
			case 'a':
			case 'A':
				if(y==1) y=WIDTH; else y--;
				break;
			case 's':
			case 'S':
				if(x==HEIGHT) x=1; else x++;
				break;
			case 'd':
			case 'D':
				if(y==WIDTH) y=1; else y++;
				break;
			case 'w':
			case 'W':
				if(x==1) x=HEIGHT; else x--;
				break;
			default:
				break;
		}
		switch(ch2)	
		{	
			case '1':
				if(y1==1) y1=WIDTH; else y1--;
				break;
			case '2':
				if(x1==HEIGHT) x1=1; else x1++;
				break;
			case '3':
				if(y1==WIDTH) y1=1; else y1++;
				break;
			case '5':
				if(x1==1) x1=HEIGHT; else x1--;
				break;
			default:
				break;
		}	
	
	}
	else
	{
		switch(ch1)
		{
			case 'x':
			case 'X':
				gameover=1;
				break;
			case 'a':
			case 'A':
				if(y==1) y=WIDTH; else y--;
				break;
			case 's':
			case 'S':
				if(x==HEIGHT) x=1; else x++;
				break;
			case 'd':
			case 'D':
				if(y==WIDTH) y=1; else y++;
				break;
			case 'w':
			case 'W':
				if(x==1) x=HEIGHT; else x--;
				break;
			default: 
				break;
		}
		switch(ch2)
		{		
			case '1':
				if(y1==1) y1=WIDTH; else y1--;
				break;
			case '2':
				if(x1==HEIGHT) x1=1; else x1++;
				break;
			case '3':
				if(y1==WIDTH) y1=1; else y1++;
				break;
			case '5':
				if(x1==1) x1=HEIGHT; else x1--;
				break;
			default:
				break;
		}
	}
}
void Logic()
{
	int i,flag=0;
	for(i=1;i<=ntail-1;i++)
			if(x==tailx[i] && y==taily[i])
			{
				gameover=1;
				mara=2;	
			}
	if(x==fruitx && y==fruity)
	{
		flag=1;
		score+=10;
		ntail1++;
	}
	for(i=1;i<=ntail1-1;i++)
		if(x1==tailx1[i] && y1==taily1[i])
		{
			gameover=1;
			mara=1;	
		}
	if(x1==fruitx && y1==fruity)
	{
		flag=1;
		score1+=10;
		ntail++;
	}
	if(flag==1)
	{
		fruitx=rand()%HEIGHT+1;
		fruity=rand()%WIDTH+1;
	}

	flag=0;
	//Bonus Eating
	if(x==bonx && y==bony)
	{
		score=score+(30-count2)*10;;
		flag=1;
	}
	//Bonus Eating
	if(x1==bonx && y1==bony)
	{
		score1=score1+(30-count2)*10;;
		flag=1;
	}
	if(flag==1)
	{
		bonx=0;
		bony=0;
	}
}
