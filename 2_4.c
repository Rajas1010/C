#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
void main()
{
     int a[2],e,p,n,f;
     p=pipe(a);
     double o;
     if(p==-1)
		printf("Pipe cannot be created");
     else{
                f=fork();
                if(f<0)
                     printf("Process can't be created");
                if(f==0)
				{
                     printf("Enter Year to check Leap Year or not:");
                     scanf("%d",&n);
                     close(a[0]);
                     write(a[1],&n,sizeof(n));
                }
                if(f>0){
                        close(a[1]);
                        read(a[0],&n,sizeof(n));
                        int b;
                        b=n;
                        if(b%4==0)
                                printf("Given year is leap year\n");
                        else
                                printf("Given year is not leap year\n");
                        }
        }
}