#include <iostream>
#include <fstream>

class Dog
{
public:
	size_t m_age;
	char m_name[64];
};

void readFile_1(std::ifstream &ifs)
{
	char buff[1024] = {0};
	while (ifs >> buff)
	{
		std::cout << buff << std::endl;
	}

	return;
}

void readFile_2(std::ifstream &ifs)
{
	char buff[1024] = {0};
	while (ifs.getline(buff, 1024))
	{
		std::cout << buff << std::endl;
	}

	return;
}

void readFile_3(std::ifstream &ifs)
{
	std::string buff;
	while (getline(ifs, buff))
	{
		std::cout << buff << std::endl;
	}

	return;
}

void readFile_4(std::ifstream &ifs)
{
	char c;
	while ((c = ifs.get()) != EOF)
	{
		std::cout << c;
	}

	return;
}

void test_1()
{
	std::ofstream ofs;
	ofs.open("data.txt", std::ios::out | std::ios::app);
	if (ofs.is_open() == false)
	{
		std::cout << "open file failed!\n";
		return;
	}

	ofs << __DATE__ << " " << __TIME__ << " test..." << std::endl;

	ofs.close();

	return;
}

void test_11()
{
	std::ifstream ifs;
	ifs.open("data.txt", std::ios::in);
	if (ifs.is_open() == false)
	{
		std::cout << "open file failed!\n";
		return;
	}

	// readFile_1(ifs);
	// readFile_2(ifs);
	// readFile_3(ifs);
	readFile_4(ifs);

	ifs.close();

	return;
}

void test_2()
{
	Dog dog = {22, "naughty"};

	std::ofstream ofs;
	ofs.open("dog.txt", std::ios::out | std::ios::app | std::ios::binary);
	if (ofs.is_open() == false)
	{
		std::cout << "open file failed!\n";
		return;
	}

	ofs.write((const char *)&dog, sizeof(dog));

	ofs.close();

	return;
}

void test_22()
{
	std::ifstream ifs;
	ifs.open("dog.txt", std::ios::in | std::ios::binary);
	if (ifs.is_open() == false)
	{
		std::cout << "open file failed!\n";
		return;
	}

	Dog dog;
	while (ifs.read((char *)&dog, sizeof(Dog)))
	{
		std::cout << "name: " << dog.m_name << std::endl;
		std::cout << "age: " << dog.m_age << std::endl;
	}

	ifs.close();

	return;
}

int main()
{
	test_1();
	test_11();

	test_2();
	test_22();

	return 0;
}