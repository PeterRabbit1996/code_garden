# if 0

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *str;
    int cur_size;
    int max_size;
} string_diy;

int string_enlarge_size(string_diy *str)
{
    char *tmp = malloc((128 + str->max_size) * sizeof(char));
    if (tmp == NULL)
        return -1;

    for (int i = 0; i < str->cur_size; i++)
        *(tmp + i) = *(str->str + i);
    free(str->str);
    str->str = tmp;

    return 0;
}

int string_append(string_diy *des, string_diy *src)
{
    while (des->max_size - des->cur_size < src->cur_size) {
        if (string_enlarge_size(des) != 0)
            return -1;
    }

    for (int i = 0; i < src->cur_size; i++)
        *(des->str + i + des->cur_size) = *(src->str + i);
    des->cur_size += src->cur_size;

    return 0;
}

int string_copy(string_diy *des, string_diy *src)
{
    while (des->max_size < src->cur_size) {
        if (string_enlarge_size(des) != 0)
            return -1;
    }

    for (int i = 0; i < src->cur_size; i++)
        *(des->str + i) = *(src->str + i);

    return 0;
}

int string_init(string_diy *str, char *src, int size)
{
/*
    str->str = malloc(128 * sizeof(char));
    if (str->str == NULL)
        return -1;

    str->cur_size = 0;
    str->max_size = 128;
*/
    int init_size = ((size / 128) + 1) * 128;
    str->str = malloc(init_size * sizeof(char));

    for (int i = 0; i < size; i++)
        *(str->str + i) = *(src + i);
    str->max_size = init_size;
    str->cur_size = size;

    return 0;
}

int string_del(string_diy str)
{
    free(str.str);

    return 0;
}

int main()
{
    string_diy str_1 = {0};
    string_diy str_2 = {0};
    string_diy str_3 = {0};

    string_init(&str_1, "hello ", 5);
    string_init(&str_2, "world", 5);
    string_init(&str_3, "i am from Mars!", 14);

    printf("%s\n", str_1.str);
    printf("%s\n", str_2.str);
    printf("%s\n", str_3.str);

    string_append(&str_1, &str_2);
    printf("%s\n", str_1.str);

    string_copy(&str_1, &str_3);
    printf("%s\n", str_1.str);

    return 0;
}

#else

#include <stdio.h>
#include <stdlib.h>

int str_expand()
{

}

int str_cpy()
{

}

int main()
{

    return 0;
}

#endif
