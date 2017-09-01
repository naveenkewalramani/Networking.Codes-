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
	printf("enter values\n");
	scanf(" %d",&value.a);
	scanf(" %c",&value.b);
	scanf(" %f",&value.c);	
	int clientSocket1;
	struct sockaddr_in serverAddr;
	socklen_t addr_size;
	clientSocket1 = socket(PF_INET, SOCK_STREAM, 0);
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(7891);
	serverAddr.sin_addr.s_addr = inet_addr("172.19.13.88 ");
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  
	addr_size = sizeof serverAddr;
	connect(clientSocket1, (struct sockaddr *) &serverAddr, addr_size);
	send(clientSocket1,&value,sizeof(value),0);
	printf("i have sent the structure\n");
	close(clientSocket1);
	return 0;
}
