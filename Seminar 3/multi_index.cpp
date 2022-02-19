#include <iostream>
#include <string>

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/hashed_index.hpp> //интерфейсы контейнеров
#include <boost/multi_index/ordered_index.hpp>// то же
#include <boost/multi_index/random_access_index.hpp> //то же

using namespace boost::multi_index;

struct Animal
{
	std::string name;
	std::size_t legs;
};

using animals_multi_index = multi_index_container <
	Animal, indexed_by < //список интерфейсов, через который мы будем использовать
		hashed_non_unique < //анордеред мульти сет
			member < Animal, std::string, &Animal::name > > , //хэш по имени
		hashed_non_unique <//то же
			member < Animal, std::size_t, &Animal::legs	> > , //хэш по числу ног
		random_access <> ,// вектор без параметров
		ordered_non_unique <// упорядоченный сет
			member < Animal, std::size_t, &Animal::legs > > > > ; //хэш по ногам//тип используемого контейнера

int main(int argc, char ** argv)
{
	animals_multi_index animals;

	animals.insert({ "cat",    4 });
	animals.insert({ "dog",    4 });
	animals.insert({ "shark",  0 });
	animals.insert({ "spider", 8 });

	auto & hashed_legs_index = animals.get < 1 > (); //запросили первый интерфейс. Он выполняет хэширование по колву ног
	std::cout << hashed_legs_index.count(4) << std::endl;

	auto iterator = hashed_legs_index.find(0);
	hashed_legs_index.modify(iterator, [](Animal & animal) { animal.name = "whale"; }); //с помощью модифай изменили ключ=модифай потому что несколько интерфейсов (чтобы происходила перестройка)

	std::cout << hashed_legs_index.find(0)->name << std::endl;

	std::cout << std::endl;

	const auto & ordered_legs_index = animals.get < 3 > (); //мульти сет

	auto begin = ordered_legs_index.lower_bound(4); //индекс здесь интерфейс
	auto end   = ordered_legs_index.upper_bound(4); //снова ищем 4хногих

	for (; begin != end; ++begin)
	{
		std::cout << begin->name << std::endl;
	}

	std::cout << std::endl;

	const auto & random_access_index = animals.get < 2 > (); //вектор (итератор в векторе random_access

	std::cout << random_access_index[0].name << std::endl;

	system("pause");

	return EXIT_SUCCESS;
}