#include <iostream>

struct IsCustomUnsignedInt
{
    enum
    {
        value1 = 1,
        value2 = 2
    };
    enum
    {
        value3 = 3
    };
    static const int value4 = 4;
    static int value5;
};

int IsCustomUnsignedInt::value5 = 5;

int main()
{
    int result1 = IsCustomUnsignedInt::value1;
    int result2 = IsCustomUnsignedInt::value2;
    std::cout << "result1 = " + std::to_string(result1) << std::endl;
    std::cout << "result2 = " + std::to_string(result2) << std::endl;
    // IsCustomUnsignedInt::value3 = 3; // error: expression is not assignable
    IsCustomUnsignedInt::value5 = 5;

    return 0;
}