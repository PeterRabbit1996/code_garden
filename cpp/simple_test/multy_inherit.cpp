#include <iostream>

namespace multy_inherit
{
	class Base1
	{
	public:
		void display() { std::cout << typeid(*this).name() << std::endl; };
		int m_base = 111;
		int m_num = 11;
	};

	class Base2
	{
	public:
		void display() { std::cout << typeid(*this).name() << std::endl; };
		int m_base = 222;
		int m_num = 22;
	};

	class Derive : public Base1, public Base2
	{
	public:
		void display() { std::cout << typeid(*this).name() << std::endl; };
		int m_derive = 333;
		int m_num = 33;
	};

	void test_1()
	{
		Derive d;
		d.display();
		d.Base1::display();
		d.Base2::display();

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

	class B
	{
	public:
		void echo() { std::cout << typeid(*this).name() << std::endl; }
	};

	class D1 : public virtual B
	{
	};

	class D2 : public virtual B
	{
	};

	class C : public D1, public D2
	{
	};

	void test3()
	{
		std::cout << "sizeof B = " << sizeof(B) << std::endl;
		std::cout << "sizeof D1 = " << sizeof(D1) << std::endl;
		std::cout << "sizeof D2 = " << sizeof(D2) << std::endl;
		std::cout << "sizeof C = " << sizeof(C) << std::endl;
	}

	void test4()
	{
		C c;
		c.echo();

		return;
	}

} // namespace multy_inherit

int main()
{
	multy_inherit::test_1();
	multy_inherit::test_2();
	multy_inherit::test3();
	multy_inherit::test4();

	return 0;
}
