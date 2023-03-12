#include <iostream>

namespace data_member
{
	typedef int length;
	class Point3D
	{
		typedef float length;

	public:
		void display(length l) { std::cout << "length = " << l << std::endl; }

	private:
		// typedef float length; // not work
	};

	class TC
	{
	public:
		int a;

	public:
		int b;

	private:
		int c;

	public:
		int d;
	};

	template <typename class_type, typename data_type1, typename data_type2>
	const char *access_order(data_type1 class_type::*mem1, data_type2 class_type::*mem2)
	{
		assert(mem1 != mem2);
		std::cout << "mem1: " << &mem1 << std::endl;
		std::cout << "mem2: " << &mem2 << std::endl;
		// return mem1 < mem2 ? "member 1 access occurs first" : "member 2 access occurs first";
		return nullptr;
	}

	void test1()
	{
		Point3D p;
		p.display(12.33);
		return;
	}

	void test2()
	{
		std::cout << access_order(&TC::a, &TC::b) << std::endl;

		return;
	}

} // namespace data_member

int main()
{
	data_member::test1();
	data_member::test2();

	return 0;
}
