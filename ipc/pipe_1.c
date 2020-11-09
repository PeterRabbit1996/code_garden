#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE	1024

int main()
{
	int n;
	int fd[2];
	pid_t pid;
	char line[MAX_LINE];

	if (pipe(fd) < 0) printf("pip error.\n");

	if ((pid = fork()) < 0) printf("fork error.\n");
	else if (pid > 0) {
		close(fd[0]);
		read(STDIN_FILENO, line, sizeof(line));
		write(fd[1], line, strlen(line));
	} else {
		close(fd[1]);
		n = read(fd[0], line, MAX_LINE);
		write(STDOUT_FILENO, line, n);
	}

	return 0;
}
