#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#define size 256
int main()
{
	int sock, length, n, status, temp;
	struct sockaddr_in addr, serverAddr;
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0){
		printf("Socket error\n");
		exit(0);
	}
	
	memset(&addr, sizeof(struct sockaddr_in), 0);
	
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(5500);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.1.1");

	temp = connect(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

	if(temp != 1)
                printf("Connected\n");
        else
                printf("Connection error\n");

	char msg[256];
	while(1) {
		scanf("%s", msg);
		temp = send(sock, msg, sizeof(msg), 0);
		if(strcmp(msg,"bye") == 0)
			break;
		msg[0] = '\0';
	}

	close(sock);

	if(temp != 1)
		printf("\n");
	else
		exit(0);

	return 0;
}
