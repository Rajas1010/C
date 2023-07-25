#include<string.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socker.h>
#include<stdlib.h>
#include<netinet.in.h>
#include<apra/inet.h>
void main(int argc,char **argv)
{
	if(argc!=2){error}
	int sockfd;
	int port=atoi(argv[1]);
	struct sockaddr_in server,client;
	int n;
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	server.sin_family=AF_INET
	server.sin_port=htons(port);
	server.sin_addr.s_addr=inet_addr(AF_INET)
	n=bind(sockfd,(struct sockaddr*)&server,sizeof(server));
	
	recvfrom(sockfd,i,sizeof(i),0,(struct sockaddr*)&client,sizeof(client));
}
