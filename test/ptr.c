#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func_1()
{
	double val = 10;
	double *pval = &val;
	double *ppval = pval;

	printf("val = %f\n", val);
	printf("&val = %p\n", &val);

	printf("pval = %p\n", pval);
	printf("*pval = %f\n", *pval);
	printf("&pval = %p\n", &pval);

	printf("ppval = %p\n", ppval);
	printf("*ppval = %f\n", *ppval);
	//printf("**ppval = %f\n", **ppval);
	printf("&ppval = %p\n", &ppval);
}

void func_2()
{
	int ival = 22;
	double dval = 55;
	void *vptr;

	vptr = &ival;
	printf("*vptr = %d\n", *(int *)vptr);

	vptr = &dval;
	printf("*vptr = %f\n", *(double *)vptr);
}

void func_3()
{
	char *src = "abcdefg";
	char *dst = (char *)malloc(sizeof(char) * (strlen(src) + 1));

	memcpy(dst, src, sizeof(char) * (strlen(src) + 1));
	*(dst + 4) = 'F';

	printf("%s\n", dst);
}

void func_4()
{
	int num_1 = 55;
	int num_2 = 88;

	const int* ptr_1 = &num_1;
	//*ptr_1 = 66; // not allowed, read-only variable is not assignable
	ptr_1 = &num_2;

	int* const ptr_2 = &num_1;
	*ptr_2 = 66;
	//ptr_2 = &num_2; // not allowed, cannot assign to variable 'ptr_2' with const-qualified type 'int *const'

}

int main()
{
	func_4();

	return 0;
}
