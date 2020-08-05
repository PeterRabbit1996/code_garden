#include <stdio.h>

void func_1()
{
	int num = 55;
	int *ptr = NULL;

	ptr = &num;
	printf("ptr = 0x%p\n", ptr);
	printf("ptr + 1 = 0x%p\n", ptr + 1);
	printf("*ptr = %d\n", *ptr);
	printf("*ptr + 1 = %d\n", *ptr + 1);
}

void cal()
{
	int calendar[12][31];
	int num = 0;
	for (int (*monthp)[31] = calendar; monthp < &calendar[12]; monthp++)
		for (int *dayp = *monthp; dayp < &(*monthp)[31]; dayp++)
			*dayp = num++;

	for (int (*monthp)[31] = calendar; monthp < &calendar[12]; monthp++)
		for (int *dayp = *monthp; dayp < &(*monthp)[31]; dayp++)
			printf("%d, ", *dayp);
	printf("\n");
}

int main()
{
	func_1();
	cal();

	return 0;
}
