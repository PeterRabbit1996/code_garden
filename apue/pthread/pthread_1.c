#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void thread_add();
void thread_minus();

int num_g = 0;
pthread_t pt_add;
pthread_t pt_minus;
pthread_mutex_t pmu;

int main()
{
	pthread_mutex_init(&pmu, NULL);
	pthread_create(&pt_add, NULL, thread_add, NULL);
	pthread_create(&pt_minus, NULL, thread_minus, NULL);

	while(1) {
		pause();
	}

	return 0;
}

void thread_add()
{
	while(1) {
		pthread_mutex_lock(&pmu);
		num_g += 1;
		printf("[%s] num_g = %d\n", __FUNCTION__, num_g);

		sleep(1);
		pthread_mutex_unlock(&pmu);
	}

}

void thread_minus()
{
	while(1) {
		pthread_mutex_lock(&pmu);
		num_g -= 1;
		printf("[%s] num_g = %d\n", __FUNCTION__, num_g);

		sleep(1);
		pthread_mutex_unlock(&pmu);
	}

}
