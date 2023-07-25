#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define MAX 10

void main()
{	
	char *ip="127.0.0.1";
	char a[100];
	int port;
	printf("Enter the Port Number");
	scanf("%d",&port);

	int sock;
	struct sockaddr_in addr;
	socklen_t addr_size;
	char buffer[1024];
	int n;
	
	sock=socket(AF_INET,SOCK_STREAM,0);
	if(sock<0)
		 exit(1);
	printf("TCP Server Socket Created.\n");

	addr.sin_family=AF_INET;
	addr.sin_port=port;
	addr.sin_addr.s_addr=inet_addr(ip);
	
	connect(sock,(struct sockaddr*)&addr,sizeof(addr));
	printf(" Connected To Server\n");
	
	int G[MAX][MAX],i,j,n,u;
	printf("Enter no. of vertices:");
	scanf("%d",&n);
	send(sock,&n,sizeof(n),0);
	printf("\nEnter the adjacency matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
	send(sock,&G,sizeof(G),0);
	
	printf("\nEnter the starting node:");
	scanf("%d",&u);
	send(sock,&u,sizeof(u),0);
	
	
	//recv(sock,buffer,sizeof(buffer),0);
	//printf("Server : %s\n",buffer);
	close(sock);
	printf("Disconnect The Server");
}
