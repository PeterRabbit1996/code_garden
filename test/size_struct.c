#include <stdio.h>

struct struct_1 {
	double d;
	char c;
	int i;
	short s1;
	short s2;
};

void sizeof_variable()
{
	printf("sizeof(char) = %lu\n", sizeof(char));
	printf("sizeof(short) = %lu\n", sizeof(short));
	printf("sizeof(int) = %lu\n", sizeof(int));
	printf("sizeof(long int) = %lu\n", sizeof(long int));
	printf("sizeof(float) = %lu\n", sizeof(float));
	printf("sizeof(double) = %lu\n", sizeof(double));
}

int main()
{
	sizeof_variable();

	struct struct_1 struct_11;
	printf("sizeof(struct struct_1) = %lu\n", sizeof(struct struct_1));
	printf("&d = %p, &c = %p, &i = %p, &s1 = %p, &s2 = %p\n",
		&struct_11.d, &struct_11.c, &struct_11.i, &struct_11.s1, &struct_11.s2);

	return 0;
}
