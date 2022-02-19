// Sem 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <tuple>
#include <boost/circular_buffer.hpp> //циклический буфер


int main()
{

    std::tuple<int, double> t(42, 1.23);
    auto t = std::make_tuple(42, 1.23); // 2 variation of creation tuple
    std::cout << std::get<0>(t) << std::endl;
    //распаковка кортежа
    int i;
    double d;
    std::tie(i, d) = t;

    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
