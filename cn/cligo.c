#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

void main()
{
	
	char *ip="127.0.0.1";
	char a[100];
	int port=5566;
	
	int sock;
	struct sockaddr_in addr;
	socklen_t addr_size;
	char buffer[1024];
	int n,c,choice;
	
	sock=socket(AF_INET,SOCK_STREAM,0);
	if(sock<0)
	{
		perror("[-]Socket error");
		exit(1);
	}
	printf("[+]TCP server socket created.\n");
	memset(&addr,'\0',sizeof(addr));
	addr.sin_family=AF_INET;
	addr.sin_port=port;
	addr.sin_addr.s_addr=inet_addr(ip);
	connect(sock,(struct sockaddr*)&addr,sizeof(addr));
	printf("client");
	printf("connect");
	printf("Enter the number of frames");
	scanf("%d",&c);
	send(sock,c,strlen(c),0);
	printf("error=1, no error=0");
	scanf("%d",&choice);
	send(sock,choice,strlen(choice),0);
	int check=0,i=0,j=0;
	if(choice==0)
	{
		for(j=0;j<c;j++)
		{
			recv(sock,i,sizeof(i),0);
			printf("received frame no : %d",i);
			printf("sending ack : %d",i);
			send(sock,i,strlen(i),0);
		}
	}
	else
	{
		for(j=0;j<c;j++)
		{
			recv(sock,i,sizeof(i),0);
			if(i==check)
			{
				printf("i %d check %d",i,check);
				printf("received frame no : %d",i);
				printf("sending ack : %d",i);
				send(sock,i,strlen(i),0);
				check++;
			}
			else
			{
				j--;
				send(sock,-1,strlen(-1),0);
			}
		}
	}
	close(sock);
}

