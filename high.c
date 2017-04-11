//Takes the score made as command line argument
//Compares it with the existing top 3 high scores
//Update the data(if necessary)
//Print on screen
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
void copy(char*dest,char*src) { int i; for(i=0;i<=49;i++) dest[i]=src[i]; }
int main(int argc, char*argv[])
{
	char str1[50],str2[50],str3[50],str[50];
	system("chmod 0777 high_name.txt");
	system("chmod 0777 high_scores.txt");
	int s1,s2,s3,sc;
	FILE *fp1,*fp2;
	fp1=fopen("high_name.txt","r");
	fp2=fopen("high_scores.txt","r");
	fscanf(fp1,"%[^\n]",str1);
	fscanf(fp1,"\n%[^\n]",str2);
	fscanf(fp1,"\n%[^\n]",str3);
	fscanf(fp2,"%d",&s1);
	fscanf(fp2,"%d",&s2);
	fscanf(fp2,"%d",&s3);
	sscanf(argv[1],"%d", &sc);
	if(sc >= s1 || sc >= s2 || sc >=s3)
	{
		printf("\t\t\t\t\t\t\t          \033[1mCONGRATULATIONS\n\t\t\t\t\t\t\t       You Made a HIGH SCORE\n\t\t\t\t\t\t\t    Enter Your Name: \033[0m");
		gets(str);
	}
	if(sc>s1)
	{
		copy(str3,str2);	s3=s2;
		copy(str2,str1);	s2=s1;
		copy(str1,str);	s1=sc;
	}
	else if(sc>s2)
	{
		copy(str3,str2);	s3=s2;
		copy(str2,str);	s2=sc;
	}
	else if(sc>s3)
	{
		copy(str3,str);	s3=sc;
	}
	fp1=fopen("high_name.txt","w");
	fprintf(fp1,"%-10s\n%-10s\n%-10s\n",str1,str2,str3);
	fp2=fopen("high_scores.txt","w");
	fprintf(fp2,"%d\n%d\n%d\n", s1,s2,s3);		
	printf("\n\n\n\t\t\t\t\t\t\t\t    \033[1mHIGH SCORES\033[0m\n\n");
	printf("\t\t\t\t\t\t\t    1. %s\t%d\n\t\t\t\t\t\t\t    2. %s\t%d\n\t\t\t\t\t\t\t    3. %s\t%d\n\n\n", str1,s1,str2,s2,str3,s3);
	fclose(fp1); fclose(fp2);
	system("chmod 0000 high_name.txt");
	system("chmod 0000 high_scores.txt");	
}
	
