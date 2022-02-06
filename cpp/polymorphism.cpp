#include <iostream>
#include <string>

/* class Animal */
class Animal
{
public:
	Animal()
	{
		std::cout << "Animal create..." << std::endl;
	}
	virtual ~Animal() = 0;

	virtual void speak() = 0;

protected:
	std::string *m_name = nullptr;
};

Animal::~Animal()
{
	std::cout << "Animal destroy..." << std::endl;
	if (m_name != nullptr)
	{
		delete m_name;
		m_name = nullptr;
	}
}

/* Dog Animal */
class Dog : public Animal
{
public:
	Dog()
	{
		std::cout << "Dog create..." << std::endl;
	}
	Dog(std::string name)
	{
		m_name = new std::string(name);
	}
	~Dog()
	{
		std::cout << "Dog destroy..." << std::endl;
		if (m_name != nullptr)
		{
			delete m_name;
			m_name = nullptr;
		}
	}

	void speak()
	{
		if (m_name != nullptr)
		{
			std::cout << "Dog " << *m_name << " speak..." << std::endl;
			return;
		}
		std::cout << "Dog speak..." << std::endl;
		return;
	}
};

/* BorderCollie Animal */
class BorderCollie : public Dog
{
public:
	BorderCollie()
	{
		std::cout << "BorderCollie create..." << std::endl;
	}
	BorderCollie(std::string name)
	{
		m_name = new std::string(name);
	}
	~BorderCollie()
	{
		std::cout << "BorderCollie destroy..." << std::endl;
		if (m_name != nullptr)
		{
			delete m_name;
			m_name = nullptr;
		}
	}

	void speak()
	{
		if (m_name != nullptr)
		{
			std::cout << "BorderCollie " << *m_name << " speak..." << std::endl;
			return;
		}
		std::cout << "BorderCollie speak..." << std::endl;
		return;
	}
};

void doSpeak(Animal &animal)
{
	animal.speak();
	return;
}

void test_1()
{
	BorderCollie borderCollie;
	doSpeak(borderCollie);
	return;
}

void test_2()
{
	std::cout << "sizeof(Animal) : " << sizeof(Animal) << std::endl;
	std::cout << "sizeof(Dog) : " << sizeof(Dog) << std::endl;
	std::cout << "sizeof(BorderCollie) : " << sizeof(BorderCollie) << std::endl;

	return;
}

void test_3()
{
	Animal *animal = new BorderCollie("pipi");
	animal->speak();
	delete animal;
	animal = nullptr;

	return;
}

int main()
{
	// test_1();
	// test_2();
	test_3();

	return 0;
}