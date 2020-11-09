#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define REMOTE_ADDR	   "127.0.0.1"
#define REMOTE_PORT	   9999
//#define BACKLOG     64
#define BUFF_LEN    1024

int main()
{
	int st_fd = 0;
	struct sockaddr_in so_remote_addr = {0};
	//socklen_t sock_len = 0;
	char buff[BUFF_LEN] = {0};

	so_remote_addr.sin_family = AF_INET;
	so_remote_addr.sin_port = htons(REMOTE_PORT);
	//so_remote_addr.sin_addr.s_addr = inet_addr(REMOTE_ADDR);
	so_remote_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if ((st_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("errno = [%d], message = [%s]\n", errno, strerror(errno));
		return -1;
	}

	if (connect(st_fd, (struct sockaddr *)&so_remote_addr, sizeof(so_remote_addr)) < 0)
	{
		printf("errno = [%d], message = [%s]\n", errno, strerror(errno));
		return -1;
	}

	while (1) {
		if (scanf("%s", buff) == EOF)
			break;

		if (send(st_fd, buff, sizeof(buff), 0) < 0)
		{
			printf("errno = [%d], message = [%s]\n", errno, strerror(errno));
			return -1;
		}

		printf("client: \n\t%s\n", buff);
	}

	return 0;
}
