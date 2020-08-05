#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sig_fpe(int signo)
{
	printf("%s\n", __FUNCTION__);
}

void sig_alrm(int signo)
{
	printf("%s\n", __FUNCTION__);
	alarm(1);
}

int main()
{
	signal(SIGFPE, sig_fpe);
	signal(SIGALRM, sig_alrm);
	int num = 0;
	//num = 1 / 0;

	alarm(4);
	printf("num = %d\n", num);
	alarm(4);
	sleep(8); // return remained sec when catch a signal.

	return 0;
}
