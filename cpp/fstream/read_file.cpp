#include <iostream>
#include <fstream>
#include <string>

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

int main()
{
	test_1();

	return 0;
}