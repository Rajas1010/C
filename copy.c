#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
void main(int argc,char *argv[])
{
		int fd,fp,s;
			char buffer;
				fd=open(argv[1],O_RDONLY);
					fp=open(argv[2],O_WRONLY);
						if(fd<0)
							printf("File not opened !!");
						else
						{
							s=read(fd,&buffer,1);
							while(s)
						{
							write(fp,&buffer,1);
							s=read(fd,&buffer,1);
						}
						}
				close(fd);
			close(fp);
}
