//  ***   I AM CLIENT- 2   ***

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>

int main(){
	int sock, cli, i;
	unsigned int len = 0, len1 = 0;
	struct sockaddr_in my, client;
	char buf[5];	

	bzero((char *)&my, sizeof(my));
	my.sin_family  = AF_INET;
	my.sin_port = htons(5500);
	my.sin_addr.s_addr = INADDR_ANY;

        bzero((char *)&client, sizeof(cli));
//        bzero(buf, sizeof(buf));


	sock = socket(PF_INET, SOCK_STREAM, 0);
	if(sock <0){
		perror("socket:");
		exit(1);
	}
	if(bind(sock, (struct sockaddr *)&my, sizeof(my)) < 0 ){
		perror("bind:");
		exit(1);
	}else{
//		printf("binded\n");
	}
	listen(sock, 5);
	cli = accept(sock, (struct sockaddr *)&client, &len);
	if(cli < 0){
		perror("accept:");
		exit(1);
	}
//	printf("connected\n");
	len = recv(cli, buf, sizeof(buf), 0);
//	printf("recieved\n");	
	printf("%c recieved\n",buf[0]);
	close(sock);
	close(cli);
	return 0;
}
