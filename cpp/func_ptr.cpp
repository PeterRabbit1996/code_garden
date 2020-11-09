#include <stdio.h>
#include <iostream>

using namespace std;

static void (*pf)(int *, int *);

class ClassTest
{
public:
	static void iswap(int *num_1, int *num_2)
	{
		*num_1 ^= *num_2;
		*num_2 ^= *num_1;
		*num_1 ^= *num_2;
	}

};

void func_1()
{
	int num_1 = 55;
	int num_2 = 99;
	pf = ClassTest::iswap;
	/*
	 * C++中的cout对象没有对函数指针作为输入参数的<<运算符重载，
	 * 函数把输入参数haha当做bool量处理。
	 * 解决办法：把函数指针进行强制类型转换为(void*)型。
	*/
	//cout << "pf = " << pf << endl;
	cout << "pf = " << (void *)pf << endl;

	printf("num_1 = %d, num_2 = %d\n", num_1, num_2);
	pf(&num_1, &num_2);
	printf("num_1 = %d, num_2 = %d\n", num_1, num_2);
}

/* func_2 is a function with parameter "int"
 * returning a pointer pointering to a function with parameter "int *, int *".
*/
void (*(func_2(int flag)))(int *, int *)
{

	return ClassTest::iswap;
}

//int (*func(int i))[10];

int main()
{
	func_1();

	return 0;
}
