#include <filesystem>
#include <iomanip>
#include <iostream>

int main(int argc, char ** argv)
{
	system("chcp 1251");

	std::filesystem::path file = "./Source.cpp"; //он относительный

	if (!std::filesystem::exists(file)) //провсерка на существование (он проверяет по конкретному пути)
	{
		std::cerr << "Path " << file << " does not exist.\n";

		return EXIT_FAILURE;
	}
	else
	{
		std::cout << "Path " << file.string() << " exists." << std::endl;
	}

	std::cout << std::filesystem::canonical(file).string() << std::endl;

	std::filesystem::path path = "directory/../directory/file.txt";

	std::cout <<
		std::filesystem::current_path().string() << std::endl <<
		std::filesystem::absolute(path).string() << std::endl << // ?
		std::filesystem::canonical(path).string() << std::endl; // weakly canonical

	std::cout << (std::filesystem::path("directory") / "file.txt").string() << std::endl;

	std::cout << std::boolalpha <<
		std::filesystem::equivalent(path, "directory/../directory/file.txt") << std::endl;

	system("pause");

	return EXIT_SUCCESS;
}