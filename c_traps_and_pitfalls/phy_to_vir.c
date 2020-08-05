#include <stdio.h>

int main()
{
	/*
	* not allow to assigned a num directly to physical address,
	* and it will arrise "Segmentation fault: 11".
	*/
	*(int *)(0x480000) = 0x55;

	return 0;
}
