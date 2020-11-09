#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <fcntl.h>

#define NUMS		10
#define FILE_MODE       (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

void *produce();
void *comsume();

sem_t *buff;

int main()
{
	pthread_t tid_produce;
	pthread_t tid_comsume;

	sem_unlink("/buff");
	buff = sem_open("/buff", O_CREAT | O_EXCL, FILE_MODE, NUMS);

	pthread_create(&tid_produce, NULL, produce, NULL);
	pthread_create(&tid_comsume, NULL, comsume, NULL);

	sem_unlink("/buff");

	pause();

	return 0;
}

void *produce()
{
	int val;

	while(1) {
		sem_wait(buff);
		sem_getvalue(buff, &val);
		printf("[%s], buff = %d\n", __FUNCTION__, val);
	}

}

void *comsume()
{
	int val;

	while(1) {
		sleep(1);

		sem_post(buff);
		sem_getvalue(buff, &val);
		printf("[%s], buff = %d\n", __FUNCTION__, val);
	}

}
