#include <iostream>
#include <iterator>

int main(int argc, char ** argv)
{
	std::istreambuf_iterator < char > istreambuf_iterator(std::cin); //процесс создания итераторов
	//оабота посимвольного ввода вывода 
	std::istreambuf_iterator < char > end;

	std::ostreambuf_iterator < char > ostreambuf_iterator(std::cout);

	while (istreambuf_iterator != end) 
	{
		*ostreambuf_iterator = *istreambuf_iterator;//копирование
		++istreambuf_iterator;//инкримент итератора 
		++ostreambuf_iterator;
	}

	system("pause");

	return EXIT_SUCCESS;
}
