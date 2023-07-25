#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>
#include <fcntl.h>

void match_pattern(char *argv[])
{
    int fd,r,j=0,count=0;
    char temp,line[100];
    if((fd=open(argv[2],O_RDONLY)) != -1)
    {
        while((r=read(fd,&temp,sizeof(char)))!= 0)
        {
            if(temp!='\n')
            {
                line[j]=temp;
                j++;
            }
            else
            {
                if(strstr(line,argv[1])!=NULL)
{
