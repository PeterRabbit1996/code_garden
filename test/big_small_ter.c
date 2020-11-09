#include <stdio.h>

void check_1()
{
	int num = 0x12345678;
	char c = *(char *)&num;

	printf("0x%x\n", num);
	printf("0x%x\n", c);
}

void check_2()
{
	union {
		int num;
		char c;
	} u;
	u.num = 0x12345678;

	printf("0x%x\n", u.num);
	printf("0x%x\n", u.c);
}

int main()
{
	check_1();
	check_2();

	return 0;
}
