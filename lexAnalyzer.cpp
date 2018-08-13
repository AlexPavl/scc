#include <vector>
#include <string>
#include <iostream>

struct Token {
    std::string type;   /* token type  */
    unsigned    id;     /* symbol's table number */
};

struct Symbol_Info {
    std::string name;       /* name of object */
    unsigned    type;
    unsigned    initLine;   /* which line init */
};

std::vector<Symbol_Info> symbTable;

unsigned lexicAnalyzer(std::istream *in)
{
    
}

