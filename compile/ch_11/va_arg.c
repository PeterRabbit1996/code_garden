#include <stdio.h>
#include <stdarg.h>

#if 0

int sum(int num, ...)
{
	int sum = 0;

	int *p = &num;
	for (int i = 1; i <= num; i++) {
		printf("%d, ", *(p - i));
	}

	return sum;
}

#endif

int sum(const int num, ...)
{
	int sum = 0;

	va_list arg_ptr;
	va_start(arg_ptr, num);

	return sum;
}

int main()
{
	printf("sum = %d\n", sum(4, 3, 6, 9, 12));
	return 0;
}
