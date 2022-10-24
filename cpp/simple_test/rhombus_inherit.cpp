#include <iostream>

class Animal
{
public:
	size_t m_age = 1;
};

class Horse : virtual public Animal
{
public:
	Horse()
	{
		m_age = 11;
	}
};

class Donkey : virtual public Animal
{
public:
	Donkey()
	{
		m_age = 111;
	}
};

class Mule : virtual public Horse, virtual public Donkey
{
public:
	Mule()
	{
		// m_age = 1111;
	}
};

void test_1()
{
	Mule m;
	// std::cout << "Mule age : " << m.Animal::m_age << std::endl; // not allowed
	std::cout << "Horse age : " << m.Horse::m_age << std::endl;
	std::cout << "Donkey age : " << m.Donkey::m_age << std::endl;
	std::cout << "Mule age : " << m.m_age << std::endl;

	return;
}

int main()
{
	test_1();

	return 0;
}