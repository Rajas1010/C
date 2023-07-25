#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
void main(){
        int a,b,c;
        a=fork();
        b=fork();
        if(a<0||b<0)
                printf("Process can't be created");
        else{
                if(a==0 && b>0)
                        c=fork();
                if(c<0)
                        printf("Process can't be created");
                else{
                        if(a>0 && b>0)
                                printf("Process's id is %d\n",getpid()); 
                        if(a>0&& b==0){
                                printf("Process's id is %d\n",getpid());
                                printf("Parent's Process's id is %d\n",getppid());}
                        if(a==0 && b>0 && c>0){
                                printf("Process's id is %d\n",getpid());
                                printf("Parent's Process's id is %d\n",getppid());}
                        if(a==0 && b==0){
                                printf("Process's id is %d\n",getpid());
                                printf("Parent's Process's id is %d\n",getppid());}
                        if(a==0&&b>0&&c==0){
                                printf("Process's id is %d\n",getpid());
                                printf("Parent's Process's id is %d\n",getppid());}
                }
        }
}
 