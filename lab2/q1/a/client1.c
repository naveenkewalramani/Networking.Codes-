//  ***  I am client 1  ***
#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/wait.h>

int main(){
	int sock, len = 0, p, cli, status;
	struct sockaddr_in my, ser, client;
//	struct hostent *h;
	char *host, buff[5], s[] = "172.19.13.239";
	
	bzero(buff,  sizeof(buff));
	bzero(&my, sizeof(my));
	bzero(&ser, sizeof(ser));
        bzero(&client, sizeof(client));

	my.sin_port = htons(5502);
	my.sin_family = AF_INET;
	my.sin_addr.s_addr = INADDR_ANY;	

	ser.sin_family = AF_INET;
	ser.sin_port = htons(5500);
	inet_pton(AF_INET, "172.19.13.239", &ser.sin_addr);	
	
//	bcopy(h->h_addr, (char *)&my.sin_addr, h->h_length);

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock <  0){
		perror("socket:");
		exit(1);
	}
	bind(sock, (struct sockaddr *)&my, sizeof(my));
	
	if(connect(sock, (struct sockaddr *)&my, sizeof(my)) < 0){
		perror("connect:");
		close(sock);
		exit(1);
	}

	printf("type the character\n");
	scanf("%s",buff);
	send(sock, (void*) buff, sizeof(buff), 0);
	printf("%c is being sent\n",buff[0]);


	return 0;
}
	
