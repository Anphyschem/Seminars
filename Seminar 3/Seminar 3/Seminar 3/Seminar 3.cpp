
#include <iostream>
#include <map>

int main()
{
    std::map<std::string, int> m;
    m["abc"] = 43; //скобочки noexcept через оператор
    m.insert(std::make_pair("xyz", 34)); //через функцию член insert
    try
    {
        std::cout<< m["a"] /*(m.at("a")*/<< std::endl; //несуществующий элемент
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    for (auto [key, value] : m)
    {
        std::cout << key << ' ' << value << std::endl;
    }
    system("pause");
}
