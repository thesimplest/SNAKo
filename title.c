#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(void)
{
	printf("\033[1m");
	int tabc=0,i;
	while(tabc<53)
	{
	system("clear");
	printf("\n\n\n\n\n\n\n");
	for(i=0;i<=tabc;i++)printf(" ");	printf("  ####   #    #    ##    #    #   ####\n");
	for(i=0;i<=tabc;i++)printf(" ");	printf(" #       ##   #   #  #   #   #   #    #\n");
	for(i=0;i<=tabc;i++)printf(" ");	printf("  ####   # #  #  #    #  ####    #    #\n");
	for(i=0;i<=tabc;i++)printf(" ");	printf("      #  #  # #  ######  #  #    #    #\n");
	for(i=0;i<=tabc;i++)printf(" ");	printf(" #    #  #   ##  #    #  #   #   #    #\n");
	for(i=0;i<=tabc;i++)printf(" ");	printf("  ####   #    #  #    #  #    #   ####\n");
	tabc++;	
	usleep(50000);
	}	
	printf("\033[0m");
	
}
