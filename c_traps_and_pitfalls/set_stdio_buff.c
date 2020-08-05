#include <stdio.h>
#include <stdlib.h>

#define BUFFSIZE	4

int main()
{
	int c;
	char *buff = (char *)malloc(sizeof(char) * BUFFSIZE);

	setbuf(stdout, buff);
	while((c = getchar()) != EOF) {
		putchar(c);
	}
}
