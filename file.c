#include<stdio.h>
#include<stdlib.h>
void main()
{
	FILE *p=NULL;
	char c='a';
	p=fopen("abc.txt","w");
	if(p==NULL)
	{
		printf("error");
	}
	fputc(c,p);
	fclose(p);
}
