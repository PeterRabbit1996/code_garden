#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_SERV	9998
#define BUFF_SIZE	1024

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("usage: ./exec_file <ip_addr>");
		exit(-1);
	}

	int sfd;
	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(struct sockaddr_in));

	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	//servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT_SERV);

	sfd = socket(AF_INET, SOCK_DGRAM, 0);

	while (1)
	{
		char buff_send[BUFF_SIZE];
		printf("client:\n\t");
		fgets(buff_send, BUFF_SIZE, stdin);
		sendto(sfd, buff_send, strlen(buff_send), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
	}

	return 0;
}
