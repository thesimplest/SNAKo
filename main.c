#include<stdio.h>
#include<stdlib.h>
#include "kbhit.h"
int main()
{
	int i=1,tabc=53,j;
	char ch;

	system("./title");


	//Printing Main Menu
	while(1)
	{
		usleep(100000);
		system("clear");
		printf("\n\n\n\n\n\n\n");
		for(j=0;j<=tabc;j++)printf(" ");	printf("  ####   #    #    ##    #    #   ####\n");
		for(j=0;j<=tabc;j++)printf(" ");	printf(" #       ##   #   #  #   #   #   #    #\n");
		for(j=0;j<=tabc;j++)printf(" ");	printf("  ####   # #  #  #    #  ####    #    #\n");
		for(j=0;j<=tabc;j++)printf(" ");	printf("      #  #  # #  ######  #  #    #    #\n");
		for(j=0;j<=tabc;j++)printf(" ");	printf(" #    #  #   ##  #    #  #   #   #    #\n");
		for(j=0;j<=tabc;j++)printf(" ");	printf("  ####   #    #  #    #  #    #   ####\n");	
		printf("\n\t\t\t\t\t\t\t\t\033[1m!!FEED THE HUNGRY SNAKE!!\n\n\n\033[0m");
		printf("\t\t\t\t\t\t1. Length of the tail increases as the snake eats '@'.\n");
		printf("\t\t\t\t\t\t2. Each '@' eaten earns 10 points.\n");
		printf("\t\t\t\t\t\t3. Eat special food '+' to earn a maximum of 300 points depending on time.\n");
		printf("\t\t\t\t\t\t4. Game gets over when snake collides with itself.\n\n"); 
		printf("\t\t\t\t\t\tIn 2 Player Mode :\n");
		printf("\t\t\t\t\t\t5. When one will eat, other will be fed.\n");
		printf("\t\t\t\t\t\t6. When time ends, Player with high score will win the game.\n\n");
		printf("\t\t\t\t\t\tControls : UP-w, DOWN-s\n");
		printf("\t\t\t\t\t\tPlayer 1 : a-LEFT, d-RIGHT, w-UP, s-DOWN, space-pause, x-terminate\n");
		printf("\t\t\t\t\t\tPlayer 2 : 1-LEFT, 3-RIGHT, 5-UP, 2-DOWN, space-pause\n\n\n");
		printf("\t\t\t\t     \033[1m\t\t\t\t%c  PLAY\n     \t\t\t\t\t\t\t\t%c  HIGH SCORES\n      \t\t\t\t\t\t\t\t%c  EXIT\n\033[0m",((i==1)?'*':' '), ((i==2)?'*':' '), ((i==3)?'*':' '));
		printf("\n\n\n\n\t\t\t\t\t\t\t\033[1mCopyright : Room 280, Tilak Hostel\n\n\n\033[0m");
		while(!kbhit());
		ch=getchar();
		if(ch=='s') i++;
		else if(ch=='w') i--;
		else if(ch=='\n') break;
		if(i==4) i=1;
		if(i==0) i=3;		
	}





	label:
	//Printing Play Menu
	if(i==1)
	{
		while(1)
		{
			usleep(100000);
			system("clear");
			printf("\n\n\n\n\n\n\n");
		for(j=0;j<=tabc;j++)printf(" ");	printf("  ####   #    #    ##    #    #   ####\n");
		for(j=0;j<=tabc;j++)printf(" ");	printf(" #       ##   #   #  #   #   #   #    #\n");
		for(j=0;j<=tabc;j++)printf(" ");	printf("  ####   # #  #  #    #  ####    #    #\n");
		for(j=0;j<=tabc;j++)printf(" ");	printf("      #  #  # #  ######  #  #    #    #\n");
		for(j=0;j<=tabc;j++)printf(" ");	printf(" #    #  #   ##  #    #  #   #   #    #\n");
		for(j=0;j<=tabc;j++)printf(" ");	printf("  ####   #    #  #    #  #    #   ####\n");	
		printf("\n\t\t\t\t\t\t\t\t\033[1m!!FEED THE HUNGRY SNAKE!!\n\n\n\033[0m");
		printf("\t\t\t\t\t\t1. Length of the tail increases as the snake eats '@'.\n");
		printf("\t\t\t\t\t\t2. Each '@' eaten earns 10 points.\n");
		printf("\t\t\t\t\t\t3. Eat special food '+' to earn a maximum of 300 points depending on time.\n");
		printf("\t\t\t\t\t\t4. Game gets over when snake collides with itself.\n\n"); 
		printf("\t\t\t\t\t\tIn 2 Player Mode :\n");
		printf("\t\t\t\t\t\t5. When one will eat, other will be fed.\n");
		printf("\t\t\t\t\t\t6. When time ends, Player with high score will win the game.\n\n");
		printf("\t\t\t\t\t\tControls : UP-w, DOWN-s\n");
		printf("\t\t\t\t\t\tPlayer 1 : a-LEFT, d-RIGHT, w-UP, s-DOWN, space-pause\n");
		printf("\t\t\t\t\t\tPlayer 2 : 1-LEFT, 3-RIGHT, 5-UP, 2-DOWN, space-pause\n\n\n");
			printf("\t\t\t\t     \033[1m\t\t\t\t%c  1 PLAYER\n\t\t\t\t     \t\t\t\t%c  2 PLAYER\n\033[0m",((i==1)?'*':' '), ((i==2)?'*':' '));
		printf("\n\n\n\n\n\t\t\t\t\t\t\t\033[1mCopyright : Room 280, Tilak Hostel\n\n\n\033[0m");
			while(!kbhit());
			ch=getchar();
			if(ch=='s') i++;
			else if(ch=='w') i--;
			else if(ch=='\n') break;
			if(i==3) i=1;
			if(i==0) i=2;
		}
		if(i==1) execlp("./one_p", "./one_p",NULL);
		else if(i==2) execlp("./two_p","./two_p",NULL);	
	}





	//Printing High Scores
	else if(i==2) 
	{
		i=1;
		while(1)
		{
			usleep(100000);
			system("clear");
			printf("\n\n\n\n\n\n\n");
		for(j=0;j<=tabc;j++)printf(" ");	printf("  ####   #    #    ##    #    #   ####\n");
		for(j=0;j<=tabc;j++)printf(" ");	printf(" #       ##   #   #  #   #   #   #    #\n");
		for(j=0;j<=tabc;j++)printf(" ");	printf("  ####   # #  #  #    #  ####    #    #\n");
		for(j=0;j<=tabc;j++)printf(" ");	printf("      #  #  # #  ######  #  #    #    #\n");
		for(j=0;j<=tabc;j++)printf(" ");	printf(" #    #  #   ##  #    #  #   #   #    #\n");
		for(j=0;j<=tabc;j++)printf(" ");	printf("  ####   #    #  #    #  #    #   ####\n");	
		printf("\n\t\t\t\t\t\t\t\t\033[1m!!FEED THE HUNGRY SNAKE!!\n\n\n\033[0m");
			system("./high 0");
			printf("\n\n\n");
			printf("\t\t\t\t     \033[1m\t\t\t\t%c  PLAY\n\t\t\t\t     \t\t\t\t%c  HIGH SCORES\n\t\t\t\t     \t\t\t\t%c  EXIT\n\033[0m",((i==1)?'*':' '), ((i==2)?'*':' '), ((i==3)?'*':' '));
			printf("\n\n\n\n\t\t\t\t\t\t\t\033[1mCopyright : Room 280, Tilak Hostel\n\n\n\033[0m");
			while(!kbhit());
			ch=getchar();
			if(ch=='s') i++;
			else if(ch=='w') i--;
			else if(ch=='\n') break;
			if(i==4) i=1;
			if(i==0) i=3;		
		}
		goto label;
	}



	//Exiting
	else if(i==3) 	exit(1);
}
