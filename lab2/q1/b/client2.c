//  ***   I AM CLIENT- 2   ***

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>

struct st{
        int i;
        float f;
        char c;
};

int main(){
	int sock, cli, i;
	unsigned int len = 0, len1 = 0;
	struct sockaddr_in my, client;
	struct st b;

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
	len = recv(cli, &b, sizeof(b), 0);
//	printf("recieved\n");	
	printf("%c %d %f recieved\n",b.c, b.i, b.f);
	close(sock);
	close(cli);
	return 0;
}
