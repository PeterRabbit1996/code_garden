#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("fork test start...\n");

	int pid = fork();
	if (pid < 0) {
		printf("fork error!\n");
		return -1;
	}
	else if (pid == 0)
		printf("i am child...\n");
	else
		printf("i am father...\n");

	printf("fork test exit...\n");

	return 0;
}
