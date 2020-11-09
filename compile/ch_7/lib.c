/* lib.c */

#include <stdio.h>
#include <unistd.h>

void foobar(int i)
{
	printf("print from lib.so %d\n", i);
	sleep(-1);
}
