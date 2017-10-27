#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
int main()
{	
	//declaration of client variables
	int clent_sockid;
	struct sockaddr_in client_addr;
	
	//client socket created
	client_sockid = socket(AF_INET,SOCK_STREAM,0);
	if(client_sockid == -1){
		printf("client socket not created\n");
		exit(1);
	}	
	
	//client structure value assigned
	bzero(&(client_addr),sizeof(client_addr));	
	client_addr.sin_family = AF_INET;
	client_addr.sin_port = htons(5510);
	client_addr.sin_addr.s_addr = INADDR_ANY;
	
	//client bind to the socket 
	int temp1 = bind(client_sockid,(struct sockaddr *)&client_addr,sizeof(struct sockaddr));
	if(temp1==-1){
		printf("client error in binding\n");
		exit(2);
	}
	//declaration of server variable
	int server_sockid;
	struct sockaddr_in server_addr;
	
	//sever socket created
	server_sockid = socket(AF_INET,SOCK_STREAM,0);
	if(server_sockid == -1){
		printf("server socket not created");
		exit(3);
	}
	//server structure created
	bzero(&(server_addr),sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port(5511);
	server_addr.sin_addr.s.addr = INADDR_ANY;
        
