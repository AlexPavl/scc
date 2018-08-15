#include <vector>
#include <string>
#include <iostream>
#include <set>

template <class Type>
bool isSetContains(std::set<Type> &Set, 
                    Type &obj)
{
    if (Set.count(obj)) {
        return true;
    }
    else {
        return false;
    }
}

struct Token {
    std::string type;   /* token type  */
    unsigned    id;     /* symbol's table number */
};

struct Symbol_Info {
    std::string name;       /* name of object */
    unsigned    type;
    unsigned    initLine;   /* which line init */
};
/* need full keywords' table */
std::set<std::string> keywords = {
    "auto", "break", "case", "char",
    "const", "continue", "default", "do",
    "double", "else", "enum", "extern",
    "float", "for", "goto", "if",
    "int", "long",	"register",	"return",
    "short", "signed", "sizeof", "static",
    "struct", "switch",	"typedef", "union",
    "unsigned", "void", "volatile", "while"
};
/* small operators' table */
std::set<char> operators = {
    '=', '+', '-', '*', '/', '(', ')', ';', ',', '{', '}'
};

std::vector<Symbol_Info> symbTable;

unsigned lexicAnalyser(std::istream &in)
{
    std::string input = "";
    char inC;
    bool startedWord = false;
    while(!in.eof()) {
        inC = in.get();
        if (isSetContains(operators, inC)) {
            std::cout << "Divider: " << inC << std::endl;
        }        
    }
}

