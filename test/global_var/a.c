#include <stdio.h>
#include "global.h"

extern int g_num;

void func_a()
{
	printf("[%s] [%s] g_num = %d\n", __FILE__, __FUNCTION__, g_num);
	g_num = 55;
	printf("[%s] [%s] g_num = %d\n", __FILE__, __FUNCTION__, g_num);

	printf("[%s] [%s] sg_num = %d\n", __FILE__, __FUNCTION__, sg_num);
	sg_num = 55;
	printf("[%s] [%s] sg_num = %d\n", __FILE__, __FUNCTION__, sg_num);
}
