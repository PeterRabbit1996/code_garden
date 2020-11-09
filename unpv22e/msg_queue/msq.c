#include <stdio.h>
#include <mqueue.h>

#define FILE_MODE       (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#define MQ_NAME		"\\mqtest"
#define FLAGS		O_RDWR | O_CREAT

#define MAX_MSG		1024
#define MAX_SIZE	1024


int main()
{
	mqd_t mqd;
	struct mq_attr mqattr;

	mqattr.mq_maxmsg = MAX_MSG;
	mqattr.mq_maxsize = MAX_SIZE;

	mqd = mq_open(MQ_NAME, FLAGS, FILE_MODE, &mqattr);

	mu_unlink(mqd);

	return 0;
}
