#include <iostream>
#include <new>

namespace new_delete
{
	void test1()
	{
		try
		{
			int *p1 = new int;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}

		int *p2 = new (std::nothrow) int;
		if (!p2)
		{
			std::cout << "new memory failed..." << std::endl;
		}

		return;
	}

} // namespace new_delete

int main()
{
	new_delete::test1();

	return 0;
}
