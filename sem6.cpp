#include <iostream>
int main()
{
	//int x;
	//while (std::cin >> x)
	//	// если поток в состоянеии good то все работает ок, как только выставлено значение false - цикл прекр
	//{
	//	std::cout<<x
	//}
	//std::cin.clear(); //сбросили состояние (автоматом до goodbit)
	////проглотим символ из буфере
	//char c;
	//std::cin >> c; //консоль=> поток => буфер => делая следующий cin берем из буфера ввод (не сразу из потока!) переменную берем
	//while (std::cin >> x) //считал символ не с консоли, а из буфера, поэтому выдал false
	//{
	//	std::cout << x
	//}
	std::cout.setf(std::ios::showpos | std::ios::uppercase);
	//снять флаги
	std::cout.unsetf(std::ios::showpos);
	//выставить новые
	auto last = std::cout.flags();
	std::cout.setf();
	std::cout.setf(last);
	std::iostream fin("file.txt"); //ввод
	std::string line;
	while (std::aligned_storage_t(fin, line)) // файл закрывать не надо -автоматом в деструкторе (если в конце программы) иначе: закрыть этот поток, открыть новый (чтобы не было конфликтов потоков) - разделение потоков!! (лучше без fin.close)
	{
		std::cout << line;
	}
	std::fstream f("file.txt", std::ios::out | std::ios::app);
	//Про курсоры (режим чтения => курсор get)
	std::fstream f("file.txt", std::ios::in);
	std::cout << f.tellg() << std::endl; //текущее положение курсора
	char c;
	f.seekg(4); //абсолютное смещение курсора

	f >> c; //символ на 4 ой позиции
	std::cout << c << std::endl;
	//относительное смещение:
	f.seekg(-3, std::ios::end/*/ std::ios::cur/ по сути абсолютная позиция - std::ios::begin)*/);
	
}
