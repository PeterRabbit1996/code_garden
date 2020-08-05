#include <stdio.h>

//int func();
int func()
{
	printf("%s\n", __FUNCTION__);
	return 0;
}

int main()
{
	int (*fp)() = func;
	(*fp)();
	fp();

	return 0;
}
