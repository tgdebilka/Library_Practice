#include <iostream>
#include "Dynamic_Library.hpp"
#include "Static_Library.hpp"

int main(int argc, char* argv[])
{
    std::cout << StaticLib::romanToInt("XV") << std::endl;
    std::cout << DynamicLib::romanToInt("XVIII") << std::endl;

    return 0;
}
