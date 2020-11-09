#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

struct list {
	int val;
	struct list *next;
};

void thread_read()
void thread_write()

struct list *head = NULL;
pthread_rwlock_t rwlock;

int main()
{
	pthread_rwlock_init(&rwlock, NULL);

	return 0;
}

void thread_read()
{
	while(1) {
		pthread_rwlock_tryrdlock(&rwlock);
		if (head == NULL) {
			pthread_rwlock_unlock(&rwlock);
			sleep(4);
			continue;
		}

		pthread_rwlock_unlock(&rwlock);
	}

}

void thread_write()
{
	while(1) {
		pthread_rwlock_tryrdlock(&rwlock);

		pthread_rwlock_unlock(&rwlock);
	}

}
