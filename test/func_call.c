#include <stdio.h>
#include <string.h>

struct C
{
    int a;
    int b;
    int c;
};

int test2(int x, int y, int z)
{
    printf("hello,test2\n");
    return 0;
}

int test(int x, int y, int z)
{
    int a = 1;
    int b = 2;
    int c = 3;
    struct C st;
    printf("addr x = %u\n",(unsigned int)(&x));
    printf("addr y = %u\n",(unsigned int)(&y));
    printf("addr z = %u\n",(unsigned int)(&z));
    printf("addr a = %u\n",(unsigned int)(&a));
    printf("addr b = %u\n",(unsigned int)(&b));
    printf("addr c = %u\n",(unsigned int)(&c));
    printf("addr st = %u\n",(unsigned int)(&st));
    printf("addr st.a = %u\n",(unsigned int)(&st.a));
    printf("addr st.b = %u\n",(unsigned int)(&st.b));
    printf("addr st.c = %u\n",(unsigned int)(&st.c));
    return 0;
}

int main(int argc, char** argv)
{
    int x = 1;
    int y = 2;
    int z = 3;
    test(x,y,z);
    printf("x = %d; y = %d; z = %d;\n", x,y,z);
    memset(&y, 0, 4);
    printf("x = %d; y = %d; z = %d;\n", x,y,z);
    return 0;
}
