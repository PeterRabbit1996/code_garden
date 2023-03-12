#include <iostream>

namespace class_template
{
	template <typename T>
	class TC
	{
	public:
		void display(T t);
	};

	template <typename T>
	void TC<T>::display(T t)
	{
		std::cout << "t = " << t << std::endl;
	}

	void test1()
	{
		TC<int> tc;
		tc.display(100);

		return;
	}

} // namespace class_template

namespace multy_args_template
{
	template <typename Func, typename... Args>
	void disMsg(const Func &&func, Args... args)
	{
		// func(std::forward<Args>(args) + std::forward<Args>(args)...);
		func(std::forward<Args>(args)...);
		return;
	}

	void test1()
	{
		disMsg([](int a, int b)
		       { std::cout << "a = " << a << std::endl;
		       std::cout << "b = " << b << std::endl; },
		       3, 5);
	}
} // namespace multy_args_template

int main()
{
	class_template::test1();
	multy_args_template::test1();

	return 0;
}
