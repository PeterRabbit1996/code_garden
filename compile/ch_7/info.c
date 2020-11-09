/* to print the infomation of stack-heap while initializing. */
#include <stdio.h>
#include <elf.h>

int main(int argc, char *argv[])
{
	char **p = argv;
	Elf32_auxv_t *aux;

	printf("Argument count: %d\n", argc);

	for (int i = 0; i < *(p - 1); i++) {
		printf("Argument %d : %s\n", i, *(p + i));
	}

	p += 1;
	p++;

	printf("Environment:\n");
	while (*p) {
		printf("%s\n", *p);
		p++;
	}
	p++; // skip 0

	printf("Auxiliary Vectors:\n");
	aux = (Elf32_auxv_t *)p;
	while (aux->a_type != AT_NULL) {
		printf("Type: %02d Value: %x\n", aux->a_type, aux->a_un.a_val);
		aux++;
	}

	return 0;
}
