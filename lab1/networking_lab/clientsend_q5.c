#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(){
	int clientSocket1;
	char c;
	printf("enter the character");
	scanf("%c",&c);
	struct sockaddr_in serverAddr;
	socklen_t addr_size;
	clientSocket1 = socket(PF_INET, SOCK_STREAM, 0);
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(7891);
	serverAddr.sin_addr.s_addr = inet_addr("172.19.13.88 ");
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  
	addr_size = sizeof serverAddr;
	connect(clientSocket1, (struct sockaddr *) &serverAddr, addr_size);
	send(clientSocket1,&c,sizeof(c),0);
	printf("i have sent the character\n");
	close(clientSocket1);
	return 0;
}
