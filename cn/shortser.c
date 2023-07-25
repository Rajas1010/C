#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <arpa/inet.h>
#define INFINITY 9999
#define MAX 10

void main()
{
	char *ip="127.0.0.1";
	int *p;
	int port;
	printf("Enter the Port Number");
	scanf("%d",&port);
	char c[512];
	int server_sock,client_sock;
	struct sockaddr_in server_addr,client_addr;
	socklen_t addr_size;
	char buffer[1024];
	int n,i, buff_len;
	auto void  dijkstra();
	server_sock=socket(AF_INET,SOCK_STREAM,0);
	if(server_sock<0)
	{
		 perror("Socket error");
		 exit(1);
	}
	printf("TCP server socket created.\n");
	
	
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=port;
	server_addr.sin_addr.s_addr=inet_addr(ip);
	
	n=bind(server_sock,(struct sockaddr*)&server_addr,sizeof(server_addr));
	if(n<0)
		exit(1);
	printf("Bind to the port number:%d\n",port);
	
	listen(server_sock,5);
	printf("Listening \n");
	
	addr_size=sizeof(client_addr);
	client_sock=accept(server_sock, (struct sockaddr*)&client_addr, &addr_size);
	printf("Client Connected.\n");	
	int G[MAX][MAX],u;	
	
	recv(client_sock,&n, sizeof(n),0);
	recv(client_sock,&G, sizeof(G),0);
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			G[i][j]=*p;
			p++;
		}
		recv(client_sock,&u, sizeof(u),0);
		dijkstra(G,n,u);

	void dijkstra(int G[MAX][MAX],int n,int startnode)
	{
	
		int cost[MAX][MAX],distance[MAX],pred[MAX];
		int visited[MAX],count,mindistance,nextnode,i,j;
		
		//pred[] stores the predecessor of each node
		//count gives the number of nodes seen so far
		//create the cost matrix
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(G[i][j]==0)
					cost[i][j]=INFINITY;
				else
					cost[i][j]=G[i][j];
		
		//initialize pred[],distance[] and visited[]
		for(i=0;i<n;i++)
		{
			distance[i]=cost[startnode][i];
			pred[i]=startnode;
			visited[i]=0;
		}
		
		distance[startnode]=0;
		visited[startnode]=1;
		count=1;
		
		while(count<n-1)
		{
			mindistance=INFINITY;
			
			//nextnode gives the node at minimum distance
			for(i=0;i<n;i++)
				if(distance[i]<mindistance&&!visited[i])
				{
					mindistance=distance[i];
					nextnode=i;
				}
				
				//check if a better path exists through nextnode			
				visited[nextnode]=1;
				for(i=0;i<n;i++)
					if(!visited[i])
						if(mindistance+cost[nextnode][i]<distance[i])
						{
							distance[i]=mindistance+cost[nextnode][i];
							pred[i]=nextnode;
						}
			count++;
		}
	
		//print the path and distance of each node
		for(i=0;i<n;i++)
			if(i!=startnode)
			{
				printf("\nDistance of node%d=%d",i,distance[i]);
				printf("\nPath=%d",i);
				
				j=i;
				do
				{
					j=pred[j];
					printf("<-%d",j);
				}while(j!=startnode);
		}
	}	
	printf("Data Forwarded To Client : %s\n",c);
	//send(client_sock,c,strlen(c),0);
	close(client_sock);
	printf("Client Disconnected.\n\n");
}