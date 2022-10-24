#include <iostream>

void test1()
{
    std::string str1 = "hello";
    std::string str2 = std::move(str1);

    printf("str1 = %s\n", str1.c_str());
    printf("str2 = %s\n", str2.c_str());

    return;
}

void test2()
{
    std::string str1 = "hello";
    std::string &&str2 = std::move(str1);
    str2.append("abc");

    printf("str1 = %s\n", str1.c_str());
    printf("str2 = %s\n", str2.c_str());

    
    return;
}

int main()
{
    test1();
    test2();

    return 0;
}