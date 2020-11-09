#include <stdio.h>

#define MAX(a, b) \
		((a) > (b) ? (a) : (b);)

#define P(a) \
		{printf("%d\n", a);}

int main()
{
	P(12);

	return 0;
}
