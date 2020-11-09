#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;

	if ((fd = open("tmp.txt", O_CREAT | O_APPEND | O_RDWR)) < 0) {
		printf("open error!\n");
		exit(1);
	}

	char buf[1024] = {0};
	while (read(STDIN_FILENO, buf, sizeof(buf) - 1)) {
		write(fd, buf, sizeof(buf) - 1);
	}

	close(fd);

	return 0;
}
