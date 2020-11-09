#include <stdio.h>
#include "a.h"
#include "b.h"

#ifndef TEST_DEFINE
#define TEST_DEFINE	3
#endif

#ifndef TEST_FUNC
#define TEST_FUNC(a, b) ((a) == (b) ? 1 : 0)
#endif

int main()
{
	int num = TEST_DEFINE;
	printf("num = %d\n", num);

	int a = 9;
	int b = 5;
	printf("TEST_FUNC(%d, %d) = %d\n", a, b, TEST_FUNC(a, b));

	return 0;
}
