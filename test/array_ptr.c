#include <stdio.h>

int main()
{
	int size = 10;
	int num[size];
	//int* num_ptr[size];
	int (*ptr_num)[size];

	for (int i = 0; i < size; i++)
		num[i] = i;
	ptr_num = &num;
	for (int i = 0; i < size; i++)
		printf("%d, ", *(*ptr_num + i));

	return 0;
}
