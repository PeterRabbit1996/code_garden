#include <stdio.h>
#include <string.h>
#include <errno.h>


int main()
{
	for (int i = 0; i < 128; i++) {
		printf("%d\t%s\n", i, strerror(i));
		errno = i;
		perror("\t");
	}

	return 0;
}
