#include<stdio.h>
#include "kbhit.h"
#include <stdlib.h>
#define WIDTH 60
#define HEIGHT 25
int main(void)
{
	int i=1,choice=1,j;
	char ch,str[50];
	while(1)
	{
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
				if(i==11 && j==26) { printf("\033[1mPAUSE MENU\033[0m"); j=35; }
				else if(i==13 && j==26) { printf("%c  Resume",((choice==1)?'*':' ')); j=34; }
				else if(i==14 && j==26) { printf("%c  Main Menu",((choice==2)?'*':' ')); j=37; }
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
		printf("\n\n\n\n\t\t\t\t\t\t\t\033[1mCopyright : Room 280, Tilak Hostel\n\033[0m");
		while(!kbhit());
		ch=getchar();
		if(ch=='s') choice++;
		else if(ch=='w') choice--;
		else if(ch=='\n') break;
		if(choice==3) choice=1;
		if(choice==0) choice=2;
		usleep(100000);
	}
	if(choice==1)  return 1;
	if(choice==2)  return 2;
}
