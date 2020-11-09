#include <stdio.h>

void func_1()
{
	const int num_1 = 11;
	printf("num_1 = %d\n", num_1);
	//num_1 = 99; // const variable not alowned to assigned again.

	int num_2 = 22;
	const int* ptr_2 = &num_2;
	printf("*ptr_2 = %d\n", *ptr_2);
	num_2 = 99;
	printf("*ptr_2 = %d\n", *ptr_2);

	int num_3 = 33;
	int* const ptr_3 = &num_3;
	printf("num_3 = %d\n", num_3);
	printf("*ptr_3 = %d\n", *ptr_3);
	num_3 = 333;
	//ptr_3 = &num_2;
}

void func_2()
{
	const int cinum = 55;
	int const *pcinum = &cinum;
	printf("*pcinum = %d\n", *pcinum);
}

void func_3()
{
	const int cinum = 66;
	int inum = cinum;

	printf("cinum = %d\n", cinum);
	printf("inum = %d\n", inum);
}

// use of const and pointer.
/*
void func_4()
{
	int inum = 10;

	const int *ci_1 = &inum;
	const int *const ci_2 = &inum;
	int const *const ci_3 = &inum;
}
*/

int main()
{
	func_1();
	func_2();
	func_3();
	
	return 0;
}
