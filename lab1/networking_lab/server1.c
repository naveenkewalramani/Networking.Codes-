#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(){
	int welcomeSocket, newSocket;
	char buffer[1024],str[1024];
	struct sockaddr_in serverAddr;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size;

	welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);


	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(7891);
	serverAddr.sin_addr.s_addr =inet_addr("172.20.22.16  ");
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

	bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

	if(listen(welcomeSocket,5)==0)
		printf("Listening\n");
	else
		printf("Error\n");

	addr_size = sizeof serverStorage;
	newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);
	while(1){
		int i;
		for(i=0;i<1024;i++)
			str[i]='\0';
		scanf( "  %[^\n]s ",str);
		//strcat(str,"\0");
		send(newSocket,str,strlen(str),0);
		for(i=0;i<1024;i++)
			buffer[i]='\0';
		recv(newSocket,buffer,1024,0);
		if(strcmp(buffer,"exit")==0)
			break;

		else
			printf("server :%s\n",buffer);
	}
	close(welcomeSocket);
	return 0;
}
