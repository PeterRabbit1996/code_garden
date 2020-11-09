#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE	4096
#define DEF_PAGER	"/usr/bin/more"

int main(int argc, char *argv[])
{
	int n;
	int fd[2];
	pid_t pid;
	char *pager = NULL, *argv0 = NULL;
	char line[MAX_LINE];
	FILE *fp;

	if (argc != 2) {printf("usage: a.out <pathname>\n"); abort();}

	if ((fp = fopen(argv[1], "r")) == NULL) {printf("can't open %s.\n", argv[1]); abort();}
	if (pipe(fd) < 0) {printf("pipe error.\n"); abort();}

	if ((pid = fork()) < 0) {printf("fork error.\n"); abort();}
	else if (pid > 0) {
		close(fd[0]);

		while (fgets(line, MAX_LINE, fp) != NULL) {
			n = strlen(line);
			if (write(fd[1], line, n) != n) {printf("write error to pipe.\n"); abort();}
		}
		if (ferror(fp)) {printf("fgets error.\n"); abort();}

		close(fd[1]);

		if (waitpid(pid, NULL, 0) < 0) {printf("waitpid error.\n"); abort();}

		exit(0);
	}
	else {
		close(fd[1]);
		if (fd[0] != STDIN_FILENO) {
			if (dup2(fd[0], STDIN_FILENO) != STDIN_FILENO) {printf("dup2 error to stdin.\n"); abort();}
			close(fd[0]);
		}

		if ((pager = getenv("PAGER")) == 0) pager = DEF_PAGER;
		if ((argv0 = strrchr(pager, '/')) != 0) argv0++;
		else argv0 = pager;

		if (execl(pager, argv0, (char *)0) < 0) {printf("execl error for %s", pager); abort();}
	}

	exit(0);
}
