#include <iostream>
#include "math.h"

int main()
{
	int n1 = 10;
	int n2 = 20;
	swap<int>(n1, n2);
	printf("n1 = %d, n2 = %d\n", n1, n2);

	return 0;
}