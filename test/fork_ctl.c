#include <stdio.h>
#include <unistd.h>

int main()
{
	/* main :num will output twice while redirecting to file if setbuf forbidden. */
	//setbuf(stdout, NULL);

	pid_t pid = 0;
	int num = 0;

	num = 55;
	printf("main: num = %d\n", num);

	if ((pid = fork()) < 0)
		return -1;
	else if (pid == 0) {
		printf("son: num = %d\n", num);
		num = 33;
		printf("son: num = %d\n", num);
	}
	else {
		printf("father: num = %d\n", num);
		num = 66;
		printf("father: num = %d\n", num);
	}

	return 0;
}
