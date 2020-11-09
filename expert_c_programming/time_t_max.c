#include <stdio.h>
#include <time.h>

int main()
{
	time_t max_time = 0x7FFFFFFF;

	printf("sizeof(time_t) = %lu byte\n", sizeof(time_t));
	printf("max_time = %s\n", asctime(gmtime(&max_time)));

	return 0;
}
