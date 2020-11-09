/************************************************************************
* 管道读写规则

* 当没有数据可读时
* O_NONBLOCK disable：read调用阻塞，即进程暂停执行，一直等到有数据来到为止。
* O_NONBLOCK enable：read调用返回-1，errno值为EAGAIN。

* 当管道满的时候
* O_NONBLOCK disable： write调用阻塞，直到有进程读走数据
* O_NONBLOCK enable：调用返回-1，errno值为EAGAIN

* 如果所有管道写端对应的文件描述符被关闭，则read返回0
* 如果所有管道读端对应的文件描述符被关闭，则write操作会产生信号SIGPIPE
* 当要写入的数据量不大于PIPE_BUF时，linux将保证写入的原子性。
* 当要写入的数据量大于PIPE_BUF时，linux将不再保证写入的原子性。

close(fd[0]);
close(fd[1]);
************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUFF_SIZE	1024

int main()
{
	int fd[2];
	pid_t pid = 0;
	int n = 0;

	pipe(fd);

	if ((pid = fork()) < 0)
		return -1;
	else if (pid > 0) {
		char buff_send[BUFF_SIZE] = "hello, world\n";
		char buff_recv[BUFF_SIZE];
		memset(buff_recv, 0, BUFF_SIZE);

		/* write buff to fd[1] */
		n = write(fd[1], buff_send, BUFF_SIZE);
		printf("in father: n = %d\n", n);
	}
	else {
		char buff_send[BUFF_SIZE] = "fuck, world\n";
		char buff_recv[BUFF_SIZE];
		memset(buff_recv, 0, BUFF_SIZE);

		/* read buff from fd[0] */
		n = read(fd[0], buff_recv, BUFF_SIZE);
		printf("in son: n = %d\n", n);

		/* write buff to std out */
		write(1, buff_recv, BUFF_SIZE);
	}

	return 0;
}
