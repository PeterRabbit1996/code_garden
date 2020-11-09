#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/errno.h>
#include <netinet/in.h>

#define LOCAL_PORT	  9999
#define BACKLOG		  64
#define BUFF_LEN	  1024

int main()
{
	int st_fd_listen = 0;
	int st_fd_accept = 0;
	struct sockaddr_in so_local_addr = {0};
	struct sockaddr_in so_remote_addr = {0};
	socklen_t sock_len = 0;
	char buff[BUFF_LEN] = {0};

	so_local_addr.sin_family = AF_INET;
	so_local_addr.sin_port = htons(LOCAL_PORT);
	so_local_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if ((st_fd_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("errno = [%d], message = [%s]\n", errno, strerror(errno));
		return -1;
	}

	if (bind(st_fd_listen, (struct sockaddr *)&so_local_addr, sizeof(so_local_addr)) < 0)
	{
		printf("errno = [%d], message = [%s]\n", errno, strerror(errno));
		return -1;
	}

	if (listen(st_fd_listen, BACKLOG) < 0)
	{
		printf("errno = [%d], message = [%s]\n", errno, strerror(errno));
		return -1;
	}

	

	while (1) {
		if ((st_fd_accept = accept(st_fd_listen, (struct sockaddr *)&so_remote_addr, &sock_len)) < 0)
		{
			printf("errno = [%d], message = [%s]\n", errno, strerror(errno));
			return -1;
		}

		pid_t pid;
		if ((pid = fork()) == 0)
		{
			close(st_fd_listen);

			while (recv(st_fd_accept, buff, sizeof(buff), 0) > 0)
			{
				printf("server: \n\t%s\n", buff);
			}

			printf("errno = [%d], message = [%s]\n", errno, strerror(errno));
			return -1;
		}

		close(st_fd_accept);
	}

	return 0;
}
