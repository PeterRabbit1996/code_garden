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
	int sockfd;
	struct sockaddr_in servaddr;
	struct sockaddr_in cliaddr;

	bzero(&servaddr, sizeof(struct sockaddr_in));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT_SERV);

	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		printf("socket error.\n");
		return -1;
	}

	if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(struct sockaddr_in)) < 0)
	{
		printf("bind error.\n");
		return -1;
	}

	while (1)
	{
		char buff_recv[BUFF_SIZE + 1];
		socklen_t so_len;

		int n = recvfrom(sockfd, buff_recv, BUFF_SIZE, 0, (struct sockaddr *)&cliaddr, &so_len);
		buff_recv[n] = '\0';
		printf("server:\n\t%s", buff_recv);
	}

	return 0;
}
