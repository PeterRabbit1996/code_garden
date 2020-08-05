#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *str = (char *)malloc(sizeof(char) * 4);
	scanf("%s", str);
	printf("%s", str);
	printf("\n");
	free(str);

	return 0;
}
