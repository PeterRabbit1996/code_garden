#include <stdio.h>

/*
* to test stack fo function calling.
*/
void func()
{
	func();
}

int main()
{
	func();

	return 0;
}
