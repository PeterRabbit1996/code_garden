#include <stdio.h>
#include <string.h>
#include <errno.h>


int main()
{
	for (int i = 0; i < 128; i++) {
		printf("%d	 %s\n", i, strerror(i));
		errno = i;
		perror("a");
	}

	return 0;
}
