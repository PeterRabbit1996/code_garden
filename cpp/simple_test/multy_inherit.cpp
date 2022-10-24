#include <iostream>

class Base1
{
public:
	int m_base = 111;
	int m_num = 11;
};

class Base2
{
public:
	int m_base = 222;
	int m_num = 22;
};

class Derive : public Base1, public Base2
{
public:
	int m_derive = 333;
	int m_num = 33;
};

void test_1()
{
	Derive d;
	std::cout << "Base1 : " << d.Base1::m_num << std::endl;
	std::cout << "Base2 : " << d.Base2::m_num << std::endl;
	std::cout << "Derive : " << d.m_num << std::endl;

	return;
}

void test_2()
{
	Derive d;
	std::cout << "Base1 : " << d.Base1::m_base << std::endl;
	std::cout << "Base2 : " << d.Base2::m_base << std::endl;
	std::cout << "Derive : " << d.m_derive << std::endl;

	return;
}

int main()
{
	test_1();
	test_2();

	return 0;
}

