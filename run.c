#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	system("gcc main.c -o main");
	system("gcc one_p.c -o one_p");
	system("gcc two_p.c -o two_p");
	system("gcc high.c -o high");
	system("gcc pause.c -o pause");	
	system("gcc title.c -o title");
	execlp("gnome-terminal", "gnome-terminal", "--full-screen","-x","./main",NULL);
}
