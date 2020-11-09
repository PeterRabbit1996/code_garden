#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <fcntl.h>

#define BUFF		10
#define FILE_MODE       (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

void *produce();
void *comsume();

sem_t *buff;
sem_t *mutex;

int main(int argc, char **argv)
{
	if (argc != 3) {
		printf("usage: ./exec_file [produce pthread num] [consume pthread num]");
		exit(-1);
	}

	int pid_produce_num = atoi(argv[1]);
	int pid_consume_num = atoi(argv[2]);

	pthread_t tid_produce[pid_produce_num];
	pthread_t tid_comsume[pid_consume_num];

	sem_unlink("/buff");
	sem_unlink("/mutex");
	buff = sem_open("/buff", O_CREAT | O_EXCL, FILE_MODE, BUFF);
	mutex = sem_open("/mutex", O_CREAT | O_EXCL, FILE_MODE, 1);

	for (int i = 0; i < pid_produce_num; i++)
		pthread_create(&tid_produce[i], NULL, produce, NULL);
	for (int i = 0; i < pid_consume_num; i++)
		pthread_create(&tid_comsume[i], NULL, comsume, NULL);

	sem_unlink("/buff");
	sem_unlink("/mutex");

	pause();

	return 0;
}

void *produce()
{
	int val;

	while(1) {
		sem_wait(buff);
		sem_wait(mutex);
		sem_getvalue(buff, &val);
		printf("[%s] pid = %ld buff = %d\n", __FUNCTION__, pthread_self(), val);
		sem_post(mutex);
	}

}

void *comsume()
{
	int val;

	while(1) {

		sem_post(buff);
		sem_wait(mutex);
		sem_getvalue(buff, &val);
		if (val >= BUFF) {
			sem_wait(buff);
			sleep(1);
		}
		else
			printf("[%s] pid = %ld buff = %d\n", __FUNCTION__, pthread_self(), val);

		sem_post(mutex);
	}

}
