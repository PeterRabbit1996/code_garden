#include <iostream>
#include <vector>

typedef struct
{
	std::string name;
	std::wstring wname;
	uint8_t age;
} Person;

class StructClass
{
public:
	int init()
	{
		for (int i = 0; i < 4; i++)
		{
			Person *person = (Person *)malloc(sizeof(Person));
			person->name.resize(64);
			person->name = std::string("abc");

			std::cout << "name is " << person->name << std::endl;

			person_list.emplace_back(person);
		}
		return 0;
	}

private:
	std::vector<Person *> person_list;
};

int main()
{
	StructClass struct_class;
	struct_class.init();

	return 0;
}