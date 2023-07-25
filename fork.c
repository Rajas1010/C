#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(int argc , char*argv [])
{
	//int id=fork();
	printf("hello world: %d",(int)getpid());
	fork();
	/*if(id==-1)
		printf("fork not created");
	else if(id==0)
	{
		printf("child");
	}
	else
		printf("parent");*/
	return 0;
} 