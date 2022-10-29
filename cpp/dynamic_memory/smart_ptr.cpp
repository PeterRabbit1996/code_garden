#include <iostream>
#include <memory>

template <typename T1, typename T2>
class TC
{
public:
	TC() = default;
	TC(T1 t1, T2 t2) : t1(t1), t2(t2) {}

	T1 t1;
	T2 t2;
};

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &cout, TC<T1, T2> tc)
{
	std::cout << "t1 = " << tc.t1 << ", t2 = " << tc.t2 << std::endl;

	return cout;
}

namespace sharted_ptr
{
	void test1()
	{
		auto ptr1 = std::make_shared<TC<std::string, int>>("a", 10);
		auto ptr2 = ptr1;
		ptr2->t1 = std::string("b");
		std::cout << *(ptr1.get());
		std::cout << *(ptr2.get());

		return;
	}

	void test2()
	{
		auto p1 = std::make_shared<std::string>("abc");
		std::cout << "p1.count = " << p1.use_count() << std::endl;

		auto p2 = p1;
		std::cout << "p1.count = " << p1.use_count() << std::endl;

		return;
	}

} // namespace sharted_ptr

namespace unique_ptr
{
	void test1()
	{

		return;
	}

} // namespace unique_ptr

namespace allocator
{
	void test1()
	{
		std::allocator<std::string> ac;
		auto const p = ac.allocate(10);

		return;
	}

} // namespace allocator

int main()
{
	sharted_ptr::test1();
	sharted_ptr::test2();

	return 0;
}