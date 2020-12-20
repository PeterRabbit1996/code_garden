#include <stdio.h>

#define DEFINE_TYPE_INT	10
#define DEFINE_TYPE_FLOAT	11

typedef enum {
	ENUM_TYPE_INT = 0,
	ENUM_TYPE_FLOAT = 1,
} DATA_TYPE;

int main()
{
	DATA_TYPE data_type;

	data_type = DEFINE_TYPE_INT;
	printf("data_type = %d\n", data_type);

	data_type = ENUM_TYPE_INT;
	printf("data_type = %d\n", data_type);

	return 0;
}
