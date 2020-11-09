#include <stdio.h>
#include <pthread.h>

void *thread_func(void *args)
{
	for (int i = 0; i < 10; i++) {
		printf("[%s] i = %d\n", __FUNCTION__, i);
	}

	return NULL;
}

int main()
{
	pthread_t p_id;
	if (pthread_create(&p_id, NULL, thread_func, NULL)) {
		printf("error!\n");
		return -1;
	}

	for (int i = 0; i < 10; i++) {
		printf("[%s] i = %d\n", __FUNCTION__, i);
	}

	sleep(4);

	return 0;
}
