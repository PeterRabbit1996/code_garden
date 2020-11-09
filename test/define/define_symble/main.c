#include <stdio.h>


void func_1()
{
#define FLAG	>

	int num_1 = 55;
	int num_2 = 99;

	int the_bigger = num_1 FLAG num_2 ? num_1 : num_2;
	printf("the bigger num is [%d]\n", the_bigger);
}

void func_2()
{
#define ADD_DIRECTION	+= 1

	int num = 50;

	num ADD_DIRECTION;
	printf("after add with ADD_DIRECTION: [%d]\n", num);
}

int main()
{
	func_2();

	return 0;
}
