#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sig_alrm(int signo)
{
	printf("sig_alarm receive.\n");
}

int main()
{
	if (signal(SIGALRM, sig_alrm) == SIG_ERR)
		abort();
	alarm(4);
	pause();

	return 0;
}
