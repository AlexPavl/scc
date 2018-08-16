#include <iostream>
#include <fstream>
#include "error.hpp"
#include "lexAnalyser.hpp"


int main(int argc, char **argv)
{
    if (argc > 1) {
        std::ifstream input(argv[1]);
        lexicAnalyser(input);
    }
    else {
        compError("Please enter filename");
    }

    return 0;
}