#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <arpa/inet.h>

void main()
{
	 char *ip="127.0.0.1";
	 int port=5566;
	 char c[512];
	 int server_sock,client_sock,a;
	 struct sockaddr_in server_addr,client_addr;
	 socklen_t addr_size;
	 char buffer[1024];
	
	 int n,i, buff_len,p,pc;
	 
	 server_sock=socket(AF_INET,SOCK_STREAM,0);
	 if(server_sock<0){
		 perror("[-]Socket error");
		 exit(1);
	 }
	 printf("[+]TCP server socket created.\n");
	 
	 server_addr.sin_family=AF_INET;
	 server_addr.sin_port=port;
	 server_addr.sin_addr.s_addr=inet_addr(ip);
	 
	 n=bind(server_sock,(struct sockaddr*)&server_addr,sizeof(server_addr));
	 if(n<0){
		 perror("[-]Bind error");
		 exit(1);
	 }
	 printf("[+]Bind to the port number:%d\n",port);
	 
	 listen(server_sock,5);
	 printf("Listening \n");
	 
	 recv(client_sock, p, sizeof(p),0);
	char f[p];
	for (i=0;i<p;i++)
		f[i]='f';
	
	 recv(client_sock, pc, sizeof(pc),0);
	printf("sending");
	if(pc==0)
	{
		for(i=0;i<p;i++)
		{
			printf("sending frame no : %d",i);
			send(client_sock,i,strlen(i),0);
			printf("waiting for ack");
			recv(client_sock, a, sizeof(a),0);
			printf("receive ack for frame %d as %d",i,a);
		}
	}
	else
	{
	    for(i=0;i<p;i++)
		{
		    if(i==2)
				printf("sending Frame no : %d",i);
			else
			{
			    printf("sending Frame no : %d",i);
				send(client_sock,i,strlen(i),0);
				printf("waiting for ack");
				
				recv(client_sock, a, sizeof(a),0);
				if(a!=-1)
				{
					printf("recv for frame no %d as %d",i,a);
					f[i]='t';
				}
			}
		}
		for(int a=0;a<p;a++)
		{
			if(f[a]==false)
			{
				printf("Resending frame %d",a);
				send(client_sock,a,strlen(a),0);
				printf("waiting for ack");
				
				recv(client_sock, b, sizeof(b),0);
				printf("recv for farme no %d as %d",a,b);
				f[a]='t';
			}
		}	
	}
	close(server_sock);
}
