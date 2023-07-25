#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
void main(){
        int fd,f;
        char buf[100];
        int a[2],p1;
        p1=pipe(a);
        if(p1==-1)
                printf("Pipe can't be opened");
        else{
                fd=open("f1.txt",O_RDONLY);
                if(fd==-1){
                        printf("File can't be created");}
                else{
                        f=fork();
                        if(f<0)
                                printf("Process can't be created");
                        if(f>0){
                                close(a[0]);
                                read(fd,&buf,sizeof(buf));
                                write(a[1],buf,sizeof(buf));}
                        if(f==0){
                                close(a[1]);
                                read(a[0],&buf,sizeof(buf));
                                write(0,buf,sizeof(buf));
                        }
                }
        }
}