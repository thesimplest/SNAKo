#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<sys/wait.h>
#include "kbhit.h"
#define WIDTH 60
#define HEIGHT 25
int gameover,x,y,fruitx,fruity,tailx[1000]={0},taily[1000]={0},ntail=0,score=0,bonx=0,bony=0,count=0,count2=0,count3=0;
void Setup();
void Draw ();
void Input();
void Logic();
int main(void)
{
	Setup();
	while(!gameover)
	{
		Draw();
		Input();
		Logic();
	}




	//Reduces tail length to 0
	int j,i,flag,k,jh;
	while(ntail>=0){
	
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
			if(i==x && j==y)
				{ printf("O"); continue; }
			flag=0;
			for(k=0;k<=ntail-1;k++)
			{
				if(i==tailx[k] && j==taily[k])
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
		if(i==4) printf("\t\t\tSCORE");
		else if(i==5) printf("\t\t\t %d", score); 
		printf("\n");
	}
	printf("                    ");
	for(i=0;i<=WIDTH+1;i++)
		printf("#");
		printf("\n");
	printf("\n\n\n\n\n\t\t\t\t\t\t\t\033[1mCopyright : Room 280, Tilak Hostel\n\033[0m");
	ntail--;
	usleep(100000);
	}
	sleep(2);
	system("clear");
	printf("\n\n\t\t\t\t\t\t\t          Your Score : %d\n\n\n",score); 
	char str[50];
	sprintf(str,"./high %d", score);
	system(str);
	sleep(10);
	execlp("./main","./main",NULL);
}





void Setup()
{
	x=HEIGHT/2;
	y=WIDTH/2;
	fruitx=rand()%HEIGHT+1;
	fruity=rand()%WIDTH+1;
}





void Draw()
{
	count++;count2++;count3++;


	//For Changing Food position after certain interval
	if(count==100) 
	{
		fruitx=rand()%HEIGHT+1;
		fruity=rand()%WIDTH+1;
		count=0;
	}

	if(count2==30)
	{
		bonx=0;
		bony=0;
	}
	//For Generating Bonus
	if(score%40==0 && score!=0)
	{
		bonx=rand()%HEIGHT+1;
		bony=rand()%WIDTH+1;
		score+=10;
		count2=0;
	}	

		
	int j,flag,k,i;
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
			if(i==x && j==y) { printf("O"); continue; }
			flag=0;
			for(k=0;k<=ntail-1;k++)
			{
				if(i==tailx[k] && j==taily[k])
				{
					printf("o");
					flag=1;
				}
			}
			if(flag==1)
				continue;	
			
			else if(i==fruitx && j==fruity)
				printf("@");
			else if(i==bonx && j==bony)
				printf("+");
			else if(j==0 || j== WIDTH+1)
				printf("#");
			else
				printf(" ");
		}
		if(i==4) printf("\t\t\tSCORE");
		else if(i==5) printf("\t\t\t %d", (score/10)*10); 
		printf("\n");	

	}
	printf("                    ");
	for(i=0;i<=WIDTH+1;i++)
		printf("#");
	printf("\n");
	printf("\n\n\n\n\t\t\t\t\t\t\t\033[1mCopyright : Room 280, Tilak Hostel\n\033[0m");
	usleep(100000-count3);	
}





void Input()
{
	static char ch,ch2=0,tmp, str[50];
	int tmp2;

	//Updating The tail
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


	if(kbhit()) ch2=getchar();
	tmp=ch;
	if(!((ch=='a' && ch2=='d') || (ch=='d' && ch2=='a') || (ch=='s' && ch2=='w') || (ch=='w' && ch2=='s'))  &&  (ch2=='x' || ch2=='a' || ch2=='d' || ch2=='w' || ch2=='s' || ch2==' ')) ch=ch2;

	switch(ch)
	{
		case 'x':
			gameover=1;
			break;
		case 'a':
			if(y==1) y=WIDTH; else y--;
			break;
		case 's':
			if(x==HEIGHT) x=1; else x++;
			break;
		case 'd':
			if(y==WIDTH) y=1; else y++;
			break;
		case 'w':
			if(x==1) x=HEIGHT; else x--;
			break;
		case ' ':
			tmp2=fork();
			if(tmp2==0) execlp("./pause","./pause",NULL);
			if(tmp2!=0) wait(&tmp2);
			if(WEXITSTATUS(tmp2)==2) execlp("./main","./main",NULL);
			ch2=tmp;
	}	
}





void Logic()
{
	int i;

	//Gameover Condition
	for(i=1;i<=ntail-1;i++)
		if(x==tailx[i] && y==taily[i])
			gameover=1;

	//Fruit Eating 
	if(x==fruitx && y==fruity)
	{
		fruitx=rand()%HEIGHT+1;
		fruity=rand()%WIDTH+1;
		score=score+10;
		ntail++;
		count=0;
	}

	//Bonus Eating
	if(x==bonx && y==bony)
	{
		score=score+(30-count2)*10;;
		bonx=0;
		bony=0;
	}	
}
