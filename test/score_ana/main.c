#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE_BUFF	1024

int main()
{
	FILE *fp_r = NULL;
	FILE *fp_w = NULL;
	char buff[1024];

	if( (fp_r = fopen("data", "r")) == NULL)
		return -1;
	if( (fp_w = fopen("copy", "w")) == NULL)
		return -1;

	memset(buff, '\0', SIZE_BUFF);
	while (fgets(buff, SIZE_BUFF, fp_r) != NULL) {
		buff[strlen(buff) - 1] = ' ';

		int num = atoi(buff);
		if (num >= 10000)
			fputs("\n", fp_w);
		fwrite(buff, 1, strlen(buff), fp_w);

		memset(buff, '\0', SIZE_BUFF);
	}

	return 0;
}
