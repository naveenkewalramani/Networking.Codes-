#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(){
	int clientSocket;
	char buffer[1024],str[1024];
	struct sockaddr_in serverAddr;
	socklen_t addr_size;
	clientSocket = socket(PF_INET, SOCK_STREAM, 0);
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(7891);
	serverAddr.sin_addr.s_addr = inet_addr("172.20.22.16  ");
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  
	addr_size = sizeof serverAddr;
	connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);
	//recv(clientSocket,buffer,1024,0);
	//printf("%s",buffer);
	while(1){
			int i;
			for(i=0;i<1024;i++)
					buffer[i]='\0';
			recv(clientSocket,buffer,1024,0);
			if(strcmp(buffer,"exit")==0)
				break;
			else 
				printf("client :%s\n",buffer);
			for(i=0;i<1024;i++)
				str[i]='\0';
			scanf("  %[^\n]s ",str);
			send(clientSocket,str,strlen(str),0);
	}
	close(clientSocket);
	return 0;
}
