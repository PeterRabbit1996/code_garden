#include <iostream>

class Base
{
public:
    virtual ~Base() { do_(); }
    virtual void do_()
    {
        std::cout << typeid(this).name() << std::endl;
    }
};

class Derive : public Base
{
public:
    virtual ~Derive() { do_(); }
    void do_() override
    {
        std::cout << typeid(this).name() << std::endl;
    }
};

int main()
{
    Base *b = new Derive();
    delete b;

    return 0;
}