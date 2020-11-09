#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void partitial_match_table(char *p, int *pmt, int size)
{
	int i = 0;
	int j = -1;
	*(pmt + 0) = -1;
	while (i < size) {
		if (j == -1 || *(p + i) == *(p + j)) {
			i += 1;
			j += 1;
			*(pmt + i) = j;
		}
		else
			j = *(pmt + j);
	}
}

int kmp(char *s, int s_size, char *p, int p_size)
{
	int *pmt = (int *)malloc(sizeof(int) * p_size);
	partitial_match_table(p, pmt, p_size);

	int i = 0;
	int j = 0;
	while (i < s_size && j < p_size) {
		if (j == -1 || *(s + i) == *(p + j)) {
			i += 1;
			j += 1;
		}
		else
			j = *(pmt + j);
	}

	if (j == p_size)
		return (i - j);

	return -1;
}

int main()
{
	char s[] = "bbc abcdab abcdabcdabde";
	char p[] = "abcdabd";
	printf("%d\n", kmp(s, strlen(s), p, strlen(p)));

	return 0;
}
