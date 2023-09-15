#include <filesystem>
#include <iostream>

void listFilesAndDirsRecursive(const std::filesystem::path &path)
{
	for (const auto &entry : std::filesystem::directory_iterator(path))
	{
		std::cout << entry.path() << std::endl;
		if (std::filesystem::is_directory(entry))
		{
			listFilesAndDirsRecursive(entry.path());
		}
	}
}

int main()
{
	std::filesystem::path path = ".";
	listFilesAndDirsRecursive(path);
	return 0;
}