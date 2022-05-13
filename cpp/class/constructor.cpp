#include <iostream>
#include <string>

using namespace std;

// definition of Person
class Person
{
public:
	Person();
	Person(unsigned short age, unsigned short height, unsigned short weight);
	Person(const Person &p); // copy constructor
	Person(Person &&p);	 // move constructor
	~Person();

protected:
	unsigned short age;
	unsigned short height; // cm
	unsigned short weight; // kg
};

Person::Person()
{
	age = 0;
	height = 0;
	weight = 0;

	cout << "Person creates." << endl;
}

Person::Person(unsigned short age, unsigned short height, unsigned short weight) : age(age), height(height), weight(weight)
{
	cout << "Person creates." << endl;
}

Person::Person(const Person &p)
{
	cout << "copy construction..." << endl;
	this->age = p.age;
	this->height = p.height;
	this->weight = p.weight;
}

Person::Person(Person &&p)
{
	cout << "move construction..." << endl;
	this->age = p.age;
	this->height = p.height;
	this->weight = p.weight;
}

Person::~Person()
{
	cout << "Person destroy." << endl;
}

Person getPer()
{
	Person p1;
	return p1;
}

void transPer(Person p)
{
	return;
}

class Box
{
public:
	Box(int a, int b, int c) : m_a(a), m_b(b), m_c(c)
	{
	}

	Box operator+(Box box)
	{
		this->m_a += box.m_a;
		this->m_b += box.m_b;
		this->m_c += box.m_c;
		return *this;
	}

	void display()
	{
		cout << "a = " << m_a << endl;
		cout << "b = " << m_b << endl;
		cout << "c = " << m_c << endl;
		return;
	}

public:
	int m_a;
	int m_b;
	int m_c;
};

class Phone
{
public:
	Phone(std::string brand)
	{
		m_brand = brand;
		cout << "phone " << m_brand << " create...\n";
	}
	~Phone()
	{
		cout << "phone " << m_brand << " destroy...\n";
	}

private:
	std::string m_brand;
};

class Worker
{
public:
	Worker(std::string name, std::string phoneBrand)
	{
		cout << "worker create...\n";
		m_name = name;
		m_phone = Phone(phoneBrand);
	}
	~Worker()
	{
		cout << "worker " << m_name << " destroy...\n";
	}

private:
	std::string m_name;
	Phone m_phone = Phone("default");
	Phone m_phone1 = Phone("phone1");
};

class T
{
	int m_a;
	char m_c;
	char m_d;
};

class Dog
{
public:
	Dog(int age)
	{
		this->age = age;
	}

	Dog(const Dog &dog)
	{
		this->age = dog.age;
	}

	Dog addAge(Dog &dog)
	{
		this->age += dog.age;
		return *this;
	}

	int getAge()
	{
		return age;
	}

private:
	int age;
};

class NullPtr
{
public:
	void showMsg()
	{
		cout << "just a msg test\n";
	}
	void showAge()
	{
		cout << "age = " << m_age << endl;
	}

private:
	int m_age;
};

void operator<<(ostream &cout, Box box)
{
	cout << "m_a = " << box.m_a << ", m_b = " << box.m_b << ", m_c = " << box.m_c << endl;
	return;
}

int main()
{
	// NullPtr *np = nullptr;
	// np->showMsg();
	// np->showAge();
	// T t;
	// cout << "sizeof (T) = " << sizeof(t) << endl;
	// Box b(1, 2, 3);
	// b.display();

	// Person p1 = getPer();
	// Person p;
	// transPer(p);

	// Worker worker("Jay", "Nokia");
	// cout << "sizeof (worker) = " << sizeof(worker) << endl;

	Dog dog1(10);
	Dog dog2(10);
	dog2.addAge(dog1).addAge(dog1).getAge();
	cout << "age = " << dog2.getAge() << endl;

	int a = 10;
	int b = 122;
	cout << "a = " << a << ", b = " << b << endl;
	strcpy((char *)(&a), (char *)(&b));
	cout << "a = " << a << ", b = " << b << endl;

	Box b1(1, 2, 3);
	Box b2(10, 20, 30);
	Box b3 = b1 + b2;
	b3.display();
	cout << b3;

	return 0;
}
