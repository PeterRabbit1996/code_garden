#include <stdio.h>
#include <stdbool.h>

void bool_test(bool flag)
{
	if (flag == true)
		printf("true!\n");
	else
		printf("false!\n");
}

int main()
{
	bool_test(true);
	bool_test(false);

	return 0;
}
