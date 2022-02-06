#include <iostream>

class Base
{
public:
	static int m_snum;

	int getNum();
	void dp()
	{
		std::cout << "Base func..." << std::endl;
	}
	void dp(int nm)
	{
		std::cout << "Base func..." << std::endl;
	}
	int m_pnum = 10;

protected:
	int m_num = 20;
};
int Base::m_snum = 30;

class Derive : public Base
{
public:
	static int m_snum;

	int getNum()
	{
		std::cout << "Base num is " << Base::m_num << std::endl;
		std::cout << "Derive num is " << m_num << std::endl;

		dp();
		Base::dp();

		return m_num;
	}
	void dp()
	{
		std::cout << "Derive func..." << std::endl;
	}

	int m_pnum = 111;

protected:
	int m_num = 222;
};
int Derive::m_snum = 333;

void test_1()
{
	Derive d;
	d.getNum();
	std::cout << d.Base ::m_pnum << std::endl;
	std::cout << d.m_pnum << std::endl;

	d.dp();
	d.Base::dp();

	return;
}

void test_2()
{
	Derive d;
	std::cout << d.Base::m_snum << std::endl;
	std::cout << d.m_snum << std::endl;

	std::cout << Derive::Base::m_snum << std::endl;
	std::cout << Derive::m_snum << std::endl;

	return;
}

int main()
{
	// test_1();
	test_2();

	return 0;
}
