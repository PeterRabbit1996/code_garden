#include <iostream>

class StaVar
{
public:
	StaVar()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		int *data = NULL;
		*data = 10;
	}
};

static StaVar sta_var;

int main()
{
	std::cout << "hello" << std::endl;

	return 0;
}