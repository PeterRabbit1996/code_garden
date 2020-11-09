#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *func()
{
	int i = 99;
	i++;
	printf("i = %d\n", i);
	return NULL;
}

int main()
{
	pthread_t pid;
	pthread_create(&pid, NULL, func, NULL);
	sleep(2);
	pthread_create(&pid, NULL, func, NULL);
	sleep(2);

	return 0;
}
