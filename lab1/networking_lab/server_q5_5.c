#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
struct ser{
		int a;
		char b;
		float c;
}value;

int main(){
	int welcomeSocket, newSocket;
	struct sockaddr_in serverAddr;
	struct sockaddr_storage serverStorage1,serverStorage2;
	socklen_t addr_size;

	welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);


	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(7891);
	serverAddr.sin_addr.s_addr =inet_addr("172.19.13.88 ");
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

	bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

	if(listen(welcomeSocket,5)==0)
		printf("Listening\n");
	else
		printf("Error\n");

	addr_size = sizeof serverStorage1;
	newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage1, &addr_size);

	recv(newSocket,&value,sizeof(value),0);
	printf("i have received the structure \n");
	printf(" %d  %c  %f\n",value.a,value.b,value.c);
	value.a=value.a-1;
	value.b=value.b-1;
	value.c=value.c-1;
	addr_size=sizeof serverStorage2;
	int newSocket2= accept(welcomeSocket,(struct sockaddr *)&serverStorage2,&addr_size);
	send(newSocket2,&value,sizeof(value),0);
	close(welcomeSocket);
	return 0;
}
