#include <iostream>
#include <cstdio>

#define NOT_ALLOW_COPY_AND_ASSIGN(class_name)    \
	class_name(const class_name &) = delete; \
	class_name &operator=(const class_name &) = delete;

class SingleInstance
{
public:
	NOT_ALLOW_COPY_AND_ASSIGN(SingleInstance)
	~SingleInstance()
	{
		std::cout << "destructor called!" << std::endl;
	}

	static SingleInstance &get_instance()
	{
		static SingleInstance instance;
		return instance;
	}

private:
	SingleInstance()
	{
		std::cout << "constructor called!" << std::endl;
	}
};

int main(int argc, char *argv[])
{
	SingleInstance &instance_1 = SingleInstance::get_instance();
	SingleInstance &instance_2 = SingleInstance::get_instance();

	return 0;
}