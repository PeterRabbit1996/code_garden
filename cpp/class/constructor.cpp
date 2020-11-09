#include <iostream>

using namespace std;

// definition of Person
class Person
{
	public:
		Person();
		Person(unsigned short age, unsigned short height, unsigned short weight);
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

int main()
{

	return 0;
}
