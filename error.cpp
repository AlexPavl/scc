#include "error.hpp"
#include <iostream>

void compError(std::string  text)
{
    std::cerr << text << std::endl;

    exit(1);
}

