#include <iostream>
#include <string>

using namespace std;

namespace constructor_study
{
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

	void test1()
	{
		NullPtr *np = nullptr;
		np->showMsg();
		// np->showAge(); // error and np is a nullptr

		return;
	}

	void test2()
	{
		T t;
		cout << "sizeof (T) = " << sizeof(t) << endl;

		return;
	}

	void test3()
	{
		Box b(1, 2, 3);
		b.display();

		return;
	}

	void test4()
	{
		Person p1 = getPer();
		Person p;
		transPer(p);

		return;
	}

	void test5()
	{
		Worker worker("Jay", "Nokia");
		cout << "sizeof (worker) = " << sizeof(worker) << endl;

		return;
	}

	void test6()
	{
		Dog dog1(10);
		Dog dog2(10);
		dog2.addAge(dog1).addAge(dog1).getAge();
		cout << "age = " << dog2.getAge() << endl;

		return;
	}

	void test7()
	{
		Box b1(1, 2, 3);
		Box b2(10, 20, 30);
		Box b3 = b1 + b2;
		b3.display();
		cout << b3;

		return;
	}
} // namespace constructor_study

namespace constructor_test
{
	class CT
	{
	public:
		CT() { std::cout << "CT constructor...\n"; }
		CT(const CT &ct) { std::cout << "CT copy constructor...\n"; }
		CT(CT &&ct)
		noexcept { std::cout << "CT move constructor...\n"; }
		/* not suggested and ct is not allowed to change its member*/
		// CT(const CT &&ct)
		// noexcept { std::cout << "CT move constructor...\n"; }
		CT &operator=(const CT &ct)
		{
			std::cout << "CT copy assignment constructor...\n";
			return *this;
		}
		CT &operator=(CT &&ct) noexcept
		{
			std::cout << "CT move assignment constructor...\n";
			return *this;
		}
		~CT() { std::cout << "CT destructor...\n"; }
	};

	void sendCTObject(CT object)
	{
		return;
	}

	CT createCTObject()
	{
		CT ct;
		return ct;
	}

	CT &createCTObjectRef()
	{
		CT ct;
		return ct;
	}

	void forwardArgs(CT ct)
	{
		CT ct1 = std::forward<CT>(ct);

		return;
	}

	void test1()
	{
		CT ct;
		sendCTObject(ct);

		return;
	}

	void test2()
	{
		CT ct1 = createCTObject();
		CT ct2 = createCTObjectRef();

		return;
	}

	void test3()
	{
		CT ct1;
		CT ct2 = ct1;
		CT ct3(ct1);
		ct3 = ct2;
	}

	void test4()
	{
		CT t1;
		CT t2 = std::move(t1);
		t2 = std::move(t1);
	}

	void test5()
	{
		const CT ct1;
		CT ct2 = std::move(ct1);
	}

	void test6()
	{
		CT ct;
		forwardArgs(ct);
	}

	void test7()
	{
		CT ct = CT();
		ct = CT();
	}

	void test8()
	{
		CT ct = CT();
	}
} // namespace constructor_test

int main()
{
	// constructor_study::test1();
	// constructor_study::test2();
	// constructor_study::test3();
	// constructor_study::test4();
	// constructor_study::test5();
	// constructor_study::test6();
	// constructor_study::test7();

	// constructor_test::test1();
	// constructor_test::test2();
	// constructor_test::test3();
	// constructor_test::test4();
	// constructor_test::test5();
	// constructor_test::test6();
	constructor_test::test7();
	// constructor_test::test8();

	return 0;
}
