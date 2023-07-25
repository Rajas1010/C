#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
void main(int argc,char *argv[])
{
 int fd,s;
 char buffer;
 fd=open(argv[1],O_RDONLY);
 if(fd<0)
  printf("File not opened !!");
 else
 {
  s=read(fd,&buffer,1);
  while(s)
  {
   printf("%c",buffer);
   s=read(fd,&buffer,1);
  }
 }
close(fd);
}
