#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#define size 512 
int main() {
	int sock;
	sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock == -1) {
		printf("Socket creation problem\n");
		exit(0);
	}
	struct sockaddr_in myaddr,clientaddr;
	bzero(&myaddr,sizeof(myaddr));
	myaddr.sin_family = AF_INET;
	myaddr.sin_port = htons(5500);
	myaddr.sin_addr.s_addr = INADDR_ANY;
	int temp;
	temp = bind(sock,(struct sockaddr*)&myaddr,sizeof(myaddr));
	if(temp == -1) {
		printf("binding error\n");
		exit(0);
	}
	temp = listen(sock,5);
	if(temp == -1) {
		printf("listening error\n");
		exit(0);
	}
	bzero(&clientaddr,sizeof(clientaddr));

	int new_fd;
	int addrlen = sizeof(clientaddr);
	new_fd = accept(sock,(struct sockaddr *)&clientaddr,&addrlen);
	if(new_fd < 0) {
		printf("socket creation error\n");
		exit(0);
	}

	while(1) {
		char msg[size];
		temp = recv(new_fd, msg, size, 0);
		if(strcmp(msg,"0")==0){
			printf("Bob\n");
		}else if(strcmp(msg,"3")==0){
			printf("Anne\n");
		}else if(strcmp(msg,"5")==0){
			printf("Barb\n");
		}else if(strcmp(msg,"7")==0){
			printf("Ray\n");
		}else if(strcmp(msg,"9")==0){
			printf("Denbigh\n");
		}else if(strcmp(msg,"10")==0){
			printf("Terri\n");
		}else if(strcmp(msg,"104")==0){
			printf("John\n");
		}else if(strcmp(msg, "bye") == 0){
			break;
		}else{
			printf("address is not found\n");
		}
	}
	close(new_fd);
	close(sock);
	
	return 0;
}
