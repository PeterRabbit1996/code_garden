#include <stdio.h>
#include <stdlib.h>

struct ST
{
	int num;
	char ch[];
};

void test1()
{
	struct ST st;
	st.ch[0] = 'a';
	printf("sizeof(st) = %lu\n", sizeof(st));
	printf("st.ch[0] = %c\n", st.ch[0]);

	return;
}

void test2()
{
	struct ST *st = (struct st*)malloc(sizeof(struct ST) + 100);
	st->ch[0] = 'a';
	printf("sizeof(st) = %lu\n", sizeof(*st));
	printf("st.ch[0] = %c\n", st->ch[0]);

	return;
}

int main()
{
	test1();
	test2();

	return 0;
}
