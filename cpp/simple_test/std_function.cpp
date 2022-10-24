#include <iostream>

template <typename T>
class TC
{
    using callback = std::function<T(T)>;

public:
    static T div(T a, T b)
    {
        return a / b;
    }

    T get(callback &&cb, T t)
    {
        cb(t);
        return t;
    }

    T operator()(T a, T b)
    {
        return a + b;
    }
};

template <typename T>
struct MOD
{
    int operator()(int a, int b)
    {
        return a % b;
    }
};

int func1(int val)
{
    return val;
}

template <typename T>
T func2(T t)
{
    return t;
}

void test1()
{
    std::function<int(int)> callback = nullptr;

    callback = func1;
    std::cout << "val = " + std::to_string(callback(100)) << std::endl;

    return;
}

void test2()
{
    int (*fun_ptr)(int) = func1;
    std::function<int(int)> callback = fun_ptr;
    std::cout << "val = " + std::to_string(callback(110)) << std::endl;
    return;
}

void test3()
{
    std::function<int(int)> callback = func2<float>;
    std::cout << "val = " + std::to_string(callback(99)) << std::endl;
    return;
}

void test4()
{
    TC<int> tc;
    int val = 12;
    tc.get([=](int) -> int
           { std::cout << "callback val = " + std::to_string(val) << std::endl; return val; },
           val);
}

void test5()
{
    struct PLUS
    {
        int operator()(int a, int b)
        {
            return a + b;
        }
    };

    std::function<int(int, int)> cb = PLUS();

    int a = 2;
    int b = 4;
    printf("sum %d and %d is %d\n", a, b, cb(a, b));

    return;
}

void test6()
{
    auto func = [](int a, int b)
    { return a * b; };
    std::function<int(int, int)> cb = func;

    int a = 3;
    int b = 8;
    printf("multiplies %d and %d is %d\n", a, b, cb(a, b));
}

void test7()
{
    std::function<int(int, int)> cb = MOD<int>();

    int a = 10;
    int b = 6;
    printf("mod %d and %d is %d\n", a, b, cb(a, b));

    return;
}

void test8() {
    std::function<float(float, float)> cb = TC<float>::div;

    float a = 10;
    float b = 6;
    printf("div %f and %f is %f\n", a, b, cb(a, b));

    return;
}

void test9() {
    std::function<int(int)> cb1 = func1;
    std::function<int(int)> &&cb2 = std::move(cb1);
    std::function<int(int)> cb3(cb2);

    printf("cb1 %d\n", cb1(10));
    printf("cb2 %d\n", cb1(11));
    printf("cb3 %d\n", cb1(12));

    return;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    std::plus<int>()(2, 5);

    return 0;
}