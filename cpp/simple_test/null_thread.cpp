#include <iostream>
#include <chrono>
#include <thread>

class Dog
{
public:
	Dog(std::string name, uint8_t age) : name_(name), age_(age) {}
	void bark(const std::string words)
	{
		std::cout << name_ << "said: " << words << std::endl;
		return;
	}

private:
	std::string name_;
	uint8_t age_;
};

int main()
{
	using namespace std::chrono_literals;

	Dog *dog = new Dog("tike", 3);
	std::thread thread([&] {
		while (true)
		{
			dog->bark("fuck!!!");
			std::this_thread::sleep_for(1s);
		}
		
	});

	std::this_thread::sleep_for(4s);
	delete dog;

	while (true)
	{
	}

	return 0;
}
