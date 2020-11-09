#include <stdio.h>

int quick_sork(int num[], int left, int right)
{

	return 0;
}

int main()
{
	int num[] = {4, 6, 2, 7, 1, 9, 8};
	int size = sizeof(num) / sizeof(int);

	quick_sork(num, 0, size - 1);
	for (int i = 0; i < size; i++)
		printf("%d, ", num[i]);
	printf("\n");

	return 0;
}
