// ***     I AM SERVER   ***

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>

struct st{
        int i;
        float f;
        char c;
};


int main(){
	int sock, cli1, i, cli2;
	unsigned int len = 0, len1 = 0;
	struct sockaddr_in my, my2, client1, client2;
	char  letter;	
	struct st b;

	bzero((char *)&my, sizeof(my));
	my.sin_family  = AF_INET;
	my.sin_port = htons(5502);
	my.sin_addr.s_addr = INADDR_ANY;

        bzero((char *)&client1, sizeof(cli1));
        bzero((char *)&my2, sizeof(my2));

	client2.sin_family = AF_INET;
	client2.sin_port = htons(5502);
	inet_pton(AF_INET, "172.20.22.121", &client2.sin_addr);
	
	sock = socket(PF_INET, SOCK_STREAM, 0);
	if(sock <0){
		perror("socket:");
		exit(1);
	}


	if(bind(sock, (struct sockaddr *)&my, sizeof(my)) < 0 ){
		perror("bind:");
		exit(1);
	}


	listen(sock, 5);


	cli1 = accept(sock, (struct sockaddr *)&client1, &len);
	if(cli1 < 0){
		perror("accept:");
		exit(1);
	}
	

	len = recv(cli1, &b, sizeof(b), 0);
	printf("%c %d %fis recieved\n", b.c, b.i, b.f);
	b.c = b.c + 1;	
	b.i += 1;
	b.f += 1.0;

//	my.sin_port = htons(5502);
	my2.sin_family = AF_INET;
	my2.sin_addr.s_addr = INADDR_ANY;	
	my2.sin_port = htons(5500);

	sock = socket(PF_INET, SOCK_STREAM, 0);
        if(sock <0){
                perror("socket:");
                exit(1);
        }


        if(bind(sock, (struct sockaddr *)&my2, sizeof(my2)) < 0 ){

        }


	if(connect(sock, (struct sockaddr *)&my2, sizeof(my2)) < 0){
		perror("connect:");
		close(sock);
		exit(1);
	}
	printf("connected\n");
//	printf("type the character\n");
//	scanf("%s",buff);
	if(send(sock,  &b, sizeof(b), 0) < 0){
		perror("send:");
		exit(1);
	}
	printf("strc is being sent\n");		

	close(sock);
	close(cli1);
//	close(cli2);
	return 0;
}
