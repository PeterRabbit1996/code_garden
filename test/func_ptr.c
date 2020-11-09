#include <stdio.h>

static void (*pf)(int *, int *);

void iswap(int *num_1, int *num_2)
{
	*num_1 ^= *num_2;
	*num_2 ^= *num_1;
	*num_1 ^= *num_2;
}

void func_1()
{
	int num_1 = 55;
	int num_2 = 99;
	pf = iswap;

	printf("num_1 = %d, num_2 = %d\n", num_1, num_2);
	pf(&num_1, &num_2);
	printf("num_1 = %d, num_2 = %d\n", num_1, num_2);
}

/* func_2 is a function with parameter "int"
 * returning a pointer pointering to a function with parameter "int *, int *".
*/
void (*(func_2(int flag)))(int *, int *)
{

	return iswap;
}

//int (*func(int i))[10];

int main()
{
	func_1();

	return 0;
}
