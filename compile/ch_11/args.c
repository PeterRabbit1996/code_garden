#include <stdio.h>

void func(int val_1, int val_2, int val_3)
{
	printf("%p\n", &val_1);
	printf("%p\n", &val_2);
	printf("%p\n", &val_3);

	int *p = &val_1;
	printf("%d\n", *(p));
	printf("%d\n", *(p - 1));
	printf("%d\n", *(p - 2));
}

int main()
{
	func(3, 6, 9);

	return 0;
}
