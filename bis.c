#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char a[100]="RaytyhgfgttdyFGHFFj\0";
	char b[100]="seghHGKHJGhghkKjhgHFytfKhjGHFFkar\0";
	strcat(a,b);
	char c[strlen(a)];
	c[0]='\0';
	for (int i=0;i<strlen(a);i++)
	{
		c[i]=(char)((int)a[i]+100);
		c[i+1]='\0';
	}
	printf("%s\n",c);
	for (int i=0;i<strlen(c);i++)
		printf("%c",(int)c[i]-100);
	return 0;
}