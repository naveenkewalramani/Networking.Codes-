#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
struct ser{
	int a;
	char b;
	float c;
}value;

int main(){
	int clientSocket;
	char c;
	struct sockaddr_in serverAddr;
	socklen_t addr_size;
	clientSocket = socket(PF_INET, SOCK_STREAM, 0);
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(7891);
	serverAddr.sin_addr.s_addr = inet_addr("172.19.13.88 ");
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  
	addr_size = sizeof serverAddr;
	connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);
	recv(clientSocket,&value,sizeof(value),0);
	printf("received structure\n");
	printf("received values  : %d  %c  %f\n",value.a,value.b,value.c);
	close(clientSocket);
	return 0;
}

