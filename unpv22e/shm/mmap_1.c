#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define SIZE		4096
#define FILE_MODE       (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main()
{
	int fd = open("text", O_RDWR | O_CREAT, FILE_MODE);
	if (fd < 0) return -1;

	//write(fd, "text", SIZE);
	lseek(fd, SIZE, SEEK_SET);
	write(fd, " ", 1);

	char *addr = mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	for (int i = 0; i < SIZE; i++) {
		*(addr + i) = 'C';
	}
	msync(addr, SIZE, MS_SYNC);

	return 0;
}
