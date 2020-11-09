#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	//close(0);
	//close(1);
	//close(2);
	printf("sizeof(size_t) = [%lu]\n", sizeof(size_t));
	printf("atoi(a) = %d\n", atoi("a"));

	return 0;
}
