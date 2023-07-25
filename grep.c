
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
 int fp,r,i=0,j,k;
 char c,temp[100];
 fp=open(argv[1],O_RDONLY);
 r=read(fp,&c,1);

 while(r)
 {
  temp[i]=c;
  i++;
  if(c=='\n')
  {
   char *buffer=(char*)malloc((i-1)*sizeof(char));
   for(j=0;j<i;j++)
     buffer[j]=temp[j];
   if(strstr(buffer,argv[2])!=NULL)
   {
    for(k=0;k<i;k++)
        printf("%c",buffer[k]);
   }
   i=0;
  }
  r=read(fp,&c,1);
 } 
}
