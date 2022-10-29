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

int main()
{
	class_template::test1();

	return 0;
}
