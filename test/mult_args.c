#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define PRINT_INFO	   "abc"
#define PRINT_DEBUG    5
#define PRINT_ERROR    1
 
double average(int cnt, ...)
{
 
	va_list valist;
	double sum = 0.0;
	int i;
 
	/* 为 cnt 个参数初始化 valist */
	va_start(valist, cnt);
 
	/* 访问所有赋给 valist 的参数 */
	for (i = 0; i < cnt; i++)
	{
	   sum += va_arg(valist, int);
	}
	/* 清理为 valist 保留的内存 */
	va_end(valist);
 
	return sum/cnt;
}

void var_test(char *format, ...)
{
	va_list list;
	va_start(list, format);
	
	char *ch;
	while(1)
	{
		ch = va_arg(list, char *);

		if(strcmp(ch, "") == 0)
		{	 
			printf("\n");
			break;
		}
		printf("%s ", ch);
	}
	va_end(list);
}

void my_print(char *print_level, ...)
{
	va_list valist;
	va_start(valist, print_level);

	char *ch;
	for (int cnt = 0; ; cnt += 1)
	{
		ch = va_arg(valist, char *);
		if(strcmp(ch, "") == 0)
		{	 
			printf("\n");
			break;
		}
		printf("%s ", ch);
	}

	va_end(valist);
}

int main()
{
	printf("Average of 2, 3, 4, 5 = %f\n", average(4, 2,3,4,5));
	printf("Average of 5, 10, 15 = %f\n", average(3, 5,10,15));

	var_test("test","this","is","a","test","");

	my_print("string", "hello", "world", "");

	return 0;
}
